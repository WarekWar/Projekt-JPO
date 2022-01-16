#ifndef ObjectClass_HEADER
#define ObjectClass_HEADER
#include <iostream>
/*
    Class used to create objects. 
*/
class Mob{
private:
    int hp;
    int dmg;
    int hit_rat;
    int def;
public:

    //Constructor
    Mob(int hp_, int dmg_, int hit_rat_, int def_);

    //Setters
    void Set_hp(int hp);
    void Set_dmg(int dmg);
    void Set_hit_rat(int hit_rat);
    void Set_def(int def);

    //Getters
    int Get_hp();
    int Get_dmg();
    int Get_hit_rat();
    int Get_def();

};

#endif
