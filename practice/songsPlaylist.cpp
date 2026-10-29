#include <iostream>
#include <string>

using namespace std;

class Song
{
public:
    string name;
    int fav_lvl;
    Song *next;

    Song(string n, int fav)
    {
        name = n;
        fav_lvl = fav;
        next = nullptr;
    }
};

class P_L_Manger
{
private:
    Song *head;

public:
    P_L_Manger()
    {
        head = nullptr;
    }

    void insert_song()
    {
        string name;
        int fav_lvl;
        cout << "Enter the name of the song: ";
        cin.ignore();
        getline(cin, name);

        cout << "Choose favorite level:\n";
        cout << "1. Top Favorite\n";
        cout << "2. least Favorite\n";
        cout << "3. or somewhere between them\n";
        cout << "Enter your choice: ";
        cin >> fav_lvl;

        if (fav_lvl == 2)
        {
            int change;
            int numSongs = getNumSongs();

            fav_lvl = change;
        }

        Song *newSong = new Song(name, fav_lvl);

        if (!head || fav_lvl == 1)
        {
            newSong->next = head;
            head = newSong;
        }
        else
        {
            Song *current = head;
            while (current->next && current->next->fav_lvl <= fav_lvl)
            {
                current = current->next;
            }
            newSong->next = current->next;
            current->next = newSong;
        }

        cout << "Song added.\n";
        printPlaylist();
    }

    void deleteSong()
    {
        if (!head)
        {
            cout << "Playlist is empty. Nothing to delete.\n";
            return;
        }

        string name;
        cout << "Enter the name of the song you want to delete: ";
        cin.ignore();
        getline(cin, name);

        Song *current = head;
        Song *prev = nullptr;

        while (current && current->name != name)
        {
            prev = current;
            current = current->next;
        }

        if (!current)
        {
            cout << "Song not found in the playlist.\n";
            return;
        }

        if (!prev)
        {
            head = current->next;
        }
        else
        {
            prev->next = current->next;
        }

        delete current;
        cout << "Song deleted successfully.\n";
        printPlaylist();
    }

    void searchSong()
    {
        if (!head)
        {
            cout << "Playlist is empty. Nothing to search.\n";
            return;
        }

        string name;
        cout << "Enter the name of the song you want to search for: ";
        cin.ignore();
        getline(cin, name);

        Song *current = head;
        bool found = false;

        while (current)
        {
            if (current->name == name)
            {
                cout << "Song found: " << current->name << " (Favorite Level: ";
                if (current->fav_lvl == 1)
                {
                    cout << "Top Favorite";
                }
                else if (current->fav_lvl == 2)
                {
                    cout << "Custom Favorite";
                }
                else
                {
                    cout << "Least Favorite";
                }
                cout << ")\n";
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "Song not found in the playlist.\n";
        }
    }

    void printPlaylist()
    {
        if (!head)
        {
            cout << "Playlist is empty.\n";
            return;
        }

        cout << "Playlist:\n";
        Song *current = head;
        int songNumber = 1;

        while (current)
        {
            cout << songNumber << ". " << current->name << " (Favorite Level: ";
            if (current->fav_lvl == 1)
            {
                cout << "Top Favorite";
            }
            else if (current->fav_lvl == 2)
            {
                cout << "Custom Favorite";
            }
            else
            {
                cout << "Least Favorite";
            }
            cout << ")\n";
            current = current->next;
            songNumber++;
        }
    }

    void playSong()
    {
        if (!head)
        {
            cout << "Playlist is empty. Nothing to play.\n";
            return;
        }

        cout << "Playing the first song: " << head->name << "\n";
    }

    int getNumSongs()
    {
        int numSongs = 0;
        Song *current = head;

        while (current)
        {
            numSongs++;
            current = current->next;
        }

        return numSongs;
    }

    ~P_L_Manger()
    {
        while (head)
        {
            Song *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    P_L_Manger playlist;
    int choice;
    while (1)
    {
        cout << "\nMenu:\n";
        cout << "1. Add a Song\n";
        cout << "2. Delete a Song\n";
        cout << "3. Search for a Song\n";
        cout << "4. Print Playlist\n";
        cout << "5. Play Song\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playlist.insert_song();
            break;
        case 2:
            playlist.deleteSong();
            break;
        case 3:
            playlist.searchSong();
            break;
        case 4:
            playlist.printPlaylist();
            break;
        case 5:
            playlist.playSong();
            break;
        case 6:
            cout << "Exit the program.\n";
            exit(1);
        default:
            cout << "Invalid value :( \n";
            break;
        }
    }

    return 0;
}
