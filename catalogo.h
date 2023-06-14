/*
*Proyecto Pedidos
*Diego Acevedo Ortega
*A01276068
*TC1030
*/

/*
*Clase Catalogo: tiene funciones crear todo tipo de palas,
*que se dividen en Alta y Baja Bama. También puede 
*mostrarte las palas que hay en el catalogo y sus costos.
*/

//Bibliotecas

#ifndef CATALOGO_H_
#define CATALOGO_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//biblioteca con el objeto a usar
#include "pala.h"

//valor constante para el tamano de los arreglos
const int MAX = 100;

//Declaro clase Catalogo
class Catalogo {

    private:

        //Declaro atributos de instancia
        Pala *cat[MAX];
        int id;

    public:

        //Declaro constructor por default
        Catalogo(): id(0) {};

        //Declaro metodos
        void crea_ejemplos();
        void agrega_gama_alta(string nombre, double peso,
        double calidad, double durabilidad);
        void agrega_gama_baja(string nombre, double peso,
        double calidad, double desvalance);
        void muestra_palas();
        void muestra_palas(string gama);
        void muestra_palas(double peso);
        void calcula_costo_palas();
        void calcula_costo_palas(string gama);

};


/**
 * crea_ejemplos genera objetos en cat[]
 *
 * Genera objetos de tipo Gama Alta y Gama Baja y los
 * guarda en la variable de instancia en cat[] para
 * poder hacer pruebas y siempre poder ocupar todas las
 * opicones del menu. No se debe usar esta funcion si 
 * se va a usar el programa como catalogo, porque los
 * datos son inventados.
 *
 * @param
 * @return
 */
void Catalogo::crea_ejemplos() {

    cat[id] = new AltaGama (id, "Alta default", 350.0, 15.0, 50);
    id++;

    cat[id] = new BajaGama (id, "Baja default", 350.0, 15.0, 10);
    id++;

}


/**
 * agrega_gama_alta crea un objeto Pala y lo agrega a
 * arreglo de palas (cat[])
 *
 * crea un objeto Gama Alta y lo agrega a arreglo de
 * palas usando como index un contador que
 * incrementa de 1 en 1.
 *
 * @param string string nombre, double peso,
 * double calidad, double durabilidad
 * @return
 */
void Catalogo::agrega_gama_alta(string nombre, double peso,
double calidad, double durabilidad) {

    cat[id] = new AltaGama(id, nombre, peso, calidad, 
    durabilidad);
    id++;

}


/**
 * agrega_gama_baja crea un objeto Pala y lo agrega a
 * arreglo de palas (cat[])
 *
 * crea un objeto Gama Baja y lo agrega a arreglo de
 * palas usando como index un contador que
 * incrementa de 1 en 1.
 *
 * @param string string nombre, double peso,
 * double calidad, double desvalance
 * @return
 */
void Catalogo::agrega_gama_baja(string nombre, double peso,
double calidad, double desvalance) {

    cat[id] = new BajaGama(id, nombre, peso, calidad, 
    desvalance);
    id++;
    
}

/**
 * muestra_palas muestra las palas guardadas en el
 * arreglo
 *
 * utiliza el arreglo cat[] y el orden de registro, para
 * recorrer todo el arreglo imprimiendo cada uno de los
 * objetos con su metodo to_string().
 *
 * @param
 * @return
 */
void Catalogo::muestra_palas() {

    for(int i = 0; i < id; i++) {

        cout << cat[i] -> to_string();

    }
}


/**
 * muestra_palas muestra las palas por su gama guardadas
 * en el arreglo
 *
 * utiliza el arreglo cat[] y el orden de registro, para
 * recorrer todo el arreglo imprimiendo cada uno de los
 * objetos de la gama requerida con su metodo to_string().
 *
 * @param string gama
 * @return
 */
void Catalogo::muestra_palas(string gama) {

    for(int i = 0; i < id; i++) {

        if(cat[i] -> get_gama() == gama) {

            cout << cat[i] -> to_string();
        
        }
    }
}


/**
 * muestra_palas muestra las palas por su peso guardadas
 * en el arreglo
 *
 * utiliza el arreglo cat[] y el orden de registro, para
 * recorrer todo el arreglo imprimiendo cada uno de los
 * objetos del peso requerido con su metodo to_string().
 *
 * @param double peso
 * @return
 */
void Catalogo::muestra_palas(double peso) {

    for(int i = 0; i < id; i++) {

        if(cat[i] -> get_peso() <= peso) {

            cout << cat[i] -> to_string();
        
        }
    }
}


/**
 * calcula_costo_palas calcula el costo de las palas
 * guardadas en el arreglo
 *
 * utiliza el arreglo cat[] y el orden de registro, para
 * recorrer todo el arreglo imprimiendo el costo de cada uno
 * de sus objetos con su metodo costo().
 *
 * @param
 * @return
 */
void Catalogo::calcula_costo_palas() {

    double total = 0.0;
    for(int i = 0; i < id; i++) {

        total = total + cat[i] -> costo();

    }

    cout << "El costo de todas las palas es: " <<
    total << endl;

}

/**
 * calcula_costo_palas calcula el costo de ciertas palas
 * guardadas en el arreglo, dependiendo de su gama
 *
 * utiliza el arreglo cat[] y el orden de registro, para
 * recorrer todo el arreglo imprimiendo el costo de los
 * objetos dependiendo de su gama con su metodo costo().
 *
 * @param string gama
 * @return
 */
void Catalogo::calcula_costo_palas(string gama) {

    double total = 0.0;
    for(int i = 0; i < id; i++){

        if (cat[i] -> get_gama() == gama) {

            total = total + cat[i] -> costo();
        }
    }
    
    cout << "El costo de las palas de gama " <<
    " es de: " << total << endl;

}

#endif // CATALOGO_H_