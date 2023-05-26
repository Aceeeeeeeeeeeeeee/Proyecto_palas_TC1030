/*
*Proyecto Catalogo de Palas
*Diego Acevedo Ortega
*A01276068
*TC1030
*/

/*
*Clase Pala es la clase padre de Alta Gama y Baja
*Gama, esta clase tiene los metodos y atributos 
*genericos para una pala.
*/

//Bibliotecas

#ifndef PALA_H_
#define PALA_H_

#include <string>
#include <sstream>

using namespace std;


//Declaro la clase abstracta Palas
class Pala {

    protected:

        //Declaro atributos de instancia
        int id;
        string nombre;
        double peso;
        string tipo;

    public:

        //Declaro constructor por default
        Pala(){
            
            id = 0;
            nombre = "";
            peso = 0.0;
            tipo = "";

        }

        //Declaro constructor que recibe valores
        Pala(int i, string nom, float pes, string tip){

            id = i;
            nombre = nom;
            peso = pes;
            tipo = tip;

        }


        //Declaro metodos
        virtual float costo() = 0;
        virtual string to_string() = 0;

};


/*
*Clase Alta Gama que hereda de la Clase Pala,
*esta contiene los atributos y metodos para una Pala.
*/

//Declaro clase Alta Gama que hereda Pala
class AltaGama: public Pala {

    private:

        //Declaro atributos de instancia
        string material;
        string forma;
        float durabilidad;
        float calidad;

    public:

        //Declaro constructor por default
        AltaGama() {

            id = 0;
            nombre = "";
            peso = 0.0;
            tipo = "";
            material = "";
            forma = "";
            durabilidad = 0.0;
            calidad = 0.0;

        }

        //Declaro constructor que recibe valores
        AltaGama(int i, string nom, float pes, string tip,
        string mat, string form, float dur, float cal):
        Pala(i, nom, pes, tip) {

            material = mat;
            forma = form;
            durabilidad = dur;
            calidad = cal;

        }

        //Declaro metodos
        float costo();
        string to_string();

};

/**
 * Metodo que calcula el costo de una pala de alta 
 * gama, tomando en cuenta su peso, su durabilidad
 * y su calidad
 *
 * @param
 * @return double costo de una pala de alta gama
*/
float AltaGama::costo() {

    float cost_alt;
    cost_alt = (durabilidad + calidad) * peso;
    return cost_alt;

}

/**
 * Almacenda los valores de los atributos 
 * en una cadena de texto.
 *
 * @param
 * @return string con los datos de la pala de alta
 * gama
*/
string AltaGama::to_string() {

    stringstream aux;
    aux << "El id es " << id << " y su nombre es " << 
    nombre << ", pesa " << peso << ", es una pala "
    << tipo << ", es de " << material << ", su forma es "
    << forma << ", su grado de durabilidad es " << 
    durabilidad << " y su calidad es " << calidad << "\n"
    << "El costo de la pala es: " << costo();
    return aux.str();

}


/*
*Clase Baja Gama que hereda de la Clase Pala,
*esta contiene los atributos y metodos para una Pala.
*/

//Declaro clase Baja Gama que hereda Pala
class BajaGama: public Pala {

    private:

        //Declaro atributos de instancia
        string material;
        float calidad;
        float desvalance;

    public:

        //Declaro constructor por default
        BajaGama() {

            id = 0;
            nombre = "";
            peso = 0.0;
            tipo = "";
            material = "";
            calidad = 0.0;
            desvalance = 0.0;

        }

        //Declaro constructor que recibe valores
        BajaGama(int i, string nom, float pes, string tip,
        string mat, float cal, float des): Pala(i, nom, 
        pes, tip) {

            material = mat;
            calidad = cal;
            desvalance = des;

        }

        //Declaro metodos
        float costo();
        string to_string();

};

/**
 * Metodo que calcula el costo de una pala de baja 
 * gama, tomando en cuenta su peso y su calidad
 *
 * @param
 * @return double costo de una pala de baja gama
*/
float BajaGama::costo() {

    float cost_baj;
    cost_baj = ((calidad * peso) - 500)/desvalance;
    return cost_baj;

}

/**
 * Almacenda los valores de los atributos 
 * en una cadena de texto.
 *
 * @param
 * @return string con los datos de la pala de alta
 * gama
*/
string BajaGama::to_string() {

    stringstream aux;
    aux << "El id es " << id << " y su nombre es " << 
    nombre << ", pesa " << peso << ", es una pala "
    << tipo << ", es de " << material << ", su forma es "
    << ", su calidad es " << calidad << 
    " y su desvalance es " << desvalance << "\n"
    << "El costo de la pala es: " << costo();
    return aux.str();

}

#endif //PALA_H_