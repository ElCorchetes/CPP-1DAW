#include "Character.h"
#include <string>

Character::Character()
{

}

Character::Character(string cname, int php, int cdamage)
{ //Se escribe this porque los nombres coinciden
	this->name = cname;
	this->hp = php;
    this->maxHp = php;
	this->damage = cdamage;
}

string Character::getName() {
    return name;
}

void Character::setName(string name) {
    this->name = name;
}

int Character::getHp() {
    return hp;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getDamage() {
    return damage;
}

void Character::setDamage(int damage) {
    this->damage = damage;
}

string Character::getLifeBar(){
    string bar = "";

    bar += "\033[32m";
    for (int i = 0; i < this->hp; i++) {
        bar += char(220);
    }

    bar += "\033[31m";
    for (int i = this->hp; i < this->maxHp; i++) {
        bar += char(220);
    }

    bar += "\033[0m";
    return bar;
}

void Character::attack(Character& c) { //Me envian los datos del otro personaje (C de contrincante)
	//Posteriormente llamo al setter de el contrincante para modificar su vida
	c.setHp(c.getHp() - damage);
}
