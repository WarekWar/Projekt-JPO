#ifndef Choice_HEADER
#define Choice_HEADER
#include "ObjectClass.h"

#include <iostream>
/*
	Class used to textualize mechanics of the game
*/

class Engine{

public:
	//Constructor doesnt do anything
	Engine();

	//Set Hero and Monster
	void static Choose_Hero();
	void static Choose_Monster();

	//Increases hero's stats
	void static Shop();

	//Uses Choose_Nonster and then 2 objects fight until 
	//program detects negative value of 'hp' in any object
	void static Fight();

	//Draw lots events. Uses previous methods aswell 
	void static Random_Event();

	//Return false if 'Hero hp' is lower or equal 0
	bool static GameOver();

	//Add const value to object's 'hp' every time room is passed by 
	void static Recover();
};

#endif

