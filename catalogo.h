/*
*Proyecto Pedidos
*Diego Acevedo Ortega
*A01276068
*TC1030
*/

/*
*Clase Catalogo maneja todo tipo de palas, que
*se dividen en Alta y Baja Bama.
*/

//Bibliotecas

#ifndef CATALOGO_H_
#define CATALOGO_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "pala.h"

const int MAX = 100;

class Catalogo {

    private:

        Pala *cat[MAX];
        int id;

    public:

        Catalogo(): id(0) {};

        void crea_ejemplos();
        void agrega_gama_alta(string nombre, float peso,
        float calidad, float durabilidad);
        void agrega_gama_baja(string nombre, float peso,
        float calidad, float desvalance);
        void muestra_palas();
        void muestra_palas(string gama);
        void muestra_palas(float peso);
        float calcula_costo_palas();
        float calcula_costo_palas(string gama);

};


void Catalogo::crea_ejemplos() {

    cat[id] = new AltaGama (id, "Alta default", 400, 1005, 50);
    id++;

    cat[id] = new AltaGama (id, "Baja default", 400, 105, 2);
    id++;

}


void Catalogo::agrega_gama_alta(string nombre, float peso,
float calidad, float durabilidad) {

    cat[id] = new AltaGama(id, nombre, peso, calidad, 
    durabilidad);
    id++;

}


void Catalogo::agrega_gama_baja(string nombre, float peso,
float calidad, float desvalance) {

    cat[id] = new BajaGama(id, nombre, peso, calidad, 
    desvalance);
    id++;
    
}


void Catalogo::muestra_palas() {

    for(int i = 0; i < id; i++) {

        cout << cat[i] -> to_string();

    }
}


void Catalogo::muestra_palas(string gama) {

    for(int i = 0; i < id; i++) {

        if(cat[i] -> get_gama() == gama) {

            cout << cat[i] -> to_string();
        
        }
    }
}


void Catalogo::muestra_palas(float peso) {

    for(int i = 0; i < id; i++) {

        if(cat[i] -> get_peso() <= peso) {

            cout << cat[i] -> to_string();
        
        }
    }
}


float Catalogo::calcula_costo_palas() {

    float total = 0;
    for(int i = 0; i < id; i++){

        total = total + cat[i] -> costo();
    }

    return total;

}


float Catalogo::calcula_costo_palas(string gama) {

    float total = 0;
    for(int i = 0; i < id; i++){

        if (cat[i] -> get_gama() == gama) {

            total = total + cat[i] -> costo();
        }
    }
    
    return total;

}

#endif // CATALOGO_H_