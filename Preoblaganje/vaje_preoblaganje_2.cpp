#include <iostream>
#include <cmath>

using namespace std;

/*
VAJE IZ PREOBLOZENIH METOD
    Naloga 2:

    Napiši program, ki deklarira razred Tocka, ki naj vsebuje lastnosti x in y tipa double, 
    konstruktor, destruktor ter tri preobložene metode Razdalja(), ki naj računajo izpišejo razdaljo med dvema točkama v ravnini. 
    - Prva metoda Razdalja naj ne vsebuje vhodnih podatkov in naj koordinate druge točke bere s tipkovnice. 
    - Druga metoda Razdalja naj vsebuje dva vhodna podatka tipa double, ki predstavljata drugo točko v ravnini. 
    - Tretja metoda Razdalja naj vsebuje za vhodni podatek objekt razreda Tocka. 
    V glavnem programu ustvari objekt razreda Tocka ter klici vse njegove metode.
*/

class Tocka {
    double x, y;

public:
    Tocka();
    ~Tocka() {}
    void Razdalja();
    void Razdalja(double,double);
    void Razdalja(Tocka);
    double getX();
    double getY();
    void vpis();
};  

void Tocka::Razdalja() {
    double x, y;
    cout << "Vnesite koordinate druge tocke: ";
    cin >> x >> y;
    double razdalja = sqrt((this->x-x)*(this->x-x) + (this->y-y)*(this->y-y));
    cout << "Razdalja me tockama: " << razdalja << endl;
}
void Tocka::Razdalja(double x, double y) {
    double razdalja = sqrt((this->x-x)*(this->x-x) + (this->y-y)*(this->y-y));
    cout << "Razdalja me tockama: " << razdalja << endl;
}
void Tocka::Razdalja(Tocka b) {
    double razdalja = sqrt((this->x-b.getX())*(this->x-b.getX()) + (this->y-b.getY())*(this->y-b.getY()));
    cout << "Razdalja me tockama: " << razdalja << endl;
}

double Tocka::getX() { return this->x; }
double Tocka::getY() { return this->y; }
Tocka::Tocka() { cout << "Vnesi x in y: "; cin >> this->x >> this->y; }

int main() {

    Tocka a;
    a.Razdalja();
    double x,y;
    cout << "Vnesi x in y: ";
    cin >> x >> y;
    a.Razdalja(x,y);
    Tocka b;
    a.Razdalja(b);


    return 0;
}