#include <iostream>
using namespace std;
struct Person{
    string name;
    Person(string name){
        this->name=name;
    } 
};
int main(){
    Person p1("urooba"); //regular object stored in stack
    cout<<p1.name<<endl;
}



#include <iostream>
using namespace std;
struct Person{
    string name;
     Person(string name){
        this->name=name;
    } 
};
int main(){
    Person *p2=new Person("urooba"); //dynamic object stored in stack and this pointer is of the constructor not of int
    cout<<p2->name<<endl;
}