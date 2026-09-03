#include "Moteur.hpp"
#include <sstream>

Moteur::Moteur(int puissance) : puissance(puissance) {
}

Moteur::~Moteur() {
    // Rien à libérer ici : aucune ressource allouée dynamiquement dans cette classe.
}

int Moteur::getPuissance() const {
    return puissance;
}

void Moteur::setPuissance(int puissance) {
    this->puissance = puissance;
}

std::string Moteur::toString() const {
    std::ostringstream oss;
    oss << "Moteur [puissance=" << puissance << "W]";
    return oss.str();
}
