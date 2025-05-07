#include "Enemy.h"

Enemy::Enemy() : Character() {

}

// Parameterized constructor
Enemy::Enemy(string name, int hp, int damage, string sprite) : Character(name, hp, damage) {
		this->sprite = sprite;
}

string Enemy::getSprite() {
	return sprite;
}
