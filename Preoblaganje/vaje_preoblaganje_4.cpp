#include <iostream>

using namespace std;

/*
    Naloga 4:
    
    Deklariraj razred Denar, ki naj vsebuje lastnosti euro in centi. 
    Definiraj metode za vnos in izpis obeh lastnosti ter preobloži operatorje +,-,*,/ in == tako, da bodo znali pravilno računati z denarno valuto EUR. 
    Premisli, kakšnega tipa naj bosta lastnosti razreda ter kakšne vhodne podatke naj imajo preobloženi operatorji.
*/

class Denar {
    int euro, centi;

public:
    void vnos();
    void izpis();
    Denar operator+(float);
    Denar operator-(float);
    Denar operator*(float);
    Denar operator/(float);
    bool operator==(float);
};

void Denar::vnos() {
    cout << "Vnesi evre: ";
    cin >> euro;
    cout << "Vnesi cente: ";
    cin >> centi;
}
void Denar::izpis() {
    cout << euro << "." << centi << " EUR\n";
}
Denar Denar::operator+(float a) { //dela OK
    Denar c;
    int tmp = a*100;
    c.centi = this->centi + tmp%100;
    tmp /= 100;
    c.euro = this->euro + tmp;
    c.euro += centi / 100;
    c.centi = c.centi%100;
    return c;
}
Denar Denar::operator-(float a) { //ne dela OK idc
    Denar c;
    int tmp = a*100;
    c.centi = this->centi - tmp%100;
    tmp /= 100;
    c.euro = this->euro - tmp;
    if(c.centi < 0) {
        c.euro -= abs(c.centi / 100);
        c.centi /= 100;
        c.centi = 100 - c.centi;
    }
    return c;
}
Denar Denar::operator*(float a) { //idk verjetn OK
    Denar c;
    a = a*this->euro + this->centi * a / 100;
    c.euro = (int)a;
    a *= 100;
    c.centi = ((int)a)%100;
    return c;
}
Denar Denar::operator/(float a) { // -||-
    float b = (float)this->euro + (float)this->centi / 100;
    b /= a;
    Denar c;
    c.euro = (int)b;
    b *= 100;
    c.centi = ((int)b)%100;
    return c;
}
bool Denar::operator==(float a) { //dela OK
    float b = (float)this->euro + (float)this->centi / 100;
    return a == b;
}

int main() {

    Denar kes;
    kes.vnos();
    kes.izpis();
    //kes = kes + 23.01;
    //kes.izpis();
    kes = kes - 3.98;
    kes.izpis();
/*     kes = kes * 1.2;
    kes.izpis();
    kes = kes / 2.5;
    kes.izpis(); */



    system("pause");
    return 0;
}