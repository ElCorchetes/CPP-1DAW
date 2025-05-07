#include <iostream>
#include <cstdlib>
using namespace std;

int spell;

void sleep(int time) {
	for (int j = 0; j < time; j++) {}
}
void printTxt(string txt) {
	for (int i = 0; i < txt.length(); i++) {
		cout << txt[i];
		sleep(160000000);
	}
}
int heroAttackEnemy() {
	int damage = rand() % 11 + 1;
	int attack = rand() % 5 + 4;
	if (attack == 3 || damage == 0) {
		cout << "You miss the attack: -0 hp\n";
		return 0;
	}
	else if (attack == 2) {
		damage *= 2;
		cout << "Critical hit: " << damage << " hp\n";
		return damage;
	}
	else {
		cout << "Hit: " << damage << " hp\n";
		return damage;
	}
}
void inventory(int& life, int& mp, int& hpPotion, int& mpPotion) {
	string in;
	cout << "[1. Heal Potion] Units: " << hpPotion << "\n";
	cout << "[2. Mana Potion] Units: " << mpPotion << "\n";
	cin >> in;
	if (in == "1" && hpPotion > 0) {
		hpPotion--;
		if (life + 7 > 20) {
			life = 20;
		}
		else {
			life = life + 7;
		}
		printTxt("You use heal potion | +7 hp\n");
	}
	else if (in == "2" && mpPotion > 0) {
		mpPotion--;
		if (mp + 8 > 20) {
			mp = 20;
		}
		else {
			mp = mp + 8;
		}
	}
	else {
		printTxt("No potions available\n");
	}
}
int spells(int& mp) {
	string in;
	cout << "[1. Magic Shield -7MP] [2. Zap -10MP] [3. Hydro Pump -12MP]\n";
	cin >> in;
	if (in == "1" && mp >= 7) {
		mp -= 7;
		spell = 1;
		printTxt("You invoke a magic shield\n");
		return 0;
	}
	else if (in == "2" && mp >= 10) {
		mp -= 10;
		spell = 2;
		printTxt("You stun Cerbero: -4 hp\n");
		return 4;
	}
	else if (in == "3" && mp >= 12) {
		mp -= 12;
		spell = 3;
		printTxt("You use Hydro Pump: -17 hp\n");
		return 17;
	}
	else {
		printTxt("Not enough MP\n");
		return 0;
	}
}
int heroController(int& life, int& mp, int& hpPotion, int& mpPotion) {
	string in;
	cin >> in;
	if (in == "1") {
		return heroAttackEnemy();
	}
	else if (in == "2") {
		inventory(life, mp, hpPotion, mpPotion);
	}
	else if (in == "3") {
		return spells(mp);
	}
	return 0;
}
int enemyAttackHero() {
	int damage = rand() % 11 + 2;
	if (spell == 2) {
		cout << "Cerbero is stunned\n";
		return 0;
	}
	else {
		cout << "Cerbero bites you: -" << damage << " hp\n";
		return damage;
	}
}
void printStatus(int life, int mp, int enemyLife) {
	// Enemy GUI
	cout << " /\\_/\\ /\\_/\\ /\\_/\\\n";
	cout << " ( o o ) ( o o ) ( o o )\n";
	cout << " \\_^_/ \\_^_/ \\_^_/\n";
	cout << " / | | | \\\n\n";
	cout << " Cerbero\n";
	cout << " [";
	for (int i = 0; i < enemyLife; ++i) cout << "#";
	for (int i = 0; i < 40 - enemyLife; ++i) cout << " ";
	cout << "] " << enemyLife << "/40\n\n";
	cout << "----------------------------------------------------\n";
	// Character GUI
	cout << "HP: [";
	for (int i = 0; i < life; ++i) cout << "#";
	for (int i = 0; i < 20 - life; ++i) cout << " ";
	cout << "] " << life << "/20\n";
	cout << "MP: [";
	for (int i = 0; i < mp; ++i) cout << "#";
	for (int i = 0; i < 20 - mp; ++i) cout << " ";
	cout << "] " << mp << "/20\n\n";
	cout << "[1. Attack] [2. Items] [3. Spells]\n";
}
int main() {
	int enemyLife = 40;
	int life = 20;
	int mp = 20;
	int hpPotion = 2;
	int mpPotion = 1;
	int armor = 4;

	//printTxt("A dark cave, the echo of your footsteps reverberates. Suddenly\n");
	//printTxt("Unknown: WHAT ARE YOU DOING IN MY CAVE?\n");
	//printTxt("You: I didn’t come here looking for trouble\n");
	//printTxt("Cerbero: Hahaha! I am Cerbero, the guardian of this place\n");
	//printTxt("You: What is so funny?\n");
	//printTxt("Cerbero: Very well, human. Let the dance begin!\n");

	while (enemyLife > 0 && life > 0) {
		for (int i = 0; i < 100; i++) cout << "\n";
		printStatus(life, mp, enemyLife);
		int heroAttack = heroController(life, mp, hpPotion, mpPotion);
		enemyLife -= heroAttack;
		sleep(2145000000);
		int enemyAttack = enemyAttackHero();
		if (spell > 0) {
			life -= (enemyAttack - armor);
			armor -= 2;
			spell = 0; // Reset spell effect
		}
		else {
			life -= enemyAttack;
		}
		sleep(2145000000);
	}
	if (enemyLife <= 0) {
		printTxt("Cerbero: HOW IS THIS POSSIBLE!\n");
		printTxt("You WIN!\n");
	}
	else {
		printTxt("Cerbero: Your bones will be perfect for my collection!\n");
			printTxt("You LOST!\n");
	}
	return 0;
}