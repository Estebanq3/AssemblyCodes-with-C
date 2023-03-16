#include <iostream>
using namespace std;

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int NaN = (exp == 0xFF) && (frac != 0);
    if (NaN) {
    	cout<< f;
        return f;
    }

    return (~sign << 31) | (exp << 23) | frac;

}

int main(){
    int f = 0;
    float numero = 0.0;
    cout << "Digitar el numero en punto flotante" << endl;
    cin >> numero;
    cout << "Numero en punto flotante: " << numero << endl;
    f = float_negate( * (unsigned * )(&numero));
    cout << "El numero negado es: " << *(float *)(&f) << endl;
    return 0;
}
