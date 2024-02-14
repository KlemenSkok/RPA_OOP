#include <iostream>
#include <cmath>

using namespace std;

/*
    2. Nalogo pod točko 1. še spremenite tako, da bo razred Valj uporabljal generični tip T 
    za lastnosti radij in visina ter v glavnem programu določite, da naj bo tip T tipa int in nato še tipa short.  
*/

template <class T>
class Valj {
    T r, v;

public:
    Valj();
    Valj(const Valj&);
    ~Valj();
    void vpis();
    int prostornina();
    int povrsina();
    bool operator!=(Valj);
    void operator+=(int);
    Valj operator-(Valj);
};
template <class T>
Valj<T>::Valj() { r = v = 0; }

template <class T>
Valj<T>::Valj(const Valj &a) {
    this->r = a.r;
    this->v = a.v;
}
template <class T>
Valj<T>::~Valj() { /*cout << "Klican destruktor.\n";*/ }

template <class T>
void Valj<T>::vpis() { 
    cout << "Vnesi r: ";
    do { cin >> r; } while(r < 0);
    cout << "Vnesi v: ";
    do { cin >> v; } while(v < 0);
}

template <class T>
int Valj<T>::prostornina() { return M_PI * r*r * v; }

template <class T>
int Valj<T>::povrsina() { return (M_PI * r*r)*2 + 2*M_PI*r*v; }

template <class T>
bool Valj<T>::operator!=(Valj a) { return this->prostornina() != a.prostornina(); }

template <class T>
void Valj<T>::operator+=(int n) { r += n; v += n; }

template <class T>
Valj<T> Valj<T>::operator-(Valj a) {
    if(*this != a) {
        a.r = -1; a.v = -1;
        return a;
    }
    a.r = this->r;
    a.v = abs(this->v - a.v);
    return a;
}

int main() {

    Valj<short/*int*/> a, b;
    a.vpis(); b.vpis();

    a += 3;
    a = a-b;
    
    if(a != b) {
        cout << "Objekta nista enaka. \nRazlika med povrsinama: " << abs(a.povrsina() - b.povrsina()) << endl;
    }
    else
        cout << "Objekta sta enaka\n";


    return 0;
}

/*
//primer uporabe kazalca na objekt
    Valj<int> *kazalc = new Valj<int>;
    kazalc->vpis();
    cout << kazalc->povrsina() << endl;

    *kazalc += 3;
    cout << kazalc->povrsina() << endl;

    delete kazalc;
*/