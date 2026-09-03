#include "Moto.hpp"
#include <sstream>
#include <limits>

namespace {
    /// Vitesse initiale de référence pour le calcul de l'accélération théorique.
    constexpr float VITESSE_KMH = 50.0f;
    /// Conversion km/h -> m/s.
    constexpr float KMH_TO_MS = 1.0f / 3.6f;
}

Moto::Moto(Moteur* moteur, const std::string& couleur,
           const std::string& nom, int poids)
    : poids(poids), couleur(couleur), nom(nom), moteur(moteur) {
}

Moto::~Moto() {
    delete moteur; // La Moto est propriétaire de son moteur (composition).
}

int Moto::getPoids() const {
    return poids;
}

void Moto::setPoids(int poids) {
    this->poids = poids;
}

std::string Moto::getCouleur() const {
    return couleur;
}

std::string Moto::getNom() const {
    return nom;
}

void Moto::setNom(const std::string& nom) {
    this->nom = nom;
}

Moteur* Moto::getMoteur() const {
    return moteur;
}

float Moto::getAcceleration() const {
    if (moteur == nullptr || poids <= 0) {
        return 0.0f;
    }
    float vitesseMs = VITESSE_KMH * KMH_TO_MS;
    float puissance = static_cast<float>(moteur->getPuissance());
    return puissance / (static_cast<float>(poids) * vitesseMs);
}

std::string Moto::toString() const {
    std::ostringstream oss;
    oss << "Moto [nom=" << nom
        << ", couleur=" << couleur
        << ", poids=" << poids << "kg"
        << ", acceleration@50km/h=" << getAcceleration() << "m/s2"
        << ", " << (moteur != nullptr ? moteur->toString() : "sans moteur")
        << "]";
    return oss.str();
}
