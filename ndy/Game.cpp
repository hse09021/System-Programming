#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 50
 
using namespace std;

class Character
{
    private:
        char* name;    // 캐릭터 이름
        int level;      // 캐릭터 레벨 
        int power;      // 캐릭터 힘
        int quickly;    // 캐릭터 민첩
        int iq;         // 캐릭터 지능
        int attack;    // 캐릭터 공경    
        int shield;     // 캐릭터 방어력
        int health;     // 캐릭터 체력
        int mind;       // 캐릭터 정신력 

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
        ~Character() {}  // 가상 Charactor 클래스 생성
        void Moshowinfo (char* weapon){
            cout<<"캐릭터 이름 : "<<name<<endl;
            cout<<"캐릭터 무기 : "<<weapon<<endl;
            cout<<"캐릭터 레벨 : "<<level<<endl;
            cout<<"캐릭터 힘 : "<<power<<endl;
            cout<<"캐릭터 민첩 : "<<quickly<<endl;
            cout<<"캐릭터 지능 : "<<iq<<endl;
            cout<<"캐릭터 공격 : "<<attack<<endl;
            cout<<"캐릭터 방어력 : "<<shield<<endl;
            cout<<"캐릭터 체력 : "<<health<<endl;
            cout<<"캐릭터 정신력 : "<<mind<<endl;
        }
        
};

class Warrior: public Character
{
    private:
        char* weapon = new char[MAX];     // 무기 
    public:
        Warrior(char* name, char* weapon) 
         : Character(name, 1, 100, 50, 20, 5, 3, 80,20)
        {
            this->weapon = weapon;
            // strcpy(this->weapon, weapon);
        }    // Warrior 디폴트 생성자 
        void attack(){
            cout<<this->weapon<<" 칼로 찔렀습니다."<<endl;
        }
        void showInfo(){
            Moshowinfo(weapon);
        }
        void move(){
            cout<<"이동하였습니다."<<endl;
        }
        ~Warrior() {}   // Warrior 생성자 삭제 
};

class Archer: public Character
{
    private:
        char* weapon;     // 무기
    public:
        Archer(char* name, char* weapon) 
            : Character(name, 1, 50, 100, 20, 5, 3, 50,50)
        {
            this->weapon = weapon;
            // strcpy(this->weapon, weapon);
        }   // Archer 디폴트 생성자 
        void attack(){
            cout<<this->weapon<<" 화살을 쐈습니다."<<endl;
        }
        void showInfo(){
            Moshowinfo(weapon);
        }
        void move(){
            cout<<"이동하였습니다."<<endl;
        }
        ~Archer() {}   // Archer 생성자 삭제 
};

class Sorcerer: public Character
{
    private:
        char* weapon;     // 무기
    public:
        Sorcerer(char* name, char* weapon)
            : Character(name, 1, 20, 50, 100, 5, 3, 20,80)
        {
            this->weapon = weapon;
            // strcpy(this->weapon, weapon);
        }    // Sorcerer 디폴트 생성자 
        void attack(){
            cout<<this->weapon<<"마법을 걸었습니다."<<endl;
        }
        void showInfo(){
            Moshowinfo(weapon);
        }
        void move(){
            cout<<"이동하였습니다."<<endl;
        }
        ~Sorcerer() {}   // Sorcerer 생성자 삭제 
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
            cout<<"현재 bag의 사이즈는 "<<size<<" 입니다."<<endl;
        }
        
};

int main()
{
    char* name = new char[MAX];
    char* weapon = new char[MAX];
    Bag bg;
    bg.Size(0);
    cout<<"IsEmpty 값은 "<<bg.IsEmpty(0)<<" 입니다."<<endl;
    cout<<"Warrior 캐릭터 이름을 입력하세요 : ";
    cin>>name;
    cout<<"무기 이름을 입력하세요 : ";
    cin>>weapon;
    Warrior wa(name, weapon);
    wa.attack();
    wa.showInfo();
    wa.move();

    cout<<"Archer 캐릭터 이름을 입력하세요 : ";
    cin>>name;
    cout<<"무기 이름을 입력하세요 : ";
    cin>>weapon;
    Archer Ar(name, weapon);
    Ar.attack();
    Ar.showInfo();
    Ar.move();

    cout<<"Sorcerer 캐릭터 이름을 입력하세요 : ";
    cin>>name;
    cout<<"무기 이름을 입력하세요 : ";
    cin>>weapon;
    Sorcerer So(name, weapon);
    So.attack();
    So.showInfo();
    So.move();
}
