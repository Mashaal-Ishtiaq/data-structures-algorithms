#include<iostream>
using namespace std;

class List{
       public:

       //data members
      int *arr;
      int capacity;  //no of elements that can be stored
      int length;   //no of elements stored
      int *curr=arr;

    
       //constructor
      List(int size){
        arr=new int[size];
        capacity=size;
        length=0;
        curr=NULL;

      }

      //destructor
      ~List(){
         delete[] arr;
      }
//display elements
void display_list(){

    cout<<"The updated list :"<<endl;

    for(int i=0;i<length;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

void start(){
    curr=arr;
}
void tail(){

    curr=arr+length-1;  //name of array represents the base index

}

void back(){
    curr--;
}

void next(){
    curr++;
}


//insert Operation
void Insert(int val,int pos){

    if(length==capacity){
        cout<<"array is full"<<endl;
        return;
    }
    if(pos<1 || pos>length+1){    //as user enters from 1 
        cout<<"Invalid position"<<endl;
        return;
    }
    tail(); //pointer will reach to the tail value

    for(int i=length;i>=pos;i--){

        *(curr+1)=*curr;
        back();
    }
    *(curr+1)=val;
    length++;
     display_list();
}


//Remove operation
void Remove(int pos){

    if(length==0){
        cout<<"array is empty"<<endl;
        return;
    }
    if(pos<1 || pos>length){
        cout<<"Invalid position"<<endl;
        return;
    }
    curr=arr+pos-1;
    for(int i=pos;i<length;i++){
        *(curr)=*(curr+1);
        next();
    }
    length--;
    display_list();
    }

    //clear operation
    void Clear(){

        length=0;
        display_list();  //to check if list is cleared or not
        cout<<"List is cleared"<<endl;
    }


    //get operation

    void Get(int pos){

        if(length==0){
            cout<<"array is empty"<<endl;
            return;
        }
        if(pos<1 || pos>length){
            cout<<"Invalid position"<<endl;
            return;
        }
        curr=arr+pos-1;
        
        cout<<"The value at position "<<pos<<" is "<<*curr<<endl;
    }

    //update operation

    void Update(int val,int pos){

        if(length==0){
            cout<<"array is empty"<<endl;
            return;
        }
        if(pos<1 || pos>length){
            cout<<"Invalid position"<<endl;
            return;
        }
        curr=arr+pos-1;
        *curr=val;
        display_list();
    }

    //find operation

    void Find(int val){
        if(length==0){
            cout<<"array is empty"<<endl;
            return;
        }
        start();
        for(int i=1;i<length;i++){
            if(*curr==val){
                cout<<"Value found at position "<<i<<endl;
                return;
            }
            next();
        }
        cout<<"Value not found"<<endl;
    }

  
    // Copy the contents of another list
    void Copy(const List& original, const List& other) {
        if (&original == &other) {
            cout << "Attempting to copy itself. No operation performed." << endl;
            return;
        }
        if (other.length > capacity) {
            cout << "Insufficient capacity to copy the list." << endl;
            return;
        }

        cout << "the list:" << endl;
        original.display_list(); 

        length = other.length;
        for (int i = 0; i < length; i++) {
            other.arr[i]= arr[i] ;
        }

        cout << "Copied list:" << endl;
        display_list(); 
    }
};
int main(){
    cout<<"Enter the size of array"<<endl;
    int size;
    cin>>size;

    List list(size);

  
    cout << "Enter the elements of array (Enter -1 to stop): ";
    int input;
    for(int i = 0; i < size; i++) {
        cin >> input;
        if(input == -1)
            break;
        list.arr[i] = input;
        list.length++;
    }
    
    cout<<"____which operation you want to use____"<<endl<<"1. create list"<<endl<<"2. copy"<<endl<<"3. clear "<<endl<<"4. insert"<<endl<<"5. remove by position"<<endl<<"6. get"<<endl<<"7. update"<<endl<<"8. find"<<endl<<"9. length"<<endl;
    cout<<"Enter choice: "<<endl;
    int choice;
    cin>>choice;


    switch(choice){

        case 1:{

        cout << "Enter the size of the list: ";
        int size;
        cin >> size;
        List list(size);
        cout << "Enter the elements of the list (Enter -1 to stop): ";
        for(int i = 0; i < size; i++) {
         cin >> input;
         if(input == -1)
            break;
        list.arr[i] = input;
        list.length++;
         }
         list.display_list();
            break;

        }
       case 2:{
            List list2(list);
            list2.Copy(list, list2);
        
        break;
        }
        case 3:{
            list.Clear();
            break;

        }
        case 4:{ 

            cout<<"Enter the value you want to insert"<<endl;
            int val;
            cin>>val;
            cout<<"Enter the position you want to insert"<<endl;
            int pos;
            cin>>pos;

            list.Insert(val,pos);

           break;


        }
        case 5:{
            cout<<"Enter the position you want to remove"<<endl;
            int pos;
            cin>>pos;

            list.Remove(pos);

            break;
        }
        case 6:
        {
            cout<<"Enter the position you want to get"<<endl;
            int pos;
            cin>>pos;

            list.Get(pos);
         
            break;
            }
        case 7:
        { 
            cout<<"Enter the position where you want to update"<<endl;
            int pos;
            cin>>pos;
            cout<<"Enter the value you want to update on that position"<<endl;
            int val;
            cin>>val;
            list.Update(pos,val);
           
            break;
        }
        case 8:
           {
            cout<<"Enter the value you want to find"<<endl;
            int val;
            cin>>val;
            list.Find(val);
            break;
           }
        case 9:
            cout << "Length of list: " << list.length << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;      
    }
    
}

