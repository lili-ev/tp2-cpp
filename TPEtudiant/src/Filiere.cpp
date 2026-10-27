
#include "Filiere.hpp"
#include "Etudiant.hpp"

#include <iostream>
#include <algorithm>

Filiere::Filiere(std::string nom)
    : nomFiliere(nom) {
}

Filiere::~Filiere() {
    // La filiere ne detruit pas les etudiants.
    for (auto* e : etudiants) {
        if (e != nullptr && e->getFiliere() == this) {
            e->setFiliere(nullptr);
        }
    }

    etudiants.clear();
}

void Filiere::inscrireEtudiant(Etudiant* e) {
    if (e == nullptr) {
        std::cerr << "Etudiant invalide." << std::endl;
        return;
    }

    // Eviter d'inscrire deux fois le meme etudiant
    if (std::find(etudiants.begin(), etudiants.end(), e)
        != etudiants.end()) {
        std::cerr << "Etudiant deja inscrit." << std::endl;
        return;
    }

    // Un etudiant ne peut appartenir qu'a une filiere
    if (e->getFiliere() != nullptr
        && e->getFiliere() != this) {
        std::cerr << "Etudiant deja inscrit dans une autre filiere."
                  << std::endl;
        return;
    }

    etudiants.push_back(e);
    e->setFiliere(this);
}

void Filiere::retirerEtudiant(Etudiant* e) {
    auto it = std::find(etudiants.begin(), etudiants.end(), e);

    if (it != etudiants.end()) {
        if (e != nullptr && e->getFiliere() == this) {
            e->setFiliere(nullptr);
        }

        etudiants.erase(it);
    }
}

int Filiere::getNombreEtudiants() const {
    return static_cast<int>(etudiants.size());
}

std::string Filiere::getNomFiliere() const {
    return nomFiliere;
}

void Filiere::afficherTous() const {
    std::cout << "Etudiants de la filiere "
              << nomFiliere << ":" << std::endl;

    if (etudiants.empty()) {
        std::cout << "Aucun etudiant inscrit." << std::endl;
        return;
    }

    for (const auto* e : etudiants) {
        if (e != nullptr) {
            std::cout << " - " << e->getNom()
                      << " (Moyenne : "
                      << e->calculerMoyenne()
                      << ")" << std::endl;
        }
    }
}
