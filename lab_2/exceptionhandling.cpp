#include <iostream>
using namespace std;
int main(){
    int a=20;
    int *ptr; //pointer initialization
    ptr =new (nothrow) int; //dynamic memory request, nothrow=prevents the heap from crashing and null will be stored in the pointer 
    if(!ptr){
        cout<<"memory allocation filled"<<endl;
    } else {
    *ptr=100; //stroing value in dynamic new 
    }
    delete ptr;
    cout<<"hello"<<endl;
}