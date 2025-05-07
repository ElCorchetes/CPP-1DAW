#include <iostream>
#include <cstdlib>

using namespace std;

int enemyLife = 40;
int life = 20;
int mp = 20;
int spell;
int armor = 0;
int hpPotion = 2;
int mpPotion = 1;

void sleep(int time) {
    for (int j = 0; j < time; j++) {}
}

void printTxt(string txt) {
    for (int i = 0; i < txt.length(); i++) {
        cout << txt[i];
        sleep(160000000);//160000000
    }
}

void spells() {
    string in;
    cout << "[1. Magic Shield -7MP] [2. Zap -10MP] [3. Hydro Pump -12MP]\n";
    cin >> in;

    if (in == "1" && mp >= 7) {
        mp -= 7;
        armor = 5;
        spell = 1;
        printTxt("You invoke a magic shield\n");
    }
    else if (in == "2" && mp >= 10) {
        mp -= 10;
        enemyLife -= 4;
        spell = 2;
        printTxt("You stun Cerbero: -4 hp\n");
    }
    else if (in == "3" && mp >= 12) {
        mp -= 12;
        enemyLife -= 17;
        printTxt("You use Hydro Pump: -17 hp\n");
    }
    else {
        printTxt("Not enough MP\n");
    }
}

void inventory() {
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
        printTxt("You use heal potion | + 7 hp\n");
    }
    else if (in == "2" && mpPotion > 0) {
        mpPotion--;
        if (mp + 8 > 20) {
            mp = 20;
        }
        else {
            mp = mp + 8;
        }
        printTxt("You use mana potion | + 8 mp\n");
    }
    else {
        printTxt("No potions available\n");
    }
}

void heroAttackEnemy() {
    int damage = rand() % 11 + 1;
    int attack = rand() % 5 + 4;

    if (attack == 3 || damage == 0) {
        cout << "You miss the attack: -0 hp\n";
    }
    else if (attack == 2) {
        damage *= 2;
        enemyLife -= damage;
        cout << "Critical hit: " << damage << " hp\n";
    }
    else {
        enemyLife -= damage;
        cout << "Hit: " << damage << " hp\n";
    }
}

void heroControl() {
    string in;

    cin >> in;
    if (in == "1") { // Attack system
        heroAttackEnemy();
    }
    else if (in == "2") { // Items system
        inventory();
    }
    else if (in == "3") { // Spells system
        spells();
    }
}

void enemyAttackHero() {
    // Enemy turn
    int AD = rand() % 11 + 2;
    if (spell == 1) {
        if ((AD - armor) > 0) {
            life -= (AD - armor);
            cout << "Cerbero bites you: -" << (AD - armor) << " hp\n";
        }
        else {
            cout << "Cerbero's attack doesn't affect you\n";
        }
    }
    else if (spell == 2) {
        cout << "Cerbero is stunned\n";
    }
    else {
        life -= AD;
        cout << "Cerbero bites you: -" << AD << " hp\n";
    }
    for (int i = 0; i < 2145000000; i++) {}
}

void printStatus() {
    // Enemy GUI
    cout << "               /\\_/\\   /\\_/\\   /\\_/\\\n";
    cout << "              ( o o ) ( o o ) ( o o )\n";
    cout << "               \\_^_/   \\_^_/   \\_^_/\n";
    cout << "                / |       |       | \\\n\n";
    cout << "                        Cerbero\n";
    cout << "     [";
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

    //printTxt("A dark cave, the echo of your footsteps reverberates. Suddenly\n");
    //printTxt("Unknown: WHAT ARE YOU DOING IN MY CAVE?\n");
    //printTxt("You: I didn’t come here looking for trouble\n");
    //printTxt("Cerbero: Hahaha! I am Cerbero, the guardian of this place\n");
    //printTxt("You: What is so funny?\n");
    //printTxt("Cerbero: Very well, human. Let the dance begin!\n");

    while (enemyLife > 0 && life > 0) {
        for (int i = 0; i < 100; i++) cout << "\n";

        if (armor > 0) {
            armor -= 2;
            spell = 1;
        }
        else {
            spell = 0;
        }

        printStatus();

        input();

        sleep(2145000000);

        enemyAttackHero();

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
