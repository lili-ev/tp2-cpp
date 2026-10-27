
#include <iostream>
#include "Etudiant.hpp"

int main() {
    // Premier étudiant
    Etudiant e1;
    e1.setNom("Alice Dupont");
    e1.setCin("123456789012345");
    e1.setNote1(15.5);
    e1.setNote2(12.0);
    e1.setNote3(18.5);

    std::cout << "Etudiant 1 : " << e1.getNom() << std::endl;
    std::cout << "Moyenne : " << e1.calculerMoyenne() << std::endl;

    // Test de validation
    std::cout << "\nTest de validation :" << std::endl;
    e1.setNote1(25.0);
    std::cout << "Note1 apres tentative d'erreur : "
              << e1.getNote1() << std::endl;

    // Deuxieme etudiant
    Etudiant e2("Bob Martin", "987654321098765", 10.0, 14.0, 16.0);

    std::cout << "\nEtudiant 2 : " << e2.getNom() << std::endl;
    std::cout << "Moyenne : " << e2.calculerMoyenne() << std::endl;

    return 0;
}

