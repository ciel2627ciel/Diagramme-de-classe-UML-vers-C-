#include <iostream>
#include <vector>
#include "Conducteur.hpp"
#include "Moto.hpp"
#include "Electrique.hpp"
#include "Thermique.hpp"

/**
 * @file main.cpp
 * @brief Programme de test des classes Conducteur, Moto, Moteur, Electrique et Thermique.
 */

int main() {
    // --- Etape 1 : un conducteur et deux motos (une thermique, une électrique) ---
    Conducteur c1("Dupont", "Alice", 1990);

    Moteur* moteurThermique = new Thermique(45000, 650.0f); // 45kW, 650cm3
    Moto motoThermique(moteurThermique, "Rouge", "Yamaha MT-07", 180);

    Moteur* moteurElectrique = new Electrique(30000, 400.0f); // 30kW, 400V
    Moto motoElectrique(moteurElectrique, "Bleue", "Zero SR/F", 220);

    // --- Etape 2 : attribution des deux motos au conducteur ---
    c1.addMoto(&motoThermique);
    c1.addMoto(&motoElectrique);

    // --- Etape 3 : affichage des informations du conducteur ---
    std::cout << "=== Apres attribution des 2 motos ===" << std::endl;
    std::cout << c1.toString() << std::endl << std::endl;

    // --- Etape 4 : deux nouveaux conducteurs, une nouvelle moto ---
    Conducteur c2("Martin", "Bob", 1985);
    Conducteur c3("Durand", "Chloe", 2000);

    Moteur* moteurThermique2 = new Thermique(60000, 900.0f); // 60kW, 900cm3
    Moto motoThermique2(moteurThermique2, "Noire", "Ducati Monster", 190);

    // Répartition : une moto par conducteur.
    // On retire la moto électrique de c1 pour la donner à c2,
    // on garde la thermique initiale sur c1, et la nouvelle moto va à c3.
    c1.rmMoto(&motoElectrique);
    c2.addMoto(&motoElectrique);
    c3.addMoto(&motoThermique2);

    // --- Etape 5 : affichage des 3 conducteurs ---
    std::cout << "=== Apres repartition (1 moto par conducteur) ===" << std::endl;
    std::cout << c1.toString() << std::endl;
    std::cout << c2.toString() << std::endl;
    std::cout << c3.toString() << std::endl;

    // Les objets Moto sont sur la pile (motoThermique, motoElectrique,
    // motoThermique2) : leurs destructeurs seront appelés automatiquement
    // en fin de main, ce qui libèrera aussi (via composition) les moteurs
    // alloués dynamiquement. Aucun delete manuel n'est donc nécessaire ici.

    return 0;
}
