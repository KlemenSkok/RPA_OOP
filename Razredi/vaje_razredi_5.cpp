#include <iostream>

using namespace std;

/*
    5. Napišite program, s katerim preberete eno celo število in izpišete vsoto števk prebranega števila (uporabi razred). 
    Primer: če je število 427, je vsota števk 13.
*/

class Stevilo {
    int stevilo;
    public:
    Stevilo(int);
    void vsota_stevk();
};

Stevilo::Stevilo(int n) {
    stevilo = n;
}

void Stevilo::vsota_stevk() {
    int n = 0;
    while(stevilo > 0) {
        n += stevilo % 10;
        stevilo /= 10;
    }
    cout << "Vsota stevk: " << n << endl;
}

int main() {

    int n; cin >> n;
    Stevilo x(n);
    x.vsota_stevk();

    system("pause");
    return 0;
}