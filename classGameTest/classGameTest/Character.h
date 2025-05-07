#pragma once
#include <iostream>
using namespace std;
class Character
{
private:
	string name;
	int hp;
	int maxHp;
	int damage;

public:
	Character();
	Character(string name, int hp, int damage);

	string getName();
	void setName(string name);

	int getHp();
	void setHp(int hp);

	int getDamage();
	void setDamage(int damage);

	string getLifeBar();

	string getStatus();
	void attack(Character& c);
};

