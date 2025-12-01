#include <iostream>
#include <climits>

using namespace std;

int monedas[5] = {1,2,5,10,50};

bool puedoPodar(int menor_cant, int monedas_actual){
    return monedas_actual >= menor_cant;
}

bool esSolucion(int cambio_restante){
    return cambio_restante == 0;
}

bool esMejorSolucion(int menor_cant, int monedas_actual) {
    return monedas_actual < menor_cant;
}

bool puedoUsarMoneda(int moneda, int cambio) {
    return moneda <= cambio;
}

void usarMoneda(int moneda, int &cant_actual, int &cambio_restante) {
    cant_actual++;
    cambio_restante -= moneda;
}

void deshacerUsarMoneda(int moneda, int &cant_actual, int &cambio_restante) {
    cant_actual--;
    cambio_restante += moneda;
}

int cambio_bt(int cambio, int &cant_monedas_actual, int &menor_cantidad_monedas, int &cambio_restante) {
    if(!puedoPodar(menor_cantidad_monedas, cant_monedas_actual)) {
        if(esSolucion(cambio_restante)){
            if(esMejorSolucion(menor_cantidad_monedas, cant_monedas_actual)){
                menor_cantidad_monedas = cant_monedas_actual;
            }   
        }else{
            for(int i = 0; i < 5; i++) {
                if(puedoUsarMoneda(monedas[i], cambio)) {
                    usarMoneda(monedas[i], cant_monedas_actual, cambio_restante);
                    cambio_bt(cambio, cant_monedas_actual, menor_cantidad_monedas, cambio_restante);
                    deshacerUsarMoneda(monedas[i], cant_monedas_actual, cambio_restante);
                }
            }
        }
    }
}

int problema_del_cambio_backtracking(int cambio) {
    int mejor_solucion = INT_MAX;
    int cant_monedas_actual = 0;
    cambio_bt(cambio, cant_monedas_actual, mejor_solucion, cambio);
    return mejor_solucion;
}

int main() {
    int cambio;
    cout << "Ingrese el cambio: ";
    cin >> cambio;
    cout << "Para el cambio de " << cambio << " se necesitan: " << problema_del_cambio_backtracking(cambio) << " monedas." << endl;
    return 0;
}