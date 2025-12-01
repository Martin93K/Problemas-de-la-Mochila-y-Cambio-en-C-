#include <iostream>
#include <climits>

using namespace std;

int monedas[5] = {1,2,5,10,50};

int problema_del_cambio_PD_tabulacion(int cambio, int cant_monedas) {
    int* cambios = new int[cambio + 1]();
    for(int i = 1; i < cambio + 1; i++) {
        int menor_cambio = INT_MAX;
        for(int j = 0; j < cant_monedas; j++) {
            if(i >= monedas[j]){
                if(menor_cambio > cambios[i - monedas[j]]){
                    menor_cambio = cambios[i - monedas[j]];
                }
            }
        }
        cambios[i] = menor_cambio + 1;
    }
    return cambios[cambio];
}

int main() {
    int cambio;
    cout << "Ingrese el cambio: ";
    cin >> cambio;
    cout << "Para el cambio de " << cambio << " se necesitan: " << problema_del_cambio_PD_tabulacion(cambio, 5) << " monedas." << endl;
    return 0;
}