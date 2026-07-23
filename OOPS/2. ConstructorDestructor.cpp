#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    char name[100];
    int health;
    
    public:
    char level;

    void print(){
        cout<<"level: "<<level<<endl;
        cout<<"health: "<<health<<endl;
    }
    //getters
    int getHealth(){ return health;}
    char getLevel(){ return level;}

    //setters
    void setHealth(int h){ health=h;} // can also put conditions in here.
    void setLevel(char l){ level=l;}

    //constructors
    Hero(){
        cout<<"Non-Parameterized Constructor Called."<<endl;
    }
    Hero(int health, char level){
        cout<<"Parameterized Constructor Called."<<endl;
        this->health=health;
        this->level=level;
    }
    Hero(Hero &temp){
        cout<<"Copy Constructor Called."<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
    // // Deep Copy Constructor
    // Hero(Hero &temp){
    //     cout<<"Deep Copy Constructor Called."<<endl;

    //     health = temp.health;
    //     level = temp.level;

    //     name = new char[strlen(temp.name)+1];
    //     strcpy(name,temp.name);
    // }

    ~Hero(){
        cout<<"Destructor called"<<endl;
    }
};
int main(){
//static allocation.
    Hero A;
    Hero B(100,'B');
    B.print();
    
// dynamic allocation.
    Hero *C= new Hero(11,'C');
    C->print();

    Hero D(B);
    Hero *E=new Hero(*C);

    D.print();
    E->print();

    delete C; 
    delete E;
}