/*
*Proyecto catalogo de Palas
*Diego Acevedo Ortega
*A01276068
*TC1030
*/

/*
*Este es el main del programa catalogo de palas, el
*cual te permite crear palas de acuerdo a su gama,
*calcular sus costos y mostrar las palas del catalogo
*/

//Bibliotecas

#include <iostream>

using namespace std;

#include "catalogo.h"
#include "pala.h"

//funcion que imprime el menu
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

    //creacion del objeto catalogo
    Catalogo catalogo;

    //creacion de un objeto de cada clase 
    catalogo.crea_ejemplos();

    int opcion = 0;

    int opt = 0;

    //variables temporales
    string temp_nombre, temp_gama;
    
    double temp_peso, temp_calidad, temp_durabilidad,
    temp_desvalance;

    //Ciclo para que siga corriendo el codigo hasta que
    //el ususario elija salir.
    while(opcion < 8 && opcion > -1) {

        //imprimir menu
        menu();

        cout << "Que desea realizar? ";
        cin >> opcion;

        //switch que realiza metodo dependiendo de opcion
        switch(opcion) {

            //caso 1 crea una pala de gama alta
            case 1:

                cout << "\nIngresa el nombre de la pala: ";
                cin >> temp_nombre;
                cout << "\nIngresa el peso gramos: ";
                cin >> temp_peso;
                cout << "\nIngresa la calidad de la pala de "
                << "forma numerica: ";
                cin >> temp_calidad;
                cout << "\nIngresa la durabilidad de la pala " 
                << "de forma numerica: ";
                cin >> temp_durabilidad;

                catalogo.agrega_gama_alta(temp_nombre,
                temp_peso, temp_calidad, temp_durabilidad);

                break;

            //caso 2 crea una pala de gama baja
            case 2:

                cout << "\nIngresa el nombre de la pala: ";
                cin >> temp_nombre;
                cout << "\nIngresa el peso gramos: ";
                cin >> temp_peso;
                cout << "\nIngresa la calidad de la pala  de"
                << " forma numerica: ";
                cin >> temp_calidad;
                cout << "\nIngresa el desvalance de la pala "
                << "de forma numerica: ";
                cin >> temp_desvalance;

                catalogo.agrega_gama_baja(temp_nombre,
                temp_peso, temp_calidad, temp_desvalance);

                break;

            //caso 3 muestra todas las palas
            case 3:

                catalogo.muestra_palas();

                break;

            //caso 4 muestra palas por su gama
            case 4:

                cout << "Ingresa 1 si quieres mostrar todas"
                << " de gama alta y 2 si quieres mostrar las"
                << " de gama baja: ";
                cin >> opt;

                if(opt == 1) {

                    temp_gama = "Alta";

                }

                else { if(opt == 2) {

                    temp_gama = "Baja";

                }

                else {

                    break;

                }
                }

                catalogo.muestra_palas(temp_gama);

                break;

            //caso 5 muestra palas por su peso
            case 5:

                cout << "Ingresa el peso maximo de las palas"
                << " que quieres que se muestren: ";
                cin >> temp_peso;

                catalogo.muestra_palas(temp_peso);

                break;

            //calcula costo de todas las palas
            case 6:

                catalogo.calcula_costo_palas();

                break;

            //calcula costo de las palas por su gama
            case 7:

                cout << "Ingresa 1 si quieres calcular el"
                << " costo de todas las palas de gama alta"
                << " y 2 si quieres caluclar el costo de"
                << " las de gama baja: ";
                cin >> opt;

                if(opt == 1) {

                    temp_gama = "Alta";

                }

                else { if (opt == 2) {

                    temp_gama = "Baja";

                }

                else {

                    break;

                }
                }

                catalogo.calcula_costo_palas(temp_gama);

                break;
    
        }
    }

    return 0;

}