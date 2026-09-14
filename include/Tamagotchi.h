#ifndef TAMAGOTCHI_H_INCLUDED
#define TAMAGOTCHI_H_INCLUDED
#include <iostream>
#include <string>
/**
 * @brief Représente l'animal virtuel et ses statistiques.
 */
class Tamagotchi {
    /**
     * @brief Diminue la faim de 10 points.
     * @param quantite la quantite de nourriture donnee
     */
    private :
        int maxEnergie;
        int energie;
        std::string nom;

    public :
        Tamagotchi(std::string nom_u);
        void parler();
        void manger();
        bool vivre();
};

#endif // TAMAGOTCHI_H_INCLUDED