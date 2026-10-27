
#include <iostream>
#include "Etudiant.hpp"
#include "Filiere.hpp"

int main() {
    Filiere f1("Informatique");

    Etudiant e1("Alice", "123", 15, 16, 17);
    Etudiant e2("Bob", "456", 12, 14, 16);
    Etudiant e3("Sara", "789", 18, 17, 19);

    f1.inscrireEtudiant(&e1);
    f1.inscrireEtudiant(&e2);
    f1.inscrireEtudiant(&e3);

    f1.afficherTous();

    std::cout << "Nombre d'etudiants : "
              << f1.getNombreEtudiants()
              << std::endl;

    std::cout << "\nRetrait de Bob..." << std::endl;

    f1.retirerEtudiant(&e2);

    f1.afficherTous();

    std::cout << "Nombre d'etudiants : "
              << f1.getNombreEtudiants()
              << std::endl;

    return 0;
}
