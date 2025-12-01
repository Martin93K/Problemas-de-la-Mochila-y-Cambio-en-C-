#include <iostream>
#include <climits>

using namespace std;

int monedas[5] = {1,2,5,10,50};

//SOLUCIÓN CON TABULACIÓN
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

//SOLUCIÓN CON MEMOIZACIÓN
int memo_aux(int cambio, int* &cambios) {
    //soluciones triviales del problema
    if(cambio == 0) return 0; 
    if(cambio < 0) return INT_MAX;

    if(cambios[cambio] != -1) { //ya está calculado
        return cambios[cambio];
    }
    //si no está calculado lo calculo
    int mejor_cambio = INT_MAX;
    for(int i = 0; i < 5; i++){
        int moneda = memo_aux(cambio - monedas[i], cambios); //busco la cantidad de monedas para dar el cambio con cada moneda disponible.
        if(moneda != INT_MAX) mejor_cambio = min(mejor_cambio, moneda + 1); //me quedo con la que me de menos cantidad de monedas
    }  
    cambios[cambio] = mejor_cambio;
    return mejor_cambio;
}

int problema_del_cambio_PD_memoizacion(int cambio) {
    //el -1 representa el valor no calculado (excepto la posición 0 (cambio de 0), que necesita 0 monedas).
    int* cambios_memo = new int[cambio + 1]();
    for(int i = 1; i < cambio + 1; i++) cambios_memo[i] = -1;

    return memo_aux(cambio, cambios_memo);
}

int main() {
    int cambio;
    cout << "Ingrese el cambio: ";
    cin >> cambio;
    //COMENTAR LA QUE NO QUIERA USAR (memoización o tabulación)
    cout << "Para el cambio de " << cambio << " se necesitan: " << problema_del_cambio_PD_tabulacion(cambio, 5) << " monedas." << endl;
    // cout << "Para el cambio de " << cambio << " se necesitan: " << problema_del_cambio_PD_memoizacion(cambio) << " monedas." << endl;
    return 0;
}