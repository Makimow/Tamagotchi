#ifndef TAMAGOTCHI_H_INCLUDED
#define TAMAGOTCHI_H_INCLUDED
#include <iostream>
#include <string>
/**
 * @class Tamagotchi
 * @brief Représente un animal virtuel et ses statistiques de vie.
 *
 * Un Tamagotchi possède une réserve d'énergie qui diminue à chaque tour
 * de jeu (voir vivre()). Le joueur peut le nourrir (voir manger()) pour
 * restaurer son énergie, sans jamais dépasser maxEnergie.
 * Si son énergie atteint 0, le Tamagotchi meurt.
 */
class Tamagotchi {
    private :
        int maxEnergie; ///< Capacité maximale de la réserve d'énergie.
        int energie; ///< Énergie actuelle ; le Tamagotchi meurt si elle atteint 0.
        std::string nom; ///< Nom donné par le joueur lors de la création.

    public :
        /**
         * @brief Construit un nouveau Tamagotchi.
         *
         * Le nom est choisi par le joueur. L'énergie maximale (entre 5 et 9)
         * et l'énergie initiale (entre 2 et 5) sont tirées aléatoirement.
         *
         * @param nom_u Nom choisi par le joueur pour ce Tamagotchi.
         */
        Tamagotchi(std::string nom_u);

        /**
         * @brief Affiche l'état courant du Tamagotchi.
         *
         * Le Tamagotchi se présente avec son nom et son humeur,
         * qui dépend de son niveau d'énergie.
         */
        void parler();

        /**
         * @brief Nourrit le Tamagotchi.
         *
         * Augmente l'énergie d'une valeur aléatoire (1 ou 2 points),
         * sans jamais dépasser maxEnergie. Si le Tamagotchi est déjà
         * au maximum, il refuse de manger.
         */
        void manger();

        /**
         * @brief Fait vivre le Tamagotchi pendant un tour de jeu.
         *
         * Consomme 1 point d'énergie. Si l'énergie tombe à 0 ou moins,
         * le Tamagotchi meurt.
         *
         * @return true si le Tamagotchi est toujours en vie,
         *         false s'il vient de mourir.
         */
        bool vivre();
};

#endif // TAMAGOTCHI_H_INCLUDED