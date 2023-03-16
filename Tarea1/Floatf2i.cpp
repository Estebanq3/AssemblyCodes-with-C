#include <iostream>
using namespace std;

typedef unsigned float_bits;



int float_f2i(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned bias = 0x7F;

    int result;
    unsigned E;
    unsigned M;

    if (exp < bias) {
        /* the float number is less than 1 */
        result = 0;
    } else if (exp >= 31 + bias) {
        /* overflow */
        result = 0x80000000;
    } else {
        /* normal */
        E = exp - bias;
        M = frac | 0x800000;
        if (E > 23) {
            result = M << (E - 23);
        } else {
            /* round to zero */
            result = M >> (23 - E);
        }
    }
    return sign ? -result : result;
}

int main(){
    int f = 0;
    float numero = 0.0;
    cout << "Digitar el numero en punto flotante" << endl;
    cin >> numero;
    cout << "Numero en punto flotante: " << numero << endl;
    f = float_f2i( * (unsigned * )(&numero));
    cout << "El numero en int: " <<  f << endl;
    return 0;
}