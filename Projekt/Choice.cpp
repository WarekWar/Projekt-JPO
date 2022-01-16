#include "Choice.h"
#include "ObjectClass.h"
#include <windows.h>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <cmath>
using std::cout, std::cin, std::endl;
using namespace std::this_thread;    
using namespace std::chrono_literals; 
using std::chrono::system_clock;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int money = 0;
int Max_hp;
//Empty objects, that will be changed by methods 
Mob hero(0, 0, 0, 0);
Mob monster(0, 0, 0, 0);

// Monster Objects
Mob orc(100, 4, 5, 1);
Mob skeleton(80, 4, 6, 2);
Mob bat(100, 6, 3, 2);
Mob demon(70, 6, 8, 4);
Mob goblin(70, 4, 10, 2);
Mob vampire(120, 6, 10, 0);
Mob ghost(60, 10, 4, 0);
Mob warewolf(115, 8, 6, 5);
Mob undead(90, 5, 7, 4);
Mob slime(70, 4, 10, 2);
Mob mimik(80, 4, 8, 1);
////////////////////

// Hero objects
Mob Artur(100, 5, 6, 3);
Mob Rossalia(90, 3, 7, 1);
Mob Dante(130, 5, 5, 3);
Mob Mirael(80, 7, 8, 0);

// Constructor doesn't do anything
Engine::Engine() {}

/*
Allows player to choose his/her Hero by entering a value.
Number '4' is used for debug purpose and it shouldn't be used 
*/
void Engine::Choose_Hero()
{
int wybor,create;
cout << "Choose your hero" << endl<<endl;
cout << "0 - Artur, famous knight of Silvar" << endl;
cout << "1 - Rossalia, mysterious bounty hunter" << endl;
cout << "2 - Dante, outsider" << endl;
cout << "3 - Mirael, priestess of blue flame order" << endl;
cout << "4 - Create your own charakter" << endl;
bool warunek2 = true;
do
    {

        cin >> wybor;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore();
            warunek2 = true;
            cin >> wybor;
            
        }
        
        
            switch (wybor)
            {
            case 0:

                cout << Artur.Get_hp() << " " << Artur.Get_dmg() << " " << Artur.Get_hit_rat() << " " << Artur.Get_def() << endl;
                hero = Artur;
                warunek2 = false;
                break;
            case 1:

                cout << Rossalia.Get_hp() << " " << Rossalia.Get_dmg() << " " << Rossalia.Get_hit_rat() << " " << Rossalia.Get_def() << endl;
                hero = Rossalia;
                warunek2 = false;
                break;
            case 2:

                cout << Dante.Get_hp() << " " << Dante.Get_dmg() << " " << Dante.Get_hit_rat() << " " << Dante.Get_def() << endl;
                hero = Dante;
                warunek2 = false;
                break;
            case 3:

                cout << Mirael.Get_hp() << " " << Mirael.Get_dmg() << " " << Mirael.Get_hit_rat() << " " << Mirael.Get_def() << endl;
                hero = Mirael;
                warunek2 = false;
                break;
            case 4:
                cout << "enter hp value" << endl;
                cin >> create; hero.Set_hp(create);
                cout << "enter dmg value" << endl;
                cin >> create; hero.Set_dmg(create);
                cout << "enter hit ratio value" << endl;
                cin >> create; hero.Set_hit_rat(create);
                cout << "enter def value" << endl;
                cin >> create; hero.Set_def(create);
                cout << hero.Get_hp() << " " << hero.Get_dmg() << " " << hero.Get_hit_rat() << " " << hero.Get_def() << endl;
                warunek2 = false;
                break;
            default:
                warunek2 = true;

            }
        
    } while (warunek2 == true);
    int Max_hp = hero.Get_hp();

}


//Draw lots enemy randomly
void Engine::Choose_Monster()
{
  
    int wybor = rand() % 10;
    switch (wybor)
    {
    case 0:

        cout << "You encounter the orc!" << endl;
        monster = orc;
        break;

    case 1:

        cout << "You encounter the skeleton!" << endl;
        monster = skeleton;
        break;

    case 2:

        cout << "You encounter the bat!" << endl;
        monster = bat;
        break;

    case 3:

        cout << "You encounter the demon!" << endl;
        monster = demon;
        break;

    case 4:


        cout << "You encounter the goblin!" << endl;
        monster = goblin;
        break;

    case 5:


        cout <<"You encounter the vampire!" << endl;
        monster = vampire;
        break;

    case 6:


        cout << "You encounter the ghost!" << endl;
        monster = ghost;
        break;

    case 7:


        cout << "You encounter the warewolf!" << endl;
        monster = warewolf;
        break;

    case 8:


        cout << "You encounter the undead!" << endl;
        monster = undead;
        break;

    case 9:


        cout << "You encounter the slime!" << endl;
        monster = slime;
        break;

    }

}

