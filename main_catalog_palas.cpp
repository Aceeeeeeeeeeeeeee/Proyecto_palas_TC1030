/*
*Proyecto catalogo de Palas
*Diego Acevedo Ortega
*A01276068
*TC1030
*/

/*
*Este es el main del programa catalogo de palas, el
*cual te permite crear palas de acuerdo a su gama
*calculando sus costos
*/

//Bibliotecas

#include <iostream>

using namespace std;

#include "catalogo.h"
#include "pala.h"


void  menu() {

    cout << "\nMENU:\n\n";
    cout << "1. Agrega una pala de alta gama\n";
    cout << "2. Agrega una pala de baja gama\n";
    cout << "3. Muesta todas las palas\n";
    cout << "4. Muesta ciertas palas de acuerdo" <<
    " a su gama\n";
    cout << "5. Muesta ciertas palas de acuerdo" <<
    " a su peso\n";
    cout << "6. Calcula el costo de todas las" <<
    " palas\n";
    cout << "7. Calcula el costo de todas las" <<
    " palas de acuerdo a su gama\n";
    cout << "8. Salir\n\n";

}


int main() {

    Catalogo catalogo;
    catalogo.crea_ejemplos();

    int opcion = 0;

    int opt = 0;

    string temp_nombre, temp_gama;
    
    float temp_peso, temp_calidad, temp_durabilidad,
    temp_desvalance;

    while(opcion < 8 && opcion > -1) {

        cout << "¿Que desea realizar? ";
        cin >> opcion;

        switch(opcion) {

            case 1:

                cout << "\nIngresa el nombre de la pala: ";
                cin >> temp_nombre;
                cout << "\nIngresa el peso gramos: ";
                cin >> temp_peso;
                cout << "\nIngresa la calidad de la pala: ";
                cin >> temp_calidad;
                cout << "\nIngresa la durabilidad de la pala: ";
                cin >> temp_durabilidad;

                catalogo.agrega_gama_alta(temp_nombre,
                temp_peso, temp_calidad, temp_durabilidad);

                break;

            case 2:

                cout << "\nIngresa el nombre de la pala: ";
                cin >> temp_nombre;
                cout << "\nIngresa el peso gramos: ";
                cin >> temp_peso;
                cout << "\nIngresa la calidad de la pala: ";
                cin >> temp_calidad;
                cout << "\nIngresa el desvalance de la pala: ";
                cin >> temp_desvalance;

                catalogo.agrega_gama_alta(temp_nombre,
                temp_peso, temp_calidad, temp_desvalance);

                break;
            
            case 3:

                catalogo.muestra_palas();

                break;

            case 4:

                cout << "Ingresa 1 si quieres mostrar todas"
                << " de gama alta y 2 si quieres mostrar las"
                << " de gama baja: ";
                cin >> opt;

                if(opt == 1) {

                    temp_gama = "Alta";

                }

                else if (opt == 2) {

                    temp_gama = "Baja";

                }

                else {

                    break;

                }

                catalogo.muestra_palas(temp_gama);

                break;

            case 5:

                cout << "Ingresa el peso maximo de las palas"
                << " que quieres que se muestren: ";
                cin >> temp_peso;

                catalogo.muestra_palas(temp_peso);

                break;

            case 6:

                catalogo.calcula_costo_palas();

                break;

            case 7:

                cout << "Ingresa 1 si quieres calcular el"
                << " costo de todas las palas de gama alta"
                << " y 2 si quieres caluclar el costo de"
                << " las de gama baja: ";
                cin >> opt;

                if(opt == 1) {

                    temp_gama = "Alta";

                }

                else if (opt == 2) {

                    temp_gama = "Baja";

                }

                else {

                    break;

                }

                catalogo.calcula_costo_palas(temp_gama);

                break;
    
        }
    }
}