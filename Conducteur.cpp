#include "Conducteur.hpp"
#include <sstream>
#include <algorithm>

Conducteur::Conducteur(const std::string& nom, const std::string& prenom, int anneeNaissance)
    : nom(nom), prenom(prenom), anneeNaissance(anneeNaissance) {
}

Conducteur::~Conducteur() {
    // Agrégation : les motos ne sont pas possédées par le conducteur,
    // on ne les détruit donc pas ici (elles restent gérées par leur
    // propriétaire, typiquement le programme principal).
}

std::string Conducteur::getNom() const {
    return nom;
}

std::string Conducteur::getPrenom() const {
    return prenom;
}

std::string Conducteur::getAnneeNaissance() const {
    return std::to_string(anneeNaissance);
}

void Conducteur::addMoto(Moto* newMoto) {
    if (newMoto != nullptr) {
        mesMotos.push_back(newMoto);
    }
}

void Conducteur::rmMoto(Moto* rmMoto) {
    mesMotos.erase(std::remove(mesMotos.begin(), mesMotos.end(), rmMoto), mesMotos.end());
}

std::string Conducteur::toString() const {
    std::ostringstream oss;
    oss << "Conducteur [nom=" << nom
        << ", prenom=" << prenom
        << ", anneeNaissance=" << anneeNaissance
        << ", motos=[";
    for (std::size_t i = 0; i < mesMotos.size(); ++i) {
        if (mesMotos[i] != nullptr) {
            oss << mesMotos[i]->toString();
        }
        if (i + 1 < mesMotos.size()) {
            oss << "; ";
        }
    }
    oss << "]]";
    return oss.str();
}
