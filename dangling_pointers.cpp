#include<iostream>
using namespace std;

int main(){
    int *ptr1=new int;
    int *ptr2=new int;

    *ptr2=44;
    *ptr1=*ptr2;

    ptr1=ptr2;

    delete ptr2;

}