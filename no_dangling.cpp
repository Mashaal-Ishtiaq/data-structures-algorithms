#include<iostream>
using namespace std;

int main(){
    int *ptr1=new int;
    int *ptr2=new int;

    *ptr2=44;
//*ptr1=*ptr2; to stay away from dangling ptr

    ptr1=ptr2;

   // delete ptr2;

   delete ptr1;
   ptr1=ptr2;

   delete ptr2;

   ptr1=ptr2=NULL;

}