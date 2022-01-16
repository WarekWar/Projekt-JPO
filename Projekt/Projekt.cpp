#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <thread>
#include <windows.h>
#include <vector>

#include "ObjectClass.h"
#include "Choice.h"
#include "Interaction.h"


using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc
using std::cin, std::cout, std::endl;
using std::chrono::system_clock;
Engine engine;
interact inter;

int main()
{
	
	engine.Choose_Hero();

	int ilosc_sal=0;
	srand(time(0));
	
	while (1)
	{
		if (engine.GameOver() == false)
			break;
		inter.Draw();
		inter.Move();
		engine.Random_Event();
		
		//engine.Choose_Monster();
		//engine.Fight();
		ilosc_sal++;
		
		engine.Recover();
	}
	
	cout << "You managed to go through " << ilosc_sal << " rooms" << endl;
}