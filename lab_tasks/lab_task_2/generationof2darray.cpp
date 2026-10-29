//create an array of pointers which stores the address of the 0 index of the respective int arrays (generation of 2d array)
#include <iostream>
using namespace std;
int main(){
    int n=4, m=4;
    int **arr=new int *[m]; //**arr=double dynamic pointer, *=single dynamic array


    for(int i=0; i<m; i++){
        arr[i]=new int[n]; 
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=j+1; //column-wise number is same so we write column i-e: j
            cout<<arr[i][j]<<" ";
        } cout<<endl;
    } for(int i=0; i<m; i++){
        delete[] arr[i];//first we delete the array of dynamic int type, i-e: n
}
delete[] arr; //then we delete the array of dynamic pointer type, i-e: m
}