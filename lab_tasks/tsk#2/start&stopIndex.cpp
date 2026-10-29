#include<iostream>
#include<cstring>

using namespace std;


char* String_between_indexes(char *string,int start_index,int stop_index)
{
      int length = strlen(string);

      if(start_index<0 || stop_index>=length || start_index>stop_index){
        cout<<"Invalid indices "<<endl;

        return 0;
      }

         int substringLength = stop_index - start_index + 1;

    
        char* result = new char[substringLength + 1];

        strncpy(result,string+start_index,substringLength);
        return result;

}

int main(){
    
    int max_length=100;
    char string[max_length];

    cout<<"enter a string"<<endl;
    cin.getline(string,max_length);

    int start_index,stop_index;

    cout<<"Enter start index: ";
    cin>>start_index;

    cout<<"Enter stop index: ";
    cin>>stop_index;

    char *result=String_between_indexes(string,start_index,stop_index);

      if (result != nullptr) {
        
        cout<<"Result: "<<result<<endl;

        
        delete[] result;
    }
}