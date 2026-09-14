/**
 * @file Tamagotchi.cpp
 * @author Antonin Hornoy (hornoyantonin@gmail.com)
 * @brief Implémentation de la classe Tamagotchi.
 * @version 0.5
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
 * @brief Construit un nouveau Tamagotchi.
 * 
 * @param nom_u Nom choisi par le joueur pour ce Tamagotchi.
 */
Tamagotchi::Tamagotchi(string nom_u) {
    nom = nom_u;
    maxEnergie = rand()%5 + 5; ///< Énergie max aléatoire entre 5 et 9.
    energie = rand()%4 + 2; ///< Énergie initiale aléatoire entre 2 et 5.
}

/**
 * @brief Affiche l'état courant du Tamagotchi.
 * 
 * Le Tamagotchi est "heureux" si son énergie est strictement supérieure
 * à 5, sinon il est "affamé". Il affiche aussi ses niveaux d'énergie.
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
 * @brief Nourrit le Tamagotchi.
 * 
 * Augmente l'énergie d'une valeur aléatoire entre 1 et 2 points.
 * Si l'énergie dépasse maxEnergie, elle est plafonnée à cette valeur.
 * Rien ne se passe si le Tamagotchi est déjà rassasié.
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
 * @brief Fait vivre le Tamagotchi pendant un tour de jeu.
 * 
 * Consomme 1 point d'énergie et annonce que le Tamagotchi survit.
 * Si l'énergie est déjà à 0 ou moins, le Tamagotchi meurt.
 * 
 * @return true si le Tamagotchi est toujours en vie,
 *         false s'il vient de mourir.
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