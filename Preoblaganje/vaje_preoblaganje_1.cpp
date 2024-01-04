#include <iostream>

using namespace std;

/*
VAJE IZ PREOBLOZENIH METOD
    Naloga 1:

    Napiši program, ki deklarira razred Racunanje, ki naj vsebuje realno število a, konstruktor, destruktor ter tri preobložene metode Racun (). 
    - Prva metoda Racun naj ne vsebuje vhodnih podatkov in naj vrne kvadrat števila a. 
    - Druga metoda Racun naj vsebuje vhodni podatek b, in naj vrne zmnožek a in b. 
    - Tretja metoda naj vsebuje tudi en vhodni podatek n in naj izračuna in vrne potenco an. 
    V glavnem programu ustvari objekt razreda Racunanje ter klici vse njegove metode.
*/

class Racunanje {
    float a;

public:
    Racunanje() {}
    ~Racunanje() {}
    float Racun();
    float Racun(float);
    float Racun(int);
    void vpis();
};

void Racunanje::vpis() {
    cin >> a;
}

float Racunanje::Racun() {
    return a*a;
}
float Racunanje::Racun(float b) {
    return a*b;
}
float Racunanje::Racun(int n) {
    if(n == 0)
        return 1;
    return a * Racunanje::Racun(n-1);
}

int main() {

    Racunanje objekt;
    objekt.vpis();

    cout << "Kvadrat stevila a: " << objekt.Racun() << endl;
    float b;
    cin >> b;
    cout << "a*b = " << objekt.Racun(b) << endl;
    int n;
    cin >> n;
    cout << "a^n = " << objekt.Racun(n) << endl;

    return 0;
}