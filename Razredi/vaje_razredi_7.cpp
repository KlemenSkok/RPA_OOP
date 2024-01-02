#include <iostream>

using namespace std;

/*
    7. Deklariraj razred denarnica, ki omogoča operacije: dvig, vlogo in ugotavljanje stanja. 
    Začetna vrednost se postavi s konstruktorjem.
*/

class Denarnica {
    float stanje;

public:
    Denarnica(float);
    void dvig(float);
    void vloga(float);
    float getStanje();
};

void Denarnica::dvig(float vrednost) {
    this->stanje -= vrednost;
}

void Denarnica::vloga(float vrednost) {
    this->stanje += vrednost;
}

float Denarnica::getStanje() {
    return this->stanje;
}

Denarnica::Denarnica(float stanje) {
    this->stanje = stanje;
}

int main() {

    float pare;
    cin >> pare;
    Denarnica tosl(pare);
    cin >> pare;
    tosl.vloga(pare);
    cin >> pare;
    tosl.dvig(pare);
    
    cout << "Stanje: " << tosl.getStanje() << "EUR\n";

    return 0;
}