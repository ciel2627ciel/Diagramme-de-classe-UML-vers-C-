#include "Thermique.hpp"
#include <sstream>

Thermique::Thermique(int puissance, float cylindree)
    : Moteur(puissance), cylindree(cylindree) {
}

Thermique::~Thermique() {
    // Rien à libérer ici : aucune ressource allouée dynamiquement dans cette classe.
}

float Thermique::getCylindree() const {
    return cylindree;
}

void Thermique::setCylindree(float newCylindree) {
    this->cylindree = newCylindree;
}

std::string Thermique::toString() const {
    std::ostringstream oss;
    oss << "Moteur thermique [puissance=" << puissance
        << "W, cylindree=" << cylindree << "cm3]";
    return oss.str();
}
