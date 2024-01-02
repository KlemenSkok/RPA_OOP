#include <iostream>

using namespace std;

/*
    6. Deklariraj razred Oseba z lastnostmi ime, priimek, letnica_rojstva in metodami za vpis in izpis podatkov. 
    Napiši program, ki deklarira objekta oseba1 in oseba2 in izpiše podatke za mlajšo osebo. 
*/

class Oseba {
    string ime,
    priimek;
    int letnica;

public:
    void vpis();
    void izpis();
    int getLetnica();
};

void Oseba::vpis() {
    cin >> ime;
    cin >> priimek;
    cin.ignore();
    cin >> letnica;
}

void Oseba::izpis() {
    cout << ime << " " << priimek << ", " << letnica << endl;
}

int main() {

    Oseba oseba1, oseba2;
    oseba1.vpis();
    oseba2.vpis();

    if(oseba1.getLetnica() <= oseba2.getLetnica()) {
        oseba1.izpis();
    }
    else oseba2.izpis();

    return 0;
}