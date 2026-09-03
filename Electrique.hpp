#ifndef ELECTRIQUE_HPP
#define ELECTRIQUE_HPP

#include "Moteur.hpp"

/**
 * @file Electrique.hpp
 * @brief Déclaration de la classe Electrique.
 */

/**
 * @class Electrique
 * @brief Moteur électrique, spécialisation de Moteur.
 */
class Electrique : public Moteur {
private:
    float tensionMax; ///< Tension maximale supportée par le moteur, en volts.

public:
    /**
     * @brief Construit un moteur électrique.
     * @param puissance Puissance en watts.
     * @param tensionMax Tension maximale en volts.
     */
    Electrique(int puissance, float tensionMax);

    /**
     * @brief Destructeur.
     */
    ~Electrique() override;

    /**
     * @brief Récupère la tension maximale.
     * @return La tension maximale en volts.
     */
    float getTensionMax() const;

    /**
     * @brief Modifie la tension maximale.
     * @param tensionMax Nouvelle tension maximale en volts.
     */
    void setTensionMax(float tensionMax);

    /**
     * @brief Renvoie une chaîne de caractères décrivant le moteur électrique.
     * @return Description lisible du moteur.
     */
    std::string toString() const override;
};

#endif // ELECTRIQUE_HPP
