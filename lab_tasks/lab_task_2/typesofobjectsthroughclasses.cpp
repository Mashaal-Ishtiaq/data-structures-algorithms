#include <iostream>
using namespace std;
struct Person{
    string name;
     Person(string name){
        this->name=name;
    } 
};
class Person1{
    public:
    Person1(){
        cout<<"i am constructor"<<endl;
    } ~Person1(){
        cout<<"i am destructor"<<endl;
    }
};
int main(){ 
    Person1 p1; //regular object's destructor will be called automatically
    cout<<"hello"<<endl;
}

#include <iostream>
using namespace std;
struct Person{
    string name;
     Person(string name){
        this->name=name;
    } 
};
class Person1{
    public:
    Person1(){
        cout<<"i am constructor"<<endl;
    } ~Person1(){
        cout<<"i am destructor"<<endl;
    }
};
int main(){ 
Person1 *p1=new Person1(); //dynamic object's destructor will be called when the object is deallocated manually
cout<<"hello"<<endl;
delete p1;
}