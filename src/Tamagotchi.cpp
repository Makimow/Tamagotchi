/**
 * @file Tamagotchi.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "Tamagotchi.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Construct a new Tamagotchi:: Tamagotchi object
 * 
 * @param nom_u 
 */
Tamagotchi::Tamagotchi(string nom_u) {
    nom = nom_u;
    maxEnergie = rand()%5 + 5;
    energie = rand()%4 + 2;
}

/**
 * @brief 
 * 
 */
void Tamagotchi::parler() {
    string etat;
    if (energie > 5) {
        etat = "heureux";
    } else {
        etat = "affame";
    }
    cout << "Bonjour, je m'appelle " << nom << ", je suis actuellement " << etat << " mon energie est de : " << energie << " et mon energie max est de : " << maxEnergie << endl;
}

/**
 * @brief 
 * 
 */
void Tamagotchi::manger() {
    int augmentation = rand()%2 + 1;
    if (energie == maxEnergie) {
        cout << "Arretez de me gaver monsieur je ne suis pas un canard la veille de Noël !!! *emoji pas content*";
    } else {
        energie += augmentation;
        cout << "Mmmmh merci pour la bonne sousoupe monsieur" << endl;
        if (energie > maxEnergie) {
            energie = maxEnergie;
        }
    }
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Tamagotchi::vivre() {
    if (energie <= 0) {
        cout << nom << " : Je meurs !!! *emoji tete de mort*" << endl;
        return false;
    } else {
        cout << nom << " : Je vie un jour de plus ! *emoji lunnettes de soleil*" << endl;
        energie -= 1;
        return true;
    }
}