#include <iostream>

using namespace std;

/*
    9. Deklariraj razred Jadrnica z lastnostmi: ime jadrnice, dolžina in hitrost v vozlih in metodo za vnos lastnosti. 
    Deklariraj razred Motorni_coln z lastnostmi: ime, moč motorja in hitrost v vozlih ter metodo za vnos lastnosti.
    Deklariraj razred Jadrnica_z_motorjem, ki deduje lastnosti in metode obeh razredov ter vsebuje še metodo, ki izračuna, 
    koliko znaša razlika med jadralno hitrostjo ter hitrostjo motornega pogona. 
*/

class Jadrnica {
    string ime;

protected:
    int dolzina, hitrost;
public:
    void vnos();
};

void Jadrnica::vnos() {
    cout << "lastnosti za jadrnico: \n";
    cin >> dolzina >> hitrost;
}

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+
class Motorni_coln {
    string ime;
    
protected:
    int moc_motorja, hitrost;
public:
    void vnos();
};

void Motorni_coln::vnos() {
    cout << "Lastnosti za motorni coln: \n";
    cin >> moc_motorja >> hitrost;
}

//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+
class Jadrnica_z_motorjem : public Motorni_coln, public Jadrnica {
    string ime;

public: 
    void vnos();
    int razlikaHitrosti();
};

void Jadrnica_z_motorjem::vnos() {
    cout << "Lastnosti za jadrnico z motorjem: \n";
    Jadrnica::vnos();
    Motorni_coln::vnos();
}

int Jadrnica_z_motorjem::razlikaHitrosti() {
    return Motorni_coln::hitrost - Jadrnica::hitrost;
}

int main() {

    Jadrnica_z_motorjem jadrnica;
    jadrnica.vnos();
    cout << "Razlika hitrosti: " << jadrnica.razlikaHitrosti() << endl; 

    return 0;
}