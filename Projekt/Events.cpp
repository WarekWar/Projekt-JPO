#include "Events.h"

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <thread>

using std::cout, std::cin, std::endl;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc
using std::chrono::system_clock;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Walka()
{
 
    int dmg1 = 0;
    int dmg2 = 0;

    const int hp_main = hero.Get_hp();
    int los = 0;
    while (1)
    {
        los = rand() % 10;
        if (monster.Get_hp() <= 0)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Przeciwnik zostal pokonany" << endl;
            SetConsoleTextAttribute(hConsole, 7);
           
            hero.Set_hp(hp_main);
           
            break;
        }
        if (los <= hero.Get_hit_rat()) {


            dmg1 = hero.Get_dmg() + los - monster.Get_def();
            if (dmg1 >= 0)
            {
                monster.Set_hp(monster.Get_hp() - los);
            }
            SetConsoleTextAttribute(hConsole, 2);
            cout << "Bohater ";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "zadal " << dmg1 << " obrazen przeciwnikowi, ktoremu zostalo " << monster.Get_hp() << " zdrowia" << endl;
        }
        else
        {
            SetConsoleTextAttribute(hConsole, 2);
            cout << "Bohater nie trafia!" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Przeciwnikowi zostalo " << monster.Get_hp() << " zdrowia" << endl;
        }
        sleep_for(1s);
        los = rand() % 10;
        if (hero.Get_hp() <= 0)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Bohater zostal pokonany" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            break;
        }
        if (los <= monster.Get_hit_rat()) {
            los = rand() % 10;
            dmg2 = monster.Get_dmg() + los - hero.Get_def();
            if (dmg2 >= 0)
            {
                hero.Set_hp( hero.Get_hp() - dmg2);
            }
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Przeciwnik ";
            SetConsoleTextAttribute(hConsole, 7);
            cout << "zadal " << dmg2 << " obrazen bohaterowi, ktoremu zostalo " << hero.Get_hp() << " zdrowia" << endl;
        }
        else {
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Przeciwnik nie trafia!" << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Bohaterowi zostalo " << hero.Get_hp() << " zdrowia" << endl;
        }
        sleep_for(1s);



    }
 
}