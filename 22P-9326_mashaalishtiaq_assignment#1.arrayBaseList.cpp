#include<iostream>
using namespace std;

class List{

    public:
  //publically declaring data members as we dont want to use getter setters
      int *arr;
      int length;
      int capacity;
      int *curr=arr;   

   //constructor
    
   List(int size){
    //data members initialization
    int*curr;
    arr=new int[size]; 
    capacity=size;
    length=0;
    curr=arr;
    cout << "Enter the elements of array (Enter -1 to stop): ";
     int input=0;

    for(int i=0;i<size;i++){
        if(input==-1){
            break;
            }
            cin>>input;
        this->arr[i]=input;
        this->length++;

    }
   }  


   //destructor
   ~List(){
    delete[] arr;
   }

   void next(){
       curr++;
   }

   void back(){
        curr--;
   }

   void start(){
      curr=arr;
   }

   void tail(){
     curr=arr+length-1;
     
   }
   //copy constructor
     List(const List& other){
      capacity=other.capacity;
      length=other.length;
      arr=new int[capacity];
      for(int i=0;i<length;i++){
          arr[i]=other.arr[i];
      }
      curr=arr+(other.curr-other.arr);
      cout<<"list copied"<<endl;
   }



    void Clear(){
        length=0;
    }

    void Insert(int val){

       isFull();
       
        
        if(length<capacity){
        tail();
       *(curr+1)=val;
        
        if(length==0){
        
            *curr=val;
        }
        length++;
    }
    }

    void Insert_to(int val,int pos){
        isFull();
        if(length<capacity){
        if(pos<1 || pos>length+1){
             cout<<"Invalid position"<<endl;
             return;
        }}

         tail(); //pointer will reach to the tail value

        for(int i=length;i>=pos;i--){

        *(curr+1)=*curr;
        back();
       }
      *(curr+1)=val;
      length++;
    }


    void Print_list(){
        

         for(int i=0;i<length;i++){
            cout<<*(arr+i)<<" ";
         }
         cout<<endl;
    }
   
   void isFull(){
      if(length==capacity){
        cout<<"Array is full"<<endl;
      }
      else
      cout<<"array is not full"<<endl;

   }

   void isEmpty(){
       if(length==0){
        cout<<"Array is empty"<<endl;
       }
       else{
        cout<<"array not empty"<<endl;
       }
   }

   
   
   void Remove(int val){
        isEmpty();
       
       if(length>0){
       int pos=Find(val);

        for(int i=pos;i<=length;i++){
        *(curr)=*(curr+1);
        next();
    }
       length--;
   }}
   

   void RemoveTo(int pos){
        isEmpty();
       
        if(length>0){
        if(pos<1 || pos>length){
        cout<<"Invalid position"<<endl;
        return;
    }
       curr=arr+pos-1;
        for(int i=pos;i<=length;i++){
        *(curr)=*(curr+1);
        next();
    }
    length--;
   }}

   int Get(int pos){
          isEmpty();
            
        if(length>0){
        if(pos<1 || pos>length){
             cout<<"Invalid position"<<endl;
            return 0;
        }
        curr=arr+pos-1;
        }
        return *curr;
   }

   void Update(int pos,int val){

        isEmpty();
           
        if(length>0){
        if(pos<1 || pos>length){
            cout<<"Invalid position"<<endl;
            return;
        }
        curr=arr+pos-1;
        *curr=val;

   }}

   int  Find(int val){
            isEmpty();
           
        if(length>0){
        start();

        for(int i=1;i<=length;i++){
            if(*curr==val){
              return i;
                  
            }
            next();
        }}
        cout<<"Value not found"<<endl;
        return -1;
    }

    void Reverse_list(){

        isEmpty();
        if(length>0){

          int left=0;
          int right=left+length-1;

          while(left<right){

            int temp=arr[left];
            arr[left]=arr[right];
            arr[right]=temp;
            left++;
            right--;
          }

    }}

    void Sort_list(){

        isEmpty();
        
         if(length>0){
        for( int i=0;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(arr[j]<arr[i] ){
                    // Swap elements
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                
                }
                


            }
        }

    }
    }

};

int main(){

    int size,found,value;
    int val;
    int pos;
    char ch;

    cout<<"Enter size of the array: "<<endl;
    cin>>size;
   
    while(1){
    cout<<"___Enter the operation you want to perform___"<<endl;
    cout<<"1. create list"<<endl<<"2. copy"<<endl<<"3. clear"<<endl<<"4. insert"<<endl<<"5. remove"<<endl<<"6. get"<<endl<<"7. update"<<endl<<"8. find"<<endl<<"9. length"<<endl<<"10. print List"<<endl<<"11. reverse list"<<endl<<"12. sort in ascending order"<<endl<<"13. isFull()"<<endl<<"14. isEmpty"<<endl<<"15. none"<<endl;
    int choice;
    cout<<"Enter your choice from above: "<<endl;
    cin>>choice;

    
       List *list;
      List *list2;
    switch(choice){
           
        case 1:
          list=new List(size); // constructor called
          break;

        case 2:
            list2=new List(*list);  //copy constructor called->deep copy
            delete list2;
            break;

        case 3:
           list->Clear();
           cout<<"list cleared"<<endl;
           break;

        case 4:   
            cout<<"Select which insert function you want to perform"<<endl;
            cout<<"a. intsert a value"<<endl<<"b. insert at a certain position"<<endl;
        
            cin>>ch;

            if(ch=='a'){
                cout<<"Enter the value you want to insert"<<endl;
              
                cin>>val;
                list->Insert(val);
            }
            if(ch=='b'){
                cout<<"Enter the value you want to insert"<<endl;
                
                cin>>val;

                cout<<"Enter the position where you want to insert"<<endl;
               
                cin>>pos;

                list->Insert_to(val,pos);

            }
            else{
                cout<<"Invalid selection"<<endl;
            }
            break;

        case 5:
         cout<<"Select the remove function you want to perform" <<endl;
         cout<<"a. Remove value"<<endl<<"b. Remove value on certain position"<<endl;
        
         cin>>ch;
         if(ch=='a'){
                cout<<"Enter the value you want to remove"<<endl;
                
                cin>>val;
                list->Remove(val);
                cout<<"value removed successfully"<<endl;
            }
         if(ch=='b'){
           
            cout<<"Enter the position where you want to remove the value from"<<endl;
               
                cin>>pos;    
                list->RemoveTo(pos);
                cout<<"value removed successfully from the given position"<<endl;

         }   
         break;
        
        case 6:
       
             cout<<"Enter the position from which you want to retrieve value"<<endl;
             cin>>pos;
              value=list->Get(pos);
             cout<<"Value: "<<value<<endl;
             break;

        case 7:
             cout<<"Enter the position where you want to enter the new value: "<<endl;
             
             cin>>pos;
             cout<<"Enter the value now: "<<endl;
            
             cin>>val;

             list->Update(pos,val);  
             break;

        case 8:
          
            cout<<"Enter the value you want to find"<<endl;
            cin>>val;

             found=list->Find(val);
             cout<<"value found at index: "<<found<<endl;
           
            break;

        case 9:
          list->isEmpty();
          cout<<"length is: "<<list->length<<endl;
          break;

        case 10:
         list->Print_list();  
         break; 

        case 11:
         list->Reverse_list();
         cout<<"List successfully reversed"<<endl;
         list->Print_list();
         break; 
        
        case 12:
        list->Sort_list();
        cout<<"array sorted in ascending order"<<endl;
        list->Print_list();
        break;
        case 13:
        list->isFull();
        break;

        case 14:
        list->isEmpty();
        break;

        case 15:
        break;

        default:
        cout<<"Invalid output"<<endl;
    }
        
    }


    }

