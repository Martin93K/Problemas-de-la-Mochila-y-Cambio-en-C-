#include <iostream>
#include <climits>

using namespace std;

int monedas[5] = {1,2,5,10,50};

int problema_del_cambio_DAC(int* array_monedas, int cambio, int cant_monedas) {
    //soluciones triviales del problema!
    if(cambio == 0) return 0; 
    if(cambio < 0) return INT_MAX;
    if(cant_monedas == 0) return INT_MAX;
    
    if(array_monedas[cant_monedas - 1] > cambio) {
        return problema_del_cambio_DAC(array_monedas, cambio, cant_monedas -1);
    } 
    int valor_usar_moneda = 1 + problema_del_cambio_DAC(array_monedas, cambio - array_monedas[cant_monedas-1], cant_monedas);
    int valor_no_usar_moneda = problema_del_cambio_DAC(array_monedas, cambio, cant_monedas-1);

    return min(valor_usar_moneda, valor_no_usar_moneda);
}

int main() {
    int cambio;
    cout << "Ingrese el cambio: ";
    cin >> cambio;
    cout << "Para el cambio de " << cambio << " se necesitan: " << problema_del_cambio_DAC(monedas, cambio, 5) << " monedas." << endl;
    return 0;
}