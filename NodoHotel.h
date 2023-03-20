#ifndef LISTICAS_NODO_HOTEL
#define LISTICAS_NODO_HOTEL

#include <string> 
#include <iostream> 
using namespace std; 

class NodoHotel{
protected:
    NodoHotel *previo;
    string nombre;
    int habitacion;
    NodoHotel *siguiente;

public:
    NodoHotel(string nombre, int numHabitacion);

    NodoHotel(string nombre, int numHabitacion, NodoHotel *previo, NodoHotel *siguiente);

    string getNombreNodo() const;
    int getHabitacionNodo() const;

    NodoHotel *getPrevioNodo() const;
    NodoHotel *getSiguienteNodo() const;

    void ponerPrevio(NodoHotel *previo);
    void ponerSiguiente(NodoHotel *siguiente);

};

#endif //LISTICAS_NODO_H