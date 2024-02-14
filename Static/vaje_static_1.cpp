#include <iostream>
#include <cmath>

using namespace std;

/*
        1. Napišite program v C++, ki deklarira razred Valj s privatnimi celoštevilčnimi lastnostmi r in v.
    Razred na vsebuje privzeti (obe lastnosti postavi na 0) konstruktor, kopirni konstruktor, destruktor, 
    metodo za branje obeh lastnosti s tipkovnice (ta naj ponovi branje, v koliko uporabnik vnese števila <0), 
    metodi za izračun površine in prostornine valja. 

    Razred naj vsebuje še preobložene operatorje: 
    - != (vrne logično 1, če sta prostornini valjev različni), 
    - operator += (poveča obe lastnosti valja za velikost vhodnega parametra n) ter 
    - operator -.  Slednji naj deluje tako, da naj najprej preveri radij obeh valjev. 
    kolikor je radij različen, naj vrne objekt razreda Valj, ki ima obe lastnosti enaki -1. 
    Če sta radija enaka, pa naj operator – vrne objekt razreda Valj, katerega radij je enak radiju trenutnega objekta, 
    višina pa naj se izračuna kot absolutna vrednost razlike višin obeh valjev. 

    V glavnem programu omogočite vnos lastnosti objektov a in b. 

    Za objekt a kličite operator a+=3, ter izračunajte razliko med objema objektoma.  
    Nato še izvedite primerjavo med objektoma a in b. 
    Če sta objekta enaka, naj program izpiše ustrezno sporočilo, 
    če pa ne, pa naj program izpiše kakšna je razlika med površinama obeh objektov. 
    Ob koncu programa še sprostite oba objekta iz pomnilnika.
*/

class Valj {
    int r, v;

public:
    Valj();
    Valj(const Valj&);
    ~Valj();
    void vpis();
    int prostornina();
    int povrsina();
    bool operator!=(Valj);
    void operator+=(int);
    Valj operator-(Valj);
};

Valj::Valj() { r = v = 0; }
Valj::Valj(const Valj &a) {
    this->r = a.r;
    this->v = a.v;
}
Valj::~Valj() { /*cout << "Klican destruktor.\n";*/ }

void Valj::vpis() { 
    cout << "Vnesi r: ";
    do { cin >> r; } while(r < 0);
    cout << "Vnesi v: ";
    do { cin >> v; } while(v < 0);
}

int Valj::prostornina() { return M_PI * r*r * v; }
int Valj::povrsina() { return (M_PI * r*r)*2 + 2*M_PI*r*v; }

bool Valj::operator!=(Valj a) { return this->prostornina() != a.prostornina(); }
void Valj::operator+=(int n) { r += n; v += n; }
Valj Valj::operator-(Valj a) {
    if(*this != a) {
        a.r = -1; a.v = -1;
        return a;
    }
    a.r = this->r;
    a.v = abs(this->v - a.v);
    return a;
}

int main() {

    Valj a, b;
    a.vpis(); b.vpis();

    a += 3;
    a = a-b;
    
    if(a != b) {
        cout << "Objekta nista enaka. \nRazlika med povrsinama: " << abs(a.povrsina() - b.povrsina()) << endl;
    }
    else
        cout << "Objekta sta enaka\n";


    return 0;
}