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


//Definicion de la clase abstracta Pala
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

        //Declaro constructor que recibe algunos valores
        Pala(int i, string nom, string gam){

            id = i;
            nombre = nom;
            gama = gam;
            peso = 350.0;
            calidad = 10.0;

        }

        //Declaro constructor que recibe todos valores
        Pala(int i, string nom, string gam, double pes, double cal){

            id = i;
            nombre = nom;
            gama = gam;
            peso = pes;
            calidad = cal;

        }


        //Declaro metodos

        /**
        * getter gama
        *
        * @param
        * @return string gama
        */
        string get_gama(){
            return gama;
        }

        /**
        * getter peso
        *
        * @param
        * @return double peso
        */
        double get_peso(){
            return peso;
        }
        
        virtual double costo() = 0;

        virtual string to_string() = 0;

};


/*
*Clase Alta Gama que hereda de la Clase Pala
*/

//Declaro clase Alta Gama
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

        //Declaro constructor que recibe algunos valores
        AltaGama(int i, string nom): Pala(i, nom, "Alta") {

            durabilidad = 50.0;

        }

        //Declaro constructor que recibe todos valores
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
 * @return double con costo de una pala de alta gama
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
    "\n" << "El costo de la pala es: " << costo() <<
    "\n";
    return aux.str();

}


/*
*Clase Baja Gama que hereda de la Clase Pala
*/

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

        //Declaro constructor que recibe algunos valores
        BajaGama(int i, string nom): Pala(i, nom, "Baja") {

            desvalance = 10.0;

        }

        //Declaro constructor que recibe todos valores
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
 * gama, tomando en cuenta su peso, su desvalance y
 * su calidad
 *
 * @param
 * @return double con costo de una pala de baja gama
*/
double BajaGama::costo() {

    double cost_baj;
    cost_baj = (calidad * peso)/desvalance;
    return cost_baj;

}

/**
 * Almacenda los valores de los atributos 
 * en una cadena de texto.
 *
 * @param
 * @return string con los datos de la pala de baja
 * gama
*/
string BajaGama::to_string() {

    stringstream aux;
    aux << "El id es " << id << " y su nombre es " << 
    nombre <<", Es de gama " << gama << ", pesa " << peso 
    << ", su calidad es " << calidad << 
    " y su desvalance es " << desvalance << "\n"
    << "El costo de la pala es: " << costo() << "\n";
    return aux.str();

}

#endif //PALA_H_