#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Movie
{
public:
    int movieId;
    string title;
    string genre;
    double ratings;
};

class Node
{
public:
    Movie movie;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;
    vector<Movie> movieArray;

public:
    BST()
    {
        root = nullptr;
    }
    Node *create_bst(const Movie &movie)
    {
        Node *newNode = new Node;
        newNode->movie = movie;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void insertMovie(Node *node, const Movie &movie)
    {
        if (movie.movieId < node->movie.movieId)
        {
            if (node->left == nullptr)
            {
                node->left = create_bst(movie);
            }
            else
            {
                insertMovie(node->left, movie);
            }
        }
        else
        {
            if (node->right == nullptr)
            {
                node->right = create_bst(movie);
            }
            else
            {
                insertMovie(node->right, movie);
            }
        }
    }

    Node *removeMovie(Node *node, int movieId)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (movieId < node->movie.movieId)
        {
            node->left = removeMovie(node->left, movieId);
        }
        else if (movieId > node->movie.movieId)
        {
            node->right = removeMovie(node->right, movieId);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *minNode = findMinimum(node->right);
                node->movie = minNode->movie;
                node->right = removeMovie(node->right, minNode->movie.movieId);
            }
        }

        return node;
    }

    Node *findMinimum(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        while (node->left != nullptr)
        {
            node = node->left;
        }

        return node;
    }

    void addMovie(int movieId, const string &title, const string &genre, double ratings)
    {
        Movie movie;
        movie.movieId = movieId;
        movie.title = title;
        movie.genre = genre;
        movie.ratings = ratings;

        if (root == nullptr)
        {
            root = create_bst(movie);
        }
        else
        {
            insertMovie(root, movie);
        }

        movieArray.push_back(movie);
    }

    //     void deleteMoives(const int ID) {

    //         if (movie.movieId==ID) {
    //         delete [] movie;
    //         }
    // }

    void recommendMovies(const string &genre)
    {
        for (const Movie &movie : movieArray)
        {
            if (movie.genre == genre)
            {
                cout << "Title: " << movie.title << ", Ratings: " << movie.ratings << endl;
            }
        }
    }
    void displayMovies()
    {
        for (int i = 0; i < movieArray.size() - 1; i++)
        {
            for (int j = 0; j < movieArray.size() - i - 1; j++)
            {
                if (movieArray[j].ratings < movieArray[j + 1].ratings)
                {
                    swap(movieArray[j], movieArray[j + 1]);
                }
            }
        }

        for (const Movie &movie : movieArray)
        {
            cout << "Title: " << movie.title << ", Ratings: " << movie.ratings << endl;
        }
    }
};

int main()
{
    BST moive;

    moive.addMovie(1, "Movie 1", "Action", 4.5);
    moive.addMovie(2, "Movie 2", "Drama", 3.8);
    moive.addMovie(3, "Movie 3", "Comedy", 4.2);

    moive.displayMovies();

    moive.displayMovies();

    moive.recommendMovies("Action");

    return 0;
}
// delete function nai ban raha :(
