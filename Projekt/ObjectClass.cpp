#include "ObjectClass.h"


Mob::Mob(int hp_, int dmg_, int hit_rat_, int def_) {
        hp = hp_;
        dmg = dmg_;
        hit_rat = hit_rat_;
        def = def_;
}
    
void Mob::Set_hp(int hp_)
{
    hp = hp_;
}
void Mob::Set_dmg(int dmg_)
{
    dmg = dmg_;
}
void Mob::Set_hit_rat(int hit_rat_)
{
    hit_rat = hit_rat_;
}
void Mob::Set_def(int def_)
{
    def = def_;
}

int Mob::Get_hp()
{
    return hp;
}
int Mob::Get_dmg()
{
    return dmg;
}
int Mob::Get_hit_rat()
{
    return hit_rat;
}
int Mob::Get_def()
{
    return def;
}




    