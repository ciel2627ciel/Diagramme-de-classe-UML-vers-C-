#ifndef MOTEUR_HPP
#define MOTEUR_HPP

#include <string>

/**
 * @file Moteur.hpp
 * @brief Déclaration de la classe Moteur.
 */

/**
 * @class Moteur
 * @brief Classe de base représentant un moteur générique.
 *
 * Sert de classe mère aux moteurs Electrique et Thermique.
 * Toutes les motos possèdent un moteur (relation de composition : le moteur
 * n'existe pas indépendamment de sa moto).
 */
class Moteur {
protected:
    int puissance; ///< Puissance du moteur en watts.

public:
    /**
     * @brief Construit un moteur avec une puissance donnée.
     * @param puissance Puissance en watts.
     */
    explicit Moteur(int puissance = 0);

    /**
     * @brief Destructeur virtuel (nécessaire car la classe est polymorphe).
     */
    virtual ~Moteur();

    /**
     * @brief Récupère la puissance du moteur.
     * @return La puissance en watts.
     */
    int getPuissance() const;

    /**
     * @brief Modifie la puissance du moteur.
     * @param puissance Nouvelle puissance en watts.
     */
    void setPuissance(int puissance);

    /**
     * @brief Renvoie une chaîne de caractères décrivant le moteur.
     * @return Description lisible du moteur.
     */
    virtual std::string toString() const;
};

#endif // MOTEUR_HPP
