#include <iostream>
using namespace std;

int monedas[5] = {1,2,5,10,50};

//supongo que el array de monedas está ordenado de meonr a mayor.
//Si no lo está, tengo que recorrerlo buscando la moneda con mayor valor.
int problema_del_cambio_greedy(int* array_monedas, int cambio) {
    int cantidad_de_monedas = 0;
    for(int i = 4; i >= 0; i--) {
        int moneda_act = array_monedas[i];
        //Me fijo si la moneda de mayor valor es menor al cambio que tengo que dar.
        //Si eso pasa entonces la uso, sino busco la siguiente de mayor valor
        while(moneda_act <= cambio) {
            cambio -= moneda_act;
            cantidad_de_monedas++;
        }
    }
    //si el cambio quedó en 0 siginifica que pude llegar al cambio, por lo que retorno la cantidad de monedas, en otro caso retorno -1.
    return cambio == 0 ? cantidad_de_monedas : -1;  
}

int main() {
    int cambio;
    cout << "Ingrese el cambio: ";
    cin >> cambio;
    cout << "Para el cambio de " << cambio << " se necesitan: " << problema_del_cambio_greedy(monedas, cambio) << " monedas." << endl;
    return 0;
}