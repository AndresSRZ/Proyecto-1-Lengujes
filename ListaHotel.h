#ifndef LISTICAS_LISTA_HOTEL
#define LISTICAS_LISTA_HOTEL

#include <cstddef>
#include "NodoHotel.h"

class ListaHotel {
protected:
    NodoHotel *primero = NULL;//primero es un atributo. Es un puntero de tipo Nodo
    //NodoHotel *primeroH = NULL;//primero es un atributo. Es un puntero de tipo Nodo
public:

    ListaHotel();//Constructor de la lista. Al crearse la lista se debe inicializar el puntero *primero (head)  de modo que apunte a NULL

    void insertarCabezaLista(string n, int h);

    void insertarHabitacionOrdenada(string n, int h);

    void insertarAlfabetoOrdenado(string n, int h);

    void insertarUltimo(string n, int h);

    //void ultimo(int entrada);

    void insertarLista(int entrada);

    void insertarLista(NodoHotel* anterior, string n, int h);//especial

    NodoHotel *buscarListaNombre(string destino);

    NodoHotel *buscarListaHabitacion(int destino);

    void eliminarNombre(string entrada);

    void eliminarHabitacion(int entrada);

    NodoHotel *getUltimo();

    void visualizar();

    void visualizarAlreves();
};

#endif //LISTICAS_LISTA_H