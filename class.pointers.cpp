#include<iostream>
#include<string>
using namespace std;

int main(){
    char ch='y';
   
    string name[10]; // declaring name outside the loop

     cout<<"Enter name"<<endl;
     int i=0;
    do{
        cin>>name[i];
        i++;
        cout<<"Enter another\n";
        cin>>ch;
    } while(ch=='y' && i<10);
     for(int i=0;i<10;i++)
    cout<<name[i];
    return 0; // adding a return statement to the main function
}
