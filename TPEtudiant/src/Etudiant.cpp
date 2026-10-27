
#include "Etudiant.hpp"
#include <iostream>

// Constructeur par defaut
Etudiant::Etudiant()
    : nom("Inconnu"), cin("000000000000000"),
      note1(0), note2(0), note3(0), filiere(nullptr) {
}

// Constructeur parametre
Etudiant::Etudiant(std::string n, std::string c,
                   double n1, double n2, double n3)
    : nom(n), cin(c), note1(0), note2(0), note3(0),
      filiere(nullptr) {
    setNote1(n1);
    setNote2(n2);
    setNote3(n3);
}

// Getters
std::string Etudiant::getNom() const {
    return nom;
}

std::string Etudiant::getCin() const {
    return cin;
}

double Etudiant::getNote1() const {
    return note1;
}

double Etudiant::getNote2() const {
    return note2;
}

double Etudiant::getNote3() const {
    return note3;
}

// Setters
void Etudiant::setNom(std::string n) {
    nom = n;
}

void Etudiant::setCin(std::string c) {
    cin = c;
}

void Etudiant::setNote1(double n) {
    if (n >= 0 && n <= 20) {
        note1 = n;
    } else {
        std::cerr << "Note 1 invalide : " << n << std::endl;
    }
}

void Etudiant::setNote2(double n) {
    if (n >= 0 && n <= 20) {
        note2 = n;
    } else {
        std::cerr << "Note 2 invalide : " << n << std::endl;
    }
}

void Etudiant::setNote3(double n) {
    if (n >= 0 && n <= 20) {
        note3 = n;
    } else {
        std::cerr << "Note 3 invalide : " << n << std::endl;
    }
}

// Calcul de la moyenne
double Etudiant::calculerMoyenne() const {
    return (note1 + note2 + note3) / 3.0;
}

// Association avec Filiere
void Etudiant::setFiliere(Filiere* f) {
    filiere = f;
}

Filiere* Etudiant::getFiliere() const {
    return filiere;
}
