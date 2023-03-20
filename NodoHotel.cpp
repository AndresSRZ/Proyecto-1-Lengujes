#include "NodoHotel.h"

NodoHotel::NodoHotel(string n, int h)
{
    nombre = n;
    habitacion = h;
    previo = 0;
    siguiente = 0; // 0 es el puntero NULL en C++
}

NodoHotel::NodoHotel(string n, int h, NodoHotel* p, NodoHotel* s) // crea el nodo y lo enlaza a n
{
    nombre = n;
    habitacion = h;
    previo = p;
    siguiente = s;
}

string NodoHotel::getNombreNodo( ) const
{
    return nombre;
}

int NodoHotel::getHabitacionNodo( ) const
{
    return habitacion;
}

NodoHotel *NodoHotel::getPrevioNodo( ) const
{
    return previo;
}

NodoHotel *NodoHotel::getSiguienteNodo( ) const
{
    return siguiente;
}

void NodoHotel:: ponerPrevio(NodoHotel* p)
{
    previo = p;
}

void NodoHotel:: ponerSiguiente(NodoHotel* s)
{
    siguiente = s;
}