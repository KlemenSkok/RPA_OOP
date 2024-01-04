#include <iostream>

using namespace std;

/*
    Naloga 5:

    Deklariraj razred Cas, ki naj vsebuje lastnosti ura, minuta in sekunda. 
    Definiraj metode za vnos  in izpis vseh lastnosti razreda ter preobloži operatorje +,-,>,<,==, ++ ter --  tako, 
    da bodo znali pravilno računati s časovnimi vrednostmi. 
*/

class Cas {
    unsigned ura,
    minuta,
    sekunda;

public:
    void vnos();
    void izpis();
    Cas operator+(Cas);
    Cas operator-(Cas);
    bool operator>(Cas);
    bool operator<(Cas);
    bool operator==(Cas);
    Cas operator++(int x);
    Cas operator--(int x);
};

void Cas::vnos() {
    cout << "Vnesi cas (h,m,s): ";
    cin >> ura >> minuta >> sekunda;
}
void Cas::izpis() { 
    cout << ura << ":" << minuta << ":" << sekunda << endl; 
}

Cas Cas::operator+(Cas b) {
    Cas c;
    c.ura = this->ura + b.ura;
    c.minuta = this->minuta + b.minuta;
    c.sekunda = this->sekunda + b.sekunda;
    //TODO----------------------------------------------
}

int main() {



    return 0;
}