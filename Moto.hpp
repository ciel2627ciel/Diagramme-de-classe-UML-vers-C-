#ifndef MOTO_HPP
#define MOTO_HPP

#include <string>
#include "Moteur.hpp"

/**
 * @file Moto.hpp
 * @brief Déclaration de la classe Moto.
 */

/**
 * @class Moto
 * @brief Représente une moto, composée d'un moteur.
 *
 * Relation de composition avec Moteur : la Moto possède et gère
 * entièrement la durée de vie de son moteur (créé dynamiquement en
 * dehors, mais détruit par la Moto).
 */
class Moto {
private:
    int poids;          ///< Poids de la moto en kilogrammes.
    std::string couleur;///< Couleur de la moto.
    std::string nom;    ///< Nom / modèle de la moto.
    Moteur* moteur;      ///< Moteur de la moto (composition, possédé par la Moto).

public:
    /**
     * @brief Construit une moto à partir d'un moteur et d'une couleur.
     * @param moteur Pointeur vers un moteur alloué dynamiquement (Electrique
     *        ou Thermique). La Moto devient propriétaire de ce pointeur et
     *        le détruira dans son destructeur.
     * @param couleur Couleur de la moto.
     * @param nom Nom/modèle de la moto (ajout par rapport au diagramme,
     *        car aucun autre moyen de le renseigner n'était prévu).
     * @param poids Poids en kilogrammes (valeur par défaut modifiable via setPoids).
     */
    Moto(Moteur* moteur, const std::string& couleur,
         const std::string& nom = "", int poids = 0);

    /**
     * @brief Destructeur : libère le moteur possédé par la moto.
     */
    ~Moto();

    // La Moto possède un pointeur qu'elle seule doit détruire : on interdit
    // la copie pour éviter une double destruction (fuite / double free),
    // conformément à la consigne "attention aux fuites mémoire".
    Moto(const Moto&) = delete;
    Moto& operator=(const Moto&) = delete;

    /**
     * @brief Récupère le poids de la moto.
     * @return Le poids en kilogrammes.
     */
    int getPoids() const;

    /**
     * @brief Modifie le poids de la moto.
     * @param poids Nouveau poids en kilogrammes.
     */
    void setPoids(int poids);

    /**
     * @brief Récupère la couleur de la moto.
     * @return La couleur.
     */
    std::string getCouleur() const;

    /**
     * @brief Récupère le nom/modèle de la moto.
     * @return Le nom.
     */
    std::string getNom() const;

    /**
     * @brief Modifie le nom/modèle de la moto.
     * @param nom Nouveau nom.
     */
    void setNom(const std::string& nom);

    /**
     * @brief Récupère le moteur de la moto.
     * @return Pointeur vers le moteur (toujours possédé par la Moto).
     */
    Moteur* getMoteur() const;

    /**
     * @brief Calcule l'accélération théorique de la moto à une vitesse
     *        initiale de 50 km/h.
     *
     * Formule : a = P / (m * v), avec P la puissance du moteur (W),
     * m le poids de la moto (kg) et v = 50 km/h convertie en m/s.
     *
     * @return L'accélération théorique en m/s².
     */
    float getAcceleration() const;

    /**
     * @brief Renvoie une chaîne de caractères décrivant la moto (et son moteur).
     * @return Description lisible de la moto.
     */
    std::string toString() const;
};

#endif // MOTO_HPP
