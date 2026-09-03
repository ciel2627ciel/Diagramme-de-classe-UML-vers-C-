#ifndef CONDUCTEUR_HPP
#define CONDUCTEUR_HPP

#include <string>
#include <vector>
#include "Moto.hpp"

/**
 * @file Conducteur.hpp
 * @brief Déclaration de la classe Conducteur.
 */

/**
 * @class Conducteur
 * @brief Représente un conducteur possédant zéro ou plusieurs motos.
 *
 * Relation d'agrégation avec Moto : le Conducteur référence des motos
 * mais n'est pas responsable de leur destruction (les motos peuvent
 * exister indépendamment et être réattribuées à un autre conducteur).
 */
class Conducteur {
private:
    std::string nom;             ///< Nom de famille du conducteur.
    std::string prenom;          ///< Prénom du conducteur.
    int anneeNaissance;          ///< Année de naissance du conducteur.
    std::vector<Moto*> mesMotos; ///< Motos possédées (agrégation, non détruites ici).

public:
    /**
     * @brief Construit un conducteur.
     * @param nom Nom de famille.
     * @param prenom Prénom.
     * @param anneeNaissance Année de naissance.
     */
    Conducteur(const std::string& nom, const std::string& prenom, int anneeNaissance);

    /**
     * @brief Destructeur. Ne détruit pas les motos (agrégation : elles ne
     *        sont pas possédées par le conducteur).
     */
    ~Conducteur();

    /**
     * @brief Récupère le nom du conducteur.
     * @return Le nom.
     */
    std::string getNom() const;

    /**
     * @brief Récupère le prénom du conducteur.
     * @return Le prénom.
     */
    std::string getPrenom() const;

    /**
     * @brief Récupère l'année de naissance du conducteur.
     * @return L'année de naissance, sous forme de chaîne (tel que défini
     *         dans le diagramme de classe).
     */
    std::string getAnneeNaissance() const;

    /**
     * @brief Ajoute une moto au conducteur.
     * @param newMoto Pointeur vers la moto à ajouter (non possédée).
     */
    void addMoto(Moto* newMoto);

    /**
     * @brief Retire une moto de la liste du conducteur (ne la détruit pas).
     * @param rmMoto Pointeur vers la moto à retirer.
     */
    void rmMoto(Moto* rmMoto);

    /**
     * @brief Renvoie une chaîne de caractères décrivant le conducteur et
     *        ses motos.
     * @return Description lisible du conducteur.
     */
    std::string toString() const;
};

#endif // CONDUCTEUR_HPP
