#include "Electrique.hpp"
#include <sstream>

Electrique::Electrique(int puissance, float tensionMax)
    : Moteur(puissance), tensionMax(tensionMax) {
}

Electrique::~Electrique() {
    // Rien à libérer ici : aucune ressource allouée dynamiquement dans cette classe.
}

float Electrique::getTensionMax() const {
    return tensionMax;
}

void Electrique::setTensionMax(float tensionMax) {
    this->tensionMax = tensionMax;
}

std::string Electrique::toString() const {
    std::ostringstream oss;
    oss << "Moteur electrique [puissance=" << puissance
        << "W, tensionMax=" << tensionMax << "V]";
    return oss.str();
}
