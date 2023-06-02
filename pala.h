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
        string gama;
        double peso;
        double calidad;

    public:

        //Declaro constructor por default
        Pala(){
            
            id = 0;
            nombre = "";
            gama = "";
            peso = 0.0;
            calidad = 0.0;

        }

        //Declaro constructor que recibe valores
        Pala(int i, string nom, string gam, double pes, double cal){

            id = i;
            nombre = nom;
            gama = gam;
            peso = pes;
            calidad = cal;

        }


        //Declaro metodos
        string get_gama(){
            return gama;
        }

        double get_peso(){
            return peso;
        }

        virtual double costo() = 0;

        virtual string to_string() = 0;

};


/*
*Clase Alta Gama que hereda de la Clase Pala,
*esta contiene los atributos y metodos para una Pala.
*/

//Declaro clase Alta Gama que hereda Pala
class AltaGama: public Pala {

    private:

        //Declaro atributo de instancia
        double durabilidad;

    public:

        //Declaro constructor por default
        AltaGama() {

            id = 0;
            nombre = "";
            gama = "Alta";
            peso = 0.0;
            calidad = 0.0;
            durabilidad = 0.0;
        }

        //Declaro constructor que recibe valores
        AltaGama(int i, string nom, double pes, double cal,
        double dur): Pala(i, nom, "Alta", pes, cal) {

            durabilidad = dur;

        }

        //Declaro metodos
        double costo();
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
double AltaGama::costo() {

    double cost_alt;
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
    nombre <<", Es de gama " << gama << ", pesa " << peso 
    << ", su calidad es " << calidad <<
    " y su grado de durabilidad es " << durabilidad <<
    "\n" << "El costo de la pala es: " << costo();
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
        double desvalance;

    public:

        //Declaro constructor por default
        BajaGama() {

            id = 0;
            nombre = "";
            gama = "Baja";
            peso = 0.0;
            calidad = 0.0;
            desvalance = 0.0;

        }

        //Declaro constructor que recibe valores
        BajaGama(int i, string nom, double pes, double cal,
        double des): Pala(i, nom, "Baja", pes, cal) {

            desvalance = des;

        }

        //Declaro metodos
        double costo();
        string to_string();

};

/**
 * Metodo que calcula el costo de una pala de baja 
 * gama, tomando en cuenta su peso y su calidad
 *
 * @param
 * @return double costo de una pala de baja gama
*/
double BajaGama::costo() {

    double cost_baj;
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
    nombre <<", Es de gama " << gama << ", pesa " << peso 
    << ", su calidad es " << calidad << 
    " y su desvalance es " << desvalance << "\n"
    << "El costo de la pala es: " << costo();
    return aux.str();

}

#endif //PALA_H_