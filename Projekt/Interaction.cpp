#include "Interaction.h"

#include <iostream>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc
using std::cin, std::cout, std::endl;
const int width = 20;
const int height = 20;
int x = 0, y = 0;

interact::interact() {}

void interact::Move()
{
    cout << "Which way will you choose?" << endl;
    cout << "u - up, d - down, r - right, l - left" << endl;
    char kierunek;
    bool warunek1 = true;
    do {
        cin >> kierunek;
        switch (kierunek)
        {
        case 'u':
            if (y == 0)
            {
                cout << "You cannot go through a wall" << endl;
                warunek1 = true;
            }
            else
            {
                cout << "You went forward..." << endl;
                y--;
                warunek1 = false;
                sleep_for(1s);

            }

            break;
        case 'd':
            if (y == height)
            {
                cout << "You cannot go through a wall" << endl;
                warunek1 = true;
            }
            else
            {
                cout << "You went back" << endl;
                y++;
                warunek1 = false;
                sleep_for(1s);

            }

            break;
        case 'r':
            if (x == width)
            {
                cout << "You cannot go through a wall" << endl;
                warunek1 = true;
            }
            else
            {
                cout << "You turned right" << endl;
                x++;
                warunek1 = false;
                sleep_for(1s);

            }

            break;
        case 'l':
            if (x == 0)
            {
                cout << "You cannot go through a wall" << endl;
                warunek1 = true;
            }
            else
            {
                cout << "You turned left" << endl;
                x--;
                warunek1 = false;
                sleep_for(1s);
            }

            break;
        default:
            warunek1 = true;
            break;
        }
    } while (warunek1 == true);
}

void interact::Draw()
{
    system("cls");
    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "P";
            else
                cout << " ";
            if (j == width - 1)
                cout << "#";

        }
        cout << endl;
    }

    for (int i = 0; i < width + 1; i++)
        cout << "#";
    cout << endl;


}