//Increases object stats
void Engine::Shop()
{

    cout << "Would you like to buy something? - Your hear inside your head" << endl;
    cout << "You have " << money << " gold" << endl;
    int wybor;
    cout << "0 - Do not buy anything/Leave" << endl;
    cout << "1 - small vial of red liguid, 40 gold" << endl;
    cout << "2 - mysterious vial of silver liquid, 50 gold" << endl;
    cout << "3 - leather vest, 80 gold " << endl;
    cout << "4 - silver, short sword , 85 gold" << endl;
    cout << "5 - plate armor, 150 gold" << endl;
    cout << "6 - longsword, 145 gold" << endl;
    ///////////////////////
    bool warunek = true;
    do {
        cin >> wybor;
        switch (wybor)
        {
        case 0:
            cout << "You leave" << endl;
            warunek = false;
            break;
        case 1:
            if (money >= 40)
            {
                cout << "You purchased the red potion" << endl;
                hero.Set_hp(hero.Get_hp() + 10);
                money -= 40;

            }
            else
                cout << "You have no enough gold!" << endl;
            warunek = true;
            break;
        case 2:
            if (money >= 50)
            {
                cout << "You purchased the mysterious potion" << endl;
                hero.Set_hit_rat(hero.Get_hit_rat() + 1);
                money -= 50;
            }
            else
                cout << "You have no enough gold!" << endl;
            warunek = true;
            break;
        case 3:
            if (money >= 80)
            {
                cout << "You purchased the leather vest" << endl;
                hero.Set_def(hero.Get_def() + 1);
                money -= 80;
            }
            else
                cout << "You have no enough gold!" << endl;
            warunek = true;
            break;
        case 4:
            if (money >= 85)
            {
                cout << "You purchased the short sword" << endl;
                hero.Set_dmg(hero.Get_dmg() + 1);
                money -= 85;
            }
            else
                cout << "You have no enough gold!" << endl;
            warunek = true;
            break;
        case 5:
            if (money >= 150)
            {
                cout << "You purchased the plate armor" << endl;
                hero.Set_def(hero.Get_def() + 2);
                money -= 150;
            }
            else
                cout << "You have no enough gold!" << endl;
            warunek = true;
            break;
        case 6:
            if (money >= 145)
            {
                cout << "You purchased the longsword" << endl;
                hero.Set_dmg(hero.Get_dmg() + 2);
                money -= 145;
            }
            else
                cout << "You have no enough gold!" << endl;

        default:
            warunek = true;
            break;


        }


    } while (warunek == true);

}

void Engine::Fight()
{

    int dmg1 = 0;
    int dmg2 = 0;

  
    int los = 0;
    while (1)
    {
        los = rand() % 10;
        if (hero.Get_hp() <= 0)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "The Hero has been defeated" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            break;
        }
        if (monster.Get_hp() <= 0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "The enemy has been defeated" << endl;
            SetConsoleTextAttribute(hConsole, 7);

        
            money += rand() % 21 + 20;
            break;
        }
        if (los <= hero.Get_hit_rat()) {


            dmg1 = hero.Get_dmg() + los - monster.Get_def();
            if (dmg1 >= 0)
            {
                monster.Set_hp(monster.Get_hp() - dmg1);
            }
            SetConsoleTextAttribute(hConsole, 2);
            cout << "The Hero ";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "deals " << dmg1 << " damage to the enemy, " << monster.Get_hp() << " hp left" << endl;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << "The Hero misses!" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "The enemy has " << monster.Get_hp() << " hp left" << endl;
        }
        sleep_for(1s);
        los = rand() % 10;
        if (monster.Get_hp() <= 0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "The enemy has been defeated" << endl;
            SetConsoleTextAttribute(hConsole, 7);


            money += rand() % 21 + 20;
            break;
        }
        if (hero.Get_hp() <= 0)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "The Hero has been defeated" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            break;
        }
        if (los <= monster.Get_hit_rat()) {
            los = rand() % 10;
            dmg2 = monster.Get_dmg() + los - hero.Get_def();
            if (dmg2 >= 0)
            {
                hero.Set_hp(hero.Get_hp() - dmg2);
            }
            SetConsoleTextAttribute(hConsole, 4);
            cout << "The enemy ";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "deals " << dmg2 << " damage to the Hero, " << hero.Get_hp() << " hp left" << endl;
        }
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "The enemy misses!" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "The Hero has " << hero.Get_hp() << " hp left" << endl;
        }
        sleep_for(1s);



    }

}

