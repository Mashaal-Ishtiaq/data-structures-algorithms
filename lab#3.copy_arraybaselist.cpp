#include<iostream>
using namespace std;

class List{
    public:
      int *arr=new int[5];

      //constructor

      List(){
          for(int i=0;i<5;i++){
          arr[i]=i+1;
    }
      }

      //constructor overloading
      List(List *list){
        for(int i=0;i<5;i++){
        this->arr[0]=list->arr[0]; // at list2 array 0 index store list1 0 index
      }}

      ~List(){
        delete[] arr;
      }
};

int main(){

    List *list=new List(); //default constructor called
    //deep copy
    List *list2=new List(list); //copy constructor called

    cout<<*list->arr;

    delete list;
    
   
}