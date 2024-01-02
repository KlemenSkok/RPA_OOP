#include <iostream>
#include <ctime>

using namespace std;

/*
    8. Deklariraj razred Datum z lastnostmi dan, mesec in leto ter metodami za določanje naključne privzete vrednosti datuma, 
    za izpis datuma in metodo, ki izračuna koliko dni manjka do konca leta. 
    Napiši program, ki deklarira 20 naključnih datumov s pomočjo razreda Datum.
    
    Primer: Naključni datum 25.10.1999; izpis: Dan:25 Mesec:10 Leto: 1999. 
    Do leta 2000 manjka še 65 dni (za vse mesece vzamemo 30 dni).
*/

// UPOSTEVA PRESTOPNA LETA ~~
class Datum {
    int dan,
    mesec,
    leto;
    
public:
    void genDatum();
    void izpis();
    int kolikoDni();
};

void Datum::genDatum() {
    leto = rand()%2050;
    mesec = rand()%12 + 1;
    switch(mesec) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dan = rand()%31+1;
            break;
        case 2:
            if((leto % 4 == 0 && leto % 100 != 0) || (leto % 400 == 0)) //prestopno leto
                dan = rand()%29+1;
            else dan = rand()%28+1;
            break;
        default:
            dan = rand()%30+1;
    }
}

void Datum::izpis() {
    cout << dan << ". " << mesec << ". " << leto;
}

int maxDni(int mesc, int leto) {
    switch(mesc) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            if((leto % 4 == 0 && leto % 100 != 0) || (leto % 400 == 0)) //prestopno leto
                return 29;
            else return 28;
            break;
        default:
            return 30;
    }
}

int Datum::kolikoDni() {
    int stevc = 0;
    stevc += maxDni(dan, leto) - dan;
    int tmp_mesec = mesec+1;

    while(tmp_mesec <= 12) {
        stevc += maxDni(tmp_mesec, leto);
        tmp_mesec++;
    }
    return stevc;
}

int main() {

    srand(time(NULL));
    Datum datum;
    
    for(int i = 0; i < 20; i++) {
        datum.genDatum();
        datum.izpis();
        cout << ", dni do konca leta: " << datum.kolikoDni() << endl;
    }

    return 0;
}

/*
Leto je prestopno, če je deljivo s 4, razen ...
... v primeru, da je leto deljivo s 100, leto ni prestopno, razen ...
... v primeru, da je leto deljivo s 400, leto je prestopno.
*/