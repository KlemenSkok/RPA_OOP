#include <iostream>

using namespace std;

/*
    2. Napišite razred, ki bo predstavljal ulomke. Vsak objekt naj ima dva člana (imenovalec in števec). 
    V konstruktorju dovolite podati oba parametra, le števec ali nobenega. 
    Napišite tudi funkcije za vse štiri osnovne računske operacije nad ulomki. 
*/
class Ulomek {
        int imenovalec, stevec;
    public:
        Ulomek(int stevec, int imenovalec) {
            this->imenovalec = imenovalec;
            this->stevec = stevec;
        }
        Ulomek(int stevec) {
            this->stevec = stevec;
            imenovalec = 1;
        }
        Ulomek() {
            imenovalec = 1;
            stevec = 0;
        }
        void izpis();
        void sestevanje(int s, int i);
        void odstevanje(int s, int i);
        void mnozenje(int s, int i);
        void deljenje(int s, int i);
        
};

void Ulomek::izpis() {
    cout << stevec << "/" << imenovalec << endl;
}

int skupni_delitelj(int a, int b) {
    if(a % b == 0)
        return b;
    return skupni_delitelj(b, a%b);
}

void Ulomek::mnozenje(int s, int i) {
    stevec *= s;
    imenovalec *= i;
    int delitelj = skupni_delitelj(stevec, imenovalec); //najdemo najvecji skupni delitelj imenovalca in stevca
    stevec /= delitelj; //in ulomek okrajsamo
    imenovalec /= delitelj;
}

void Ulomek::deljenje(int s, int i) {
    stevec *= i;
    imenovalec *= s;
    int delitelj = skupni_delitelj(stevec, imenovalec); //najdemo najvecji skupni delitelj imenovalca in stevca
    stevec /= delitelj; //in ulomek okrajsamo
    imenovalec /= delitelj;
}

void Ulomek::sestevanje(int s, int i) {
    imenovalec *= i;
    stevec = stevec*i + s*imenovalec;
    int delitelj = skupni_delitelj(stevec, imenovalec); //najdemo najvecji skupni delitelj imenovalca in stevca
    stevec /= delitelj; //in ulomek okrajsamo
    imenovalec /= delitelj;
}

void Ulomek::odstevanje(int s, int i) {
    imenovalec *= i;
    stevec = stevec*i - s*imenovalec;
    int delitelj = skupni_delitelj(stevec, imenovalec); //najdemo najvecji skupni delitelj imenovalca in stevca
    stevec /= delitelj; //in ulomek okrajsamo
    imenovalec /= delitelj;
}

int main() {

    Ulomek a(1, 2), b(1, 3);
    a.sestevanje(b.stevec, b.imenovalec);
    a.izpis();

    return 0;
}