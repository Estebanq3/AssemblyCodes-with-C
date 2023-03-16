#include <iostream>
using namespace std;
typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int NaN = (exp == 0xFF);
    if (NaN) {
        return f;
    }
    if (exp == 0xFF-1) {
        frac = 0;
    } else if (exp == 0) {
        /* Denormalized */
        frac <<= 1;    
    } else {
        /* Normalized */
        exp += 1;
    }
    return sign << 31 | exp << 23 | frac;
}


int main() {
    int f = 0;
    float numero = 0.0;
    cout << "Digitar el numero en punto flotante" << endl;
    cin >> numero;
    cout << "Numero en punto flotante: " << numero << endl;
    f = float_twice( * (unsigned * )(&numero));
    cout << "El resultado es: " << *(float *)(&f) << endl;
    return 0;
}