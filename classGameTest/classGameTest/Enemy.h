#pragma once 
#include "Character.h" 
#include <iostream>

using namespace std;

class Enemy : public Character
{
	private:
		string sprite; //Sprite del enemigo
public:
	Enemy();
	Enemy(string name, int hp, int damage, string sprite);
	string getSprite();
};