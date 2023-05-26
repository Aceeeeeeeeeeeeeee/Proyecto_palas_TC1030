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
#include <string>

using namespace std;

#include "pala.h"


int main(){

    int temp_id = 1;
    
    string temp_nombre, temp_tipo, temp_material,
    temp_forma;
    
    float temp_peso, temp_durabilidad, temp_calidad,
    temp_desvalance;


    cout << "\nIngresa el nombre de la pala: ";
    cin >> temp_nombre;
    cout << "\nIngresa el peso gramos: ";
    cin >> temp_peso;
    cout << "\nIngresa el tipo de pala: ";
    cin >> temp_tipo;
    cout << "\nIngresa el material de la pala: ";
    cin >> temp_material;
    cout << "\nIngresa el forma: ";
    cin >> temp_forma;
    cout << "\nIngresa la durabilidad de la pala: ";
    cin >> temp_durabilidad;
    cout << "\nIngresa la calidad de la pala: ";
    cin >> temp_calidad;

    AltaGama pala_nox(temp_id, temp_nombre, temp_peso,
    temp_tipo, temp_material, temp_forma,
    temp_durabilidad, temp_calidad);

    cout << pala_nox.to_string();


    cout << "\nIngresa el nombre de la pala: ";
    cin >> temp_nombre;
    cout << "\nIngresa el peso gramos: ";
    cin >> temp_peso;
    cout << "\nIngresa el tipo de pala: ";
    cin >> temp_tipo;
    cout << "\nIngresa el material de la pala: ";
    cin >> temp_material;
    cout << "\nIngresa la calidad de la pala: ";
    cin >> temp_calidad;
    cout << "\nIngresa el desvalance de la pala: ";
    cin >> temp_desvalance;

    BajaGama pala_wilson(temp_id, temp_nombre, temp_peso,
    temp_tipo, temp_material, temp_calidad, temp_desvalance);

    cout << pala_wilson.to_string();
    
}