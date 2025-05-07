#include <iostream>
#include <cstdlib>
#include <vector>

#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")

#include "Character.h"
#include "Enemy.h"
#include "FinalBoss.h"

using namespace std;

void printUI(Character hero, Enemy enemy) {
    cout << enemy.getSprite();
    cout << "                        " << enemy.getName() << endl;
    cout << "\n====================\n";
    cout << "Enemy HP: " << enemy.getLifeBar() << "\n";
    cout << "Your HP: " << hero.getLifeBar() << "\n";
    cout << "====================\n";
    cout << "[1. Atacar]   [2. Salir]\n";
}


int update(Character &hero, Enemy enemy){
    // Bucle de combate
    while (hero.getHp() > 0 && enemy.getHp() > 0) {
        printUI(hero, enemy);

        int choice;
        cout << "Tu eleccion: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n" << hero.getName() << " ataca!\n";
            hero.attack(enemy);
        }
        else if (choice == 2) {
            cout << "\n¡Huyendo del combate!\n";
            break;
        }

        if (enemy.getHp() > 0) {
            cout << "\n" << enemy.getName() << "ataca!\n";
            enemy.attack(hero);
        }
    }

    if (enemy.getHp() <= 0 && hero.getHp() > 0) {
        cout << "\n¡Victoria! ¡Has derrotado a Cerbero!\n";
        return 1;
    }
    else if (hero.getHp() <= 0 && enemy.getHp() > 0) {
        cout << "\n¡Derrota! ¡"<< enemy.getName() <<"te ha vencido!\n";
		return -1;
    }
    else if (hero.getHp() <= 0 && enemy.getHp() <= 0) {
        cout << "\n¡Ambos han caído en combate!\n";
		return 0;
    }

}

int main() {
    PlaySound(TEXT("s.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	string sprite_enemy = "                 /\\_/\\   /\\_/\\   /\\_/\\\n                ( o o ) ( o o ) ( o o )\n                 \\_^_/   \\_^_/   \\_^_/\n                  / |       |       | \\\n\n";
    string sprite_boss = 
        "                 %%%%%%%%%%%%%%%%          \n"
        "              @%%%%%%%%%%%%%%%%%%%         \n"
        "             %%%%%%%%%%%%%%%%%%%%%%        \n"
        "           ##%%%%%%%%%%@%%%%%%%%%%%##      \n"
        "          #*++*#%%%%%%%*@%%%%%%#**++*#     \n"
        "          *+++++++++++#+++++++++++++*#     \n"
        "         #+++++++++++*#+*#++++++++++++%    \n"
        "         *++++++++++*%+++#*+++++++++++#    \n"
        "         **##%%%%%%%##*#*###%%%%%%%#***    \n"
        "         %%%%%%%%%%%%%**#%@%%%%%%%%%%%%    \n"
        "        %%%%%%%%%%%%@@@#%@@@%%%%%%%%%%%    \n"
        "       @%%%%%%%%%%@@%%+++%@%@@%%%%%%%%%    \n"
        "       %%%%%%%%%@@@#+++++++*%%@%%%%%%%%%   \n"
        "     %%%%%%%%%@@@#+++*#+%++*+#@@%%%%%%%%%  \n"
        "    %%%%%%%%@@@@@#++++++++++%@@@@@%%%%%%%% \n"
        "   %%%%%%%%@@@@@@@%*++#%#+*@@@@@@@@%%%%%%%%\n"
        "   %%%%%%@@@@@@@@@%%#++++%%@@@@@@@@@%%%%%%%\n"
        "   %%%%%@@@@@@@@@%%%%%#*%%%@@@@@@@@@@%%%%%%\n"
        "   %%%@@@@@@@@@@@%%%%%%%%%%@@@@@@@@@@@%%%%%\n"
        "   %%@@@@@@@@@@@@%%%%%%%%%%%@@@@@@@@@@@%%%%\n"
        "   %@@@@@@@@@@@@ @%%%%%%%%%%%@@@@@@@@@@%%%%\n"
        "   @@@@@@@@@@@@@   @%%%%%%%%%@@@@@@@@@@@@%%\n";

    string playerName;
    cout << "\n";
    cout << "Ingrese el nombre del jugador: ";
    cin >> playerName;

    int heroPower = 7+(rand() % 3 + 4);
    int enemyPower = rand() % 3 + 5;

    Character hero(playerName, 20, heroPower);
    Enemy enemy("Cerbero", 30, enemyPower, sprite_enemy);
    FinalBoss boss("Hades", 60, 5, 10, 2, sprite_boss);

	vector<Enemy> enemies;
	enemies.push_back(enemy);
	enemies.push_back(boss);

	for (int i = 0; i < enemies.size(); i++) {
		 int win = update(hero, enemies[i]);
         if (win <= 0)
         {
             break;
         }  
	}

    return 0;
}
