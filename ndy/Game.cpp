#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#define MAX 50
 
using namespace std;

class Character
{
    private:
        char* name;
        int level;
        int power;
        int quickly;
        int iq;
        int attack;
        int shield;
        int health;
        int mind;

    public:

        Character(char* name, int level, int power, int quickly, int iq, int attack, int shield, int health, int mind){
            this->name = name;
            this->level = level;
            this->power = power;
            this->quickly = quickly;
            this->iq = iq;
            this->attack = attack;
            this->shield = shield;
            this->health = health;
            this->mind = mind;
        }
        ~Character() {}
        void Moshowinfo (char* weapon){
            cout<<"Name : "<<name<<endl;
            cout<<"Weapon : "<<weapon<<endl;
            cout<<"Level : "<<level<<endl;
            cout<<"Power : "<<power<<endl;
            cout<<"Quickly : "<<quickly<<endl;
            cout<<"IQ : "<<iq<<endl;
            cout<<"Attack : "<<attack<<endl;
            cout<<"Shield : "<<shield<<endl;
            cout<<"Health : "<<health<<endl;
            cout<<"Mind : "<<mind<<endl;
        }
        
};

class Warrior: public Character
{
    private:
        char* weapon = new char[MAX]; 
    public:
        Warrior(char* name, char* weapon) 
         : Character(name, 1, 100, 50, 20, 5, 3, 80,20)
        {
            this->weapon = weapon;
        } 
        void attack(){
            cout<<this->weapon<<" stabbed in knife."<<endl;
        }
        void showInfo(){
            Moshowinfo(weapon);
        }
        void move(){
            cout<<"moved."<<endl;
        }
        ~Warrior() {}
};

class Archer: public Character
{
    private:
        char* weapon;
    public:
        Archer(char* name, char* weapon) 
            : Character(name, 1, 50, 100, 20, 5, 3, 50,50)
        {
            this->weapon = weapon;
        }
        void attack(){
            cout<<this->weapon<<" shot an arrow."<<endl;
        }
        void showInfo(){
            Moshowinfo(weapon);
        }
        void move(){
            cout<<"moved."<<endl;
        }
        ~Archer() {}
};

class Sorcerer: public Character
{
    private:
        char* weapon;
    public:
        Sorcerer(char* name, char* weapon)
            : Character(name, 1, 20, 50, 100, 5, 3, 20,80)
        {
            this->weapon = weapon;
        }
        void attack(){
            cout<<this->weapon<<"used magic."<<endl;
        }
        void showInfo(){
            Moshowinfo(weapon);
        }
        void move(){
            cout<<"moved."<<endl;
        }
        ~Sorcerer() {}
};

class Bag
{
    private:
        int size;
        int capacity;
        int array;
    public:
        Bag (int bagCapacity = 3):size (0){};
        string IsEmpty(int size){
            if (size==0)
                return "True";
            else
                return "False";
        }
        void Size(int size){
            cout<<"Currently size of the bag is "<<size<<endl;
        }
        ~Bag() {};
};

int main()
{
    char* name = new char[MAX];
    char* weapon = new char[MAX];
    Bag bg;
    bg.Size(0);
    cout<<"IsEmpty? "<<bg.IsEmpty(0)<<endl;
    cout<<"Warrior's Name? : ";
    cin>>name;
    cout<<"Weapon : ";
    cin>>weapon;
    Warrior wa(name, weapon);
    wa.attack();
    wa.showInfo();
    wa.move();

    cout<<"Archer's Name? : ";
    cin>>name;
    cout<<"Weapon : ";
    cin>>weapon;
    Archer Ar(name, weapon);
    Ar.attack();
    Ar.showInfo();
    Ar.move();

    cout<<"Sorcerer's Name? : ";
    cin>>name;
    cout<<"Weapon : ";
    cin>>weapon;
    Sorcerer So(name, weapon);
    So.attack();
    So.showInfo();
    So.move();
}