void Engine::Random_Event()
{
    int losowanie = rand() % 100;
    if (losowanie <= 5)
    {
        cout << "You sense little vibration..." << endl;
        sleep_for(2s);
        cout << "Pieces of dirt are falling..." << endl;
        sleep_for(2s);
        cout << "You look at ceiling" << endl;
        sleep_for(2s);
        cout << "Before you can react, your body rests under rocks and dirt" << endl;
        hero.Set_hp(0);
    }
    else if (losowanie > 5 && losowanie <= 20)
    {
        cout << "Following empty corridor, you hear suspicious sound" << endl;
        sleep_for(2s);
        cout << "After a while you discover its origin..." << endl;
        /////////////////////////                                                                                                      
        Choose_Monster();
        Fight();
    }     ///walka
    else if (losowanie > 20 && losowanie <= 40)
    {
        char wybor;
        cout << "Walking through long and dark corridors, you notice wooden chest in a shadow" << endl;
        sleep_for(3s);
        cout << "Curious, what it is inside..." << endl;
        sleep_for(2s);
        cout << "Do you want to open?" << endl;
        cout << "y - yes, n - no" << endl;
    ponow:
        cin >> wybor;
        if (wybor == 'y')
        {
            cout << "You decided to open the chest..." << endl;
            if (losowanie > 20 && losowanie <= 25)
            {
                cout << "It is a mimic!" << endl;
                monster = mimik;
                Fight();
                                                                                                     
            }
            else if (losowanie > 25 && losowanie <= 35)
            {
                cout << "The chest hid marvelous treasure!" << endl;
                money += 20;
                                                                                              
            }
            else
            {
                cout << "The chest was empty..." << endl;
                sleep_for(1s);
                cout << "Bad luck... " << endl;
            }
        }
        else if (wybor == 'n')
        {
            cout << "You left the chest..." << endl;
        }
        else
            goto ponow;
    }
    else if (losowanie > 40 && losowanie <= 60)
    {
        cout << "You find small, light altar with weird cat idol filled with water" << endl;
        sleep_for(2s);
        cout << "You feel thirsty..." << endl;
        sleep_for(2s);
        cout << "Drink water?" << endl;
        cout << "y - yes, n - no" << endl;
        char wybor;
    wroc:
        cin >> wybor;
        if (wybor == 'y')
        {

            cout << "You drank water..." << endl;
            if (losowanie > 40 && losowanie <= 48)
            {
                cout << "You do not feel well" << endl;
                ///////////////////////                                
                hero.Set_hp(hero.Get_hp()-5);
            }
            else
            {
                cout << "You feel refreshed" << endl;
                /////////////////////////          
                hero.Set_hp(hero.Get_hp() +10);
            }

        }
        else if (wybor == 'n')
        {
            cout << "You left altar..." << endl;
        }
        else
            goto wroc;


    }
    else if (losowanie > 60 && losowanie <= 70)
    {
        cout << "You see strange items with prices, but there is no one nearby" << endl;
        sleep_for(2s);
       Shop();

    }
    else
        cout << "Luckly nothing happend" << endl;

    sleep_for(1s);
}

bool Engine::GameOver()
{   
    if (hero.Get_hp() <= 0)
    {
        SetConsoleTextAttribute(hConsole, 3);
        cout << "GAME OVER" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << endl;
        return false;
    }
    else
        return true;
}

void Engine::Recover()
{
    int Max_hp = hero.Get_hp();
    if (hero.Get_hp() > 0)
    {
        hero.Set_hp(hero.Get_hp() + 5);
        
    }
}