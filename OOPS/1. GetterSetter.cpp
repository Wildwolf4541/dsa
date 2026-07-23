#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    char name[100];
    int health;
    
    public:
    char level;

    //getters
    int getHealth(){ return health;}
    char getLevel(){ return level;}

    //setters
    void setHealth(int h){ health=h;} // can also put conditions in here.
    void setLevel(char l){ level=l;}    
};
int main(){
//static allocation.
    Hero A;
    // cout<<A.health - gives error as health is private and can't be accessed outside class.
    A.level='S';
    A.setHealth(100);
    cout<<"A's Health: "<< A.getHealth()<<endl;
    cout<<"A's Level: "<< A.level<<endl;

// dynamic allocation.
    Hero *B= new Hero;
    B->level='A';
    B->setHealth(50);
    cout<<"B's Health: "<< B->getHealth()<<endl;
    cout<<"B's Level: "<< B->level<<endl;
}