 #include<iostream>
 using namespace std;
 //display all elements of array
 void display(int size,int *arr){


    for(int *ptr1=arr;ptr1<arr+size;ptr1++){

        cout<<*ptr1<<"\t";
       
    }
    cout<<endl;
 }

 //checking if the sum of elements of array==number entered

    void Sum(int num, int size, int *arr) {
    int sum = 0; // Initialize sum to 0
    int *ptr = nullptr; // Initialize the pointer to nullptr

    for (ptr = arr; ptr < arr + size; ptr++) {
        sum += *ptr; // Add the value pointed to by ptr to sum
    }

    if (sum == num) {
        cout << "The sum of the array is equal to the number you entered, i.e., " << sum << endl;
    } else {
        cout << "Sum of array is not equal to the number entered: " << num << endl;
    }
}

//swapping pointer elements with subsequent odd numbers

void Swap(int size,int *arr){

        cout << "BEFORE SWAPPING" << endl;
     
            display(size, arr);
        
        cout<<"AFTER SWAPPING"<<endl;


           int *ptr1 = arr;
           int *ptr2 = arr + 1;

    for (; ptr2 < arr + size; ptr1 += 2, ptr2 += 2) {
        *ptr1 = *ptr1 + *ptr2;
        *ptr2 = *ptr1 - *ptr2;
        *ptr1 = *ptr1 - *ptr2;
    
    
    
    }
     display(size, arr);
}

 int main(){
    int size,choice;
    cout<<"1.Display all elements"<<endl<<"2.Sum of all elements in array"<<endl<<"3.swap even and odd positions"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    
     while(1){
          cout<<"Enter the size of array (should be even)"<<endl;
          cin>>size;
         //condition to check if size is even
        if(size%2!=0)
        cout<<"Enter the size again"<<endl;
        else
         break;}
        int arr[size];
          cout<<"Enter the elements of array"<<endl;
          for(int i=0;i<size;i++){
          cin>>arr[i];
         }
          
     switch (choice){
        
        //display elements of array
        case 1:
        
          void (*funDisplay)(int,int *);
          funDisplay=&display;
          funDisplay(size,arr);
          break;

        case 2:
        int num;
        cout<<"Enter a number"<<endl;
        cin>>num;
         void (*funSum)(int,int,int *);
          funSum=&Sum;
          funSum(num,size,arr);
         break;

         case 3:

         void (*funSwap)(int,int*);
         funSwap=&Swap;
         funSwap(size,arr);
         break;
     }  

    

          
 }
