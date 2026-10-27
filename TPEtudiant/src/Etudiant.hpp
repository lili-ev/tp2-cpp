#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

#include <string>

class Filiere;

class Etudiant {
private:
    std::string nom;
    std::string cin;
    double note1, note2, note3;
    Filiere* filiere;

public:
    Etudiant();
    Etudiant(std::string n, std::string c, double n1, double n2, double n3);

    std::string getNom() const;
    std::string getCin() const;
    double getNote1() const;
    double getNote2() const;
    double getNote3() const;

    void setNom(std::string n);
    void setCin(std::string c);
    void setNote1(double n);
    void setNote2(double n);
    void setNote3(double n);

    double calculerMoyenne() const;

    void setFiliere(Filiere* f);
    Filiere* getFiliere() const;
};

#endif
