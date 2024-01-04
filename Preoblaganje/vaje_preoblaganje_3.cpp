#include <iostream>
#include <cmath>

using namespace std;

/*
VAJE IZ PREOBLOZENIH OPERATORJEV
    Naloga 3:

    Napiši program, ki definira razred Krog z lastnostjo radij ter metodo za vnos,metodo izračun ploščine in metodo za izračun obsega kroga. 
    Razredu dodaj še preobložene operatorje:
     + (sešteje  radija dveh krogov),
     - (radij manjšega kroga odšteje od radija večjega kroga),
     == (primerja enakost radijev dveh krogov) 
    ter operator predinkrementa, ki naj poveča radij kroga za 10. 
    V glavnem programu deklariraj dva objekta razreda Krog ter kliči vse metode in operatorje razreda Krog.
*/

class Krog {
    float radij;

public:
    void vnos();
    void izpis();
    float ploscina();
    float obseg();
    Krog operator+(Krog);
    Krog operator-(Krog);
    bool operator==(Krog);
    Krog operator++(); //*brez argumentov za predinkrement!!!
};

Krog Krog::operator++() {
    this->radij += 10;
    return *this;
}
bool Krog::operator==(Krog b) {
    if(this->radij == b.radij)
        return true;
    return false;
}
Krog Krog::operator+(Krog b) {
    Krog c;
    c.radij = this->radij + b.radij;
    return c;
}
Krog Krog::operator-(Krog b) {
    Krog c;
    if(this->radij > b.radij)
        c.radij = this->radij - b.radij;
    else c.radij = b.radij - this->radij;
    return c;
}
void Krog::izpis() { cout << "Radij kroga: " << this->radij << endl; }
void Krog::vnos() {
    cout << "Vnesi polmer kroga: ";
    cin >> radij;
}
float Krog::ploscina() { return M_PI * radij*radij; }
float Krog::obseg() { return 2 * M_PI * radij; }

int main() {

    Krog a, b;
    a.vnos(); b.vnos();
    ++a;
    a.izpis();

    cout << "Ploscina kroga a: " << a.ploscina() << "\nObseg kroga a: " << a.obseg() << endl;
    if(a == b) cout << "Kroga imata enak radij\n";
    else cout << "Kroga nimata enakega radija\n";

    a = a+b;
    b = b-a;
    a.izpis();
    b.izpis();



    return 0;
}