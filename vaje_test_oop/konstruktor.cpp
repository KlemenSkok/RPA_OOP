#include <iostream>

using namespace std;

class Razred {
    int x, y;

public:
    Razred(const Razred&);
    Razred();
    Razred(int, int);
    void vpis();
    void izpis();
};
//kopirni
Razred::Razred(const Razred &a) {
    this->x = a.x;
    this->y = a.y;
    //*this = a;
}
Razred::Razred() { //prazni
    x = y = 0;
}
Razred::Razred(int a, int b) { //neprazni
    this->x = a;
    this->y = b;
}

void Razred::vpis() {
    cout << "Vnesi x in y: ";
    cin >> x >> y;
}
void Razred::izpis() {
    cout << "x: " << x << ", y: " << y << "\n";
}


int main() {

    Razred a, b(1,2), c(b);
    a.vpis();
    a.izpis();
    b.izpis();
    c.izpis();

    return 0;
}