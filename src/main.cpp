/**
 * @file main.cpp
 * @author Antonin Hornoy (hornoyantonin@gmail.com)
 * @brief Point d'entrée du jeu Tamagotchi en mode console.
 * @version 0.5
 * @date 2026-09-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <iostream>
#include "Tamagotchi.h"
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Fonction principale du jeu.
 * 
 * Déroulement d'une partie :
 * 1. Le joueur choisit combien de Tamagotchis créer et leur donne un nom.
 * 2. Chaque tour de jeu, le joueur choisit un Tamagotchi et une action
 *    (le nourrir ou lui parler).
 * 3. À la fin de chaque tour, tous les Tamagotchis perdent 1 point
 *    d'énergie (voir Tamagotchi::vivre()).
 * 4. La partie se termine quand un Tamagotchi meurt.
 * 
 * @return 0 si le programme s'est terminé normalement.
 */
int main() {
    int n;
    int choixTama;
    int choixAction;
    string nom;
    vector<Tamagotchi> v;
    bool vivants = true;
    bool fini = false;
    cout << "Bienvenue dans le jeu des Tamagotchis !" << endl;
    cout << "Veuillez entrer le nombre de Tamagochis que vous voulez creer : ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Comment voulez vous appeler le Tamagotchis Numero " << i << " ? : ";
        cin >> nom;
        v.push_back(Tamagotchi(nom));
    }
    while (vivants == true) {
        fini = false;
        while (!fini) {
            cout << "Choisissez sur quel tamagotchi (ex : 1 pour le tamagotchi numero 1) vous voulez effectuer une action : " << endl;
            cin >> choixTama;
            if (choixTama > n) {
                cout << "Ce tamagotchi n'existe pas, voulez reessayer" << endl;
            } else {
                cout << "Voulez vous le nourir (1) ou simplement parler (2) ? : " << endl;
                cin >> choixAction;
                switch (choixAction)
                {
                case 1 :
                    v[choixTama - 1].manger();
                    fini = true;
                    break;
                case 2 :
                    v[choixTama - 1].parler();
                    break;
                default:
                    cout << "Mauvaise valeure entree, veuillez reessayer" << endl;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            vivants = v[i-1].vivre();
        }
    }
    return 0;
}