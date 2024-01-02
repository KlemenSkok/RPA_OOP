#include <iostream>

using namespace std;

/*
    3. Deklariraj razred Polinom, ki definira polinom 2. stopnje (kvadratni polinom y=ax2 + bx + c). Definiraj metode razreda, ki 
    • berejo koeficiente polinoma;
    • računajo vrednosti polinoma za prebrani x;
    • izpiše število korenov polinoma;
    Napiši program, ki deklarira objekt razreda Polinom in izračuna vrednost polinoma ali število korenov.
*/

class Polinom {
    int a, b, c;
    
    public:
        Polinom();
        void beri_koef();
        int izracunaj_y(int);
        void izracunaj_koren();
        void izpis();
};

Polinom::Polinom() {
    a = 1;
    b = 1;
    c = 1;
}

void Polinom::beri_koef() {
    cin >> a >> b >> c;
}

int Polinom::izracunaj_y(int x) {
    return a * x*x + b * x + c;
}

void Polinom::izpis() {
    cout << a << "x^2 + " << b << "x";
    if(c != 0) cout << " + " << c << endl;
    else cout << endl;
}

void Polinom::izracunaj_koren() { //nicle
    int D = b*b - 4*a*c;
    if(D < 0)
        cout << "Polinom nima nicel.\n";
    else if(D == 0)  
        cout << "Polinom ima eno niclo: " << (-b / (2*a)) << endl;
    else {
        cout << "Polinom ima dve nicli: \n";
        cout << "\tx1 = " << ((-b + D) / (2*a)) << endl;
        cout << "\tx2 = " << ((-b - D) / (2*a)) << endl;
    }
}

int main() {

    Polinom p;
    p.beri_koef();
    p.izpis();
    int x; 
    cout << "vnesi x: "; cin>> x;
    cout << "Vrednost polinoma za vrednost x=" << x << ": " << p.izracunaj_y(x) << endl;

    p.izracunaj_koren();

    system("pause");
    return 0;
}