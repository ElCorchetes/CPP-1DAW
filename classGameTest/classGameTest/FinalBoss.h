#pragma once 
#include "Enemy.h"

using namespace std;

class FinalBoss : public Enemy
{
private:
	int magicDamage;
	int lifeSteal;
public:
	FinalBoss();
	FinalBoss(string name, int hp, int damage, int magicDamage, int lifeSteal, string sprite);
	int getMagicDamage();
	void setMagicDamage(int magicDamage);
	int getLifeSteal();
	void setLifeSteal(int lifeSteal);
	virtual void attack(Character& c);
};
