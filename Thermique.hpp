#ifndef THERMIQUE_HPP
#define THERMIQUE_HPP

#include "Moteur.hpp"

/**
 * @file Thermique.hpp
 * @brief Déclaration de la classe Thermique.
 */

/**
 * @class Thermique
 * @brief Moteur thermique, spécialisation de Moteur.
 */
class Thermique : public Moteur {
private:
    float cylindree; ///< Cylindrée du moteur, en cm³.

public:
    /**
     * @brief Construit un moteur thermique.
     * @param puissance Puissance en watts.
     * @param cylindree Cylindrée en cm³.
     */
    Thermique(int puissance, float cylindree);

    /**
     * @brief Destructeur.
     */
    ~Thermique() override;

    /**
     * @brief Récupère la cylindrée du moteur.
     * @return La cylindrée en cm³.
     */
    float getCylindree() const;

    /**
     * @brief Modifie la cylindrée du moteur.
     * @param newCylindree Nouvelle cylindrée en cm³.
     */
    void setCylindree(float newCylindree);

    /**
     * @brief Renvoie une chaîne de caractères décrivant le moteur thermique.
     * @return Description lisible du moteur.
     */
    std::string toString() const override;
};

#endif // THERMIQUE_HPP
