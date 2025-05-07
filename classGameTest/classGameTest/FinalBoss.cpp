#include "FinalBoss.h";
#include "Enemy.h"

FinalBoss::FinalBoss() : Enemy() {

}

FinalBoss::FinalBoss(string name, int hp, int damage, int magicDamage, int lifeSteal, string sprite) : Enemy(name, hp, damage, sprite) {
	this->magicDamage = magicDamage;
	this->lifeSteal = lifeSteal;
}

void FinalBoss::setMagicDamage(int magicDamage) {
    this->magicDamage = magicDamage;
}

int FinalBoss::getMagicDamage() {
    return magicDamage;
}

void FinalBoss::setLifeSteal(int lifeSteal) {
    this->lifeSteal = lifeSteal;
}

int FinalBoss::getLifeSteal() {
    return lifeSteal;
}

void FinalBoss::attack(Character& c) {
    int rnd = rand() % 3; // valor aleatorio: 0, 1 o 2
    int baseDamage = getDamage();
    int totalDamage = baseDamage;

    if (rnd == 1) {
        totalDamage += magicDamage;
    }
    else if (rnd == 2) {
        totalDamage = baseDamage;
    }

    c.setHp(c.getHp() - totalDamage);

    if (rnd == 2) {
        setHp(getHp() + lifeSteal);
    }
}