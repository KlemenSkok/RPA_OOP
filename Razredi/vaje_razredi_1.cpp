#include <iostream>

using namespace std;

/*
    1. Napišite razred Dijak_matura, ko naj hrani podatke o uspehu dijaka na maturi 
    (ime_dijaka, SLO, ocena_SLO, MAT, ocena_MAT, ANG, ocena_ANG, Izb_1, ocena_Izb_1, Izb_2, ocena_Izb_2). 
    Vsi podatki naj bodo zaščiteni in dostop do njih naj bo izključno preko funkcij.
    Metoda, ki vrne zaupne podatke (ocene), naj ima še en parameter (ključ) in naj vrne podatke le v primeru, če je ključ pravilen. 
*/
class Dijak_matura {
        string ime_dijaka, kljuc;
        int SLO, ocena_SLO,
        MAT, ocena_MAT,
        ANG, ocena_ANG,
        Izb_1, ocena_Izb_1,
        Izb_2, ocena_Izb_2;
    public:
        void vpis_ocen();
        void izpis_ocen(string kljuc);
};

void Dijak_matura::vpis_ocen() {
    cin >> SLO >> ocena_SLO >> MAT >> ocena_MAT >> ANG >> ocena_ANG >> Izb_1 >> ocena_Izb_1 >> Izb_2 >> ocena_Izb_2;
}

void Dijak_matura::izpis_ocen(string kljuc) {
    if(this->kljuc == kljuc) {
        cout << "SLO: " << ocena_SLO << "\nMAT: " << ocena_MAT << "\nANG: " << ocena_ANG << "\nIzb_1: " << ocena_Izb_1 << "\nIzb_2: " << ocena_Izb_2;
    }
    else cout << "Nepravilen kljuc!\n";
}


int main() {



    return 0;
}