#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

float Calculate_average_stock(int size, int* inventory) {
    int total_stock = 0;

    for (int i=0;i<size;i++) {
        total_stock += inventory[i];
    }
    return static_cast<float>(total_stock)/size; // type casting to convert int to float for precision

}


int Critical_products(int size,int* inventory){

     int avg= Calculate_average_stock(size,inventory);
     int count = 0;
    for (int i=0;i<size;i++) {
        if (inventory[i]<avg) {
            ++count;
        }
    }
    return count;
  

}



int Find_Top_Selling_Products(int size,int* inventory){

     int maxIndex = 0;
     for (int i=1;i<size;i++) {
          if (inventory[i] > inventory[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
  

}


int Find_Second_Best_Selling_Products(int size,int *inventory){
      int maxIndex = 0;
    int secondMaxIndex = -1;
    for (int i=1;i<size;i++) {
        if (inventory[i]>inventory[maxIndex]) {
            secondMaxIndex=maxIndex;
            maxIndex=i;
        } else if (secondMaxIndex==-1 || inventory[i]<inventory[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }
    return secondMaxIndex;

}



void Sorting_By_popularity(int size,int *inventory){
       for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-i-1;j++) {
            if (inventory[j] < inventory[j+1]) {
                // Swap if the current element is less than the next element
               return swap(inventory[j], inventory[j + 1]);
            }
        }
    }
}



int main(){
   

    int size,choice;

    cout<<"enter the size if the inventory array"<<endl;
    cin>>size;

   
      srand(time(NULL)); //random generation with time

     int *inventory=new int[size];

      for(int i=0;i<size;i++){
        
       inventory[i]= rand()%100+1; //storing the random numbers in array
       
      }

    
    cout<<"1. Calculate the average stock level"<<endl<<"2. Identify critical products"<<endl<<"3. Discover top-selling product"<<endl<<"4. Find second best-selling product"<<endl<<"5. Sort products by popularity"<<endl;
    cin>>choice;
    
    switch(choice){
      
      case 1:
       
       //calling calulate average function through pointer function
    {
        float (*fun_average)(int,int*);
        fun_average=&Calculate_average_stock;
        float res=fun_average(size,inventory);

        cout<<"Average Stock level: "<<res<<endl;
        break;

        
    
    }

     case 2:

        //calling critical products function through pointer function
      {  
        int (*fun_critical)(int,int*);
        fun_critical=&Critical_products;
        int res2=fun_critical(size,inventory);
        
        cout<<"Critical products: "<<res2<<endl;
        break;
      }

      case 3:

       { //calling top selling products function through pointer function
        
        int (*fun_top_selling)(int,int*);
        fun_top_selling=&Find_Top_Selling_Products;
        int res3=fun_top_selling(size,inventory);
        
        cout<<"Top selling product: "<<res3<<endl;
        break;
   
       }

       case 4:

       { //calling second best selling products function through pointer function
        
        int (*fun_Sec_top_selling)(int,int*);
        fun_Sec_top_selling=&Find_Second_Best_Selling_Products;
        int res4=fun_Sec_top_selling(size,inventory);
        
        cout<<"Second best selling product: "<<res4<<endl;
        break;
   
       }


        case 5:

       { 
        //calling sorting function through pointer function
        
        void (*fun_Sort)(int,int*);
        fun_Sort=&Sorting_By_popularity;
        fun_Sort(size,inventory);
        
        cout<<"Sorted Inventory by Popularity: "<<endl;
        for (int i=0;i<size;++i)
        {
        cout<<inventory[i]<< " ";
        }
        cout<<endl;

        break;
   
       }
       

    


    delete[] inventory;
}
}


          