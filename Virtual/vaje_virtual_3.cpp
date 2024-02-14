#include <iostream>

using namespace std;

/*
    3. Napišite matematični program, ki vsebuje osnovni razred Lik. 
    To naj bo abstraktni razred, ki ima virtualne funkcije za obseg in ploščino lika. 
    Iz njega izpelji prave razrede za like kot so kvadrat, krog, romb.
*/

class Lik {

public:
    virtual float obseg() = 0;
    virtual float ploscina() = 0;
    virtual void vpis() = 0;
    virtual void izpis() = 0;
};

class Kvadrat : public Lik {
    float a;

public:
    void vpis();
    void izpis();
    float obseg();
    float ploscina();
};
void Kvadrat::vpis() { cout << "Vnesi a: "; cin >> a; }
void Kvadrat::izpis() { cout << "a: " << a << endl; }
float Kvadrat::obseg() { return 4 * a; }
float Kvadrat::ploscina() { return a*a; }



class Krog : public Lik {
    float r;

public:
    void vpis();
    void izpis();
    float obseg();
    float ploscina();
};
void Krog::vpis() { cout << "Vnesi r: "; cin >> r; }
void Krog::izpis() { cout << "r: " << r << endl; }
float Krog::obseg() { return 2 * 3.141 * r; }
float Krog::ploscina() { return 3.141 * r*r; }


class Romb : public Kvadrat {
    float a;
};


int main() {

    Kvadrat x;
    x.vpis();
    printf("Obseg: %f\nPloscina: %f\n\n", x.obseg(), x.ploscina());
    
    Krog y; y.vpis();
    printf("Obseg: %f\nPloscina: %f\n\n", y.obseg(), y.ploscina());

    Romb z; z.vpis();
    printf("Obseg: %f\nPloscina: %f\n\n", z.obseg(), z.ploscina());

    return 0;
}