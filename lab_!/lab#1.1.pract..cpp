#include<iostream>
using namespace std;

int main(){
    int age=19;
    int *ptr=&age;
    int **ptr1=&ptr;

    cout<<"&ptr"<<&ptr<<endl;;
    cout<<"ptr"<<ptr<<endl;
    cout<<"&ptr1"<<&ptr1<<endl;
    cout<<"*ptr"<<*ptr<<endl;
    cout<<"*ptr1"<<*ptr1<<endl;
    cout<<"**ptr1"<<**ptr1<<endl;
}