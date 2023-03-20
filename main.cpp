#include <iostream>
#include "ListaHotel.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

//metodo que carga las distintas listas con la informacion que esta en el archivo plano
void cargarHuespedesArchivo(ListaHotel *l, ListaHotel *listaHabitacion, ListaHotel *listaAlfabeto) {
    string line;
    string nombre;
    bool leyoNombre; 
    
    ifstream archivo_entrada("Hotel/hotel.txt");
  
    //abre el archivo de lectura 
    if (archivo_entrada.is_open()) {
        leyoNombre = true;
        // mientras tenga lineas que leer lee cada linea del archivo
        while (getline(archivo_entrada, line)) {
            leyoNombre = !(leyoNombre);
            // cada dos lineas leidas debe insertar en cada uno de las listas
            if(!(leyoNombre)){
                nombre = line;
            }
            else{
                // agrega a la lista l por orden de llegada
                l->insertarCabezaLista(nombre, stoi(line, nullptr, 10));
                // agrega a la lista listaHabitacion por orden de habitacion
                listaHabitacion->insertarHabitacionOrdenada(nombre, stoi(line, nullptr, 10));
                // agrega a la lista listaAlfabeto por orden de nombres
                listaAlfabeto->insertarAlfabetoOrdenado(nombre, stoi(line, nullptr, 10));
            }
        }
        archivo_entrada.close();
    }
    else {
        cout << "No se pudo abrir el archivo Hotel/hotel.txt" << endl;
    }
}
//metodo para buscar la habitacion en la lista
void buscarHabitacion(ListaHotel *l){
    NodoHotel *temp;
    int habitacion;
    cout << "Ingrese el numero de habitacion que desea buscar: " << endl;
    cin >> habitacion; 
  
    temp = l->buscarListaHabitacion(habitacion);
    
    cout << "\n\n" << endl;
    //si es diferente de null temp contendra la direccion del nodo, por lo tanto contiene la informacion del nodo buscado 
    if (temp != NULL) {
        cout << "La habitacion " << temp->getHabitacionNodo() << " se encuentra ocupada por " << temp->getNombreNodo() << endl;
    }
    //si temp es null, es que no la encuentra. 
    else {
        cout << "La habitacion " << habitacion << " se encuentra disponible" << endl;
    }
    cout << "\n\n" << endl;
}

//metodo para buscar nombre en la lista
void buscarNombre(ListaHotel *l){
    NodoHotel *temp;
    string nombre;
    cout << "Ingrese el nombre del huesped que desea buscar: " << endl;
    cin >> nombre; 
  
    temp = l->buscarListaNombre(nombre);
  
    cout << "\n\n" << endl;
    //si es diferente de null temp contendra la direccion del nodo, por lo tanto contiene la informacion del nodo buscado 
    if (temp != NULL) {
        cout << "El huesped " << temp->getNombreNodo() << " se encuentra en la habitacion " << temp->getHabitacionNodo() << endl;
    } 
    else {
    //si temp es null, es que no la encuentra. 
        cout << "No se encontró ese huésped" << endl;
    }
    cout << "\n\n" << endl;
}

// metodo para buscar los vecinos de una lista
void buscarVecinos(ListaHotel *listaHabitacion){
    NodoHotel *temp;
    NodoHotel *nodoAnterior;
    NodoHotel *nodoPosterior;

    int habitacion;
    cout << "Ingrese el numero de habitacion que desea buscarle vecinos: " << endl;
    cin >> habitacion; 
  
    temp = listaHabitacion->buscarListaHabitacion(habitacion);
    cout << "\n\n" << endl;
    //si es diferente de null temp contendra la direccion del nodo, por lo tanto contiene la informacion del nodo buscado 
    if (temp != 0) {
        cout << "La habitacion " << temp->getHabitacionNodo() << " se encuentra ocupada por " << temp->getNombreNodo() << " y sus vecinos son: " << endl;
        nodoAnterior = temp->getPrevioNodo();
        nodoPosterior = temp->getSiguienteNodo();
        //si es diferente de null temp contendra la direccion del nodo, por lo tanto contiene la informacion del nodo buscado y el anterior
        if (nodoAnterior != NULL) {
            cout << "El vecino anterior es " << nodoAnterior->getNombreNodo() << " que se encuentra en la habitacion " << nodoAnterior->getHabitacionNodo() << endl;
        } 
        //si es  null temp no tendra vecino anterior
        else {
            cout << "No tiene vecino anterior" << endl;
        }
        //si es diferente de null temp contendra la direccion del nodo, por lo tanto contiene la informacion del nodo buscado y el siguiente
        if (nodoPosterior != NULL) {
            cout << "El vecino posterior es " << nodoPosterior->getNombreNodo() << " que se encuentra en la habitacion " << nodoPosterior->getHabitacionNodo() << endl;
        } else {
            cout << "No tiene vecino posterior" << endl;
        }
    } else {
        cout << "La habitacion " << habitacion << " se encuentra disponible" << endl;
    }
    cout << "\n\n" << endl;
}

//metodo para agregar nombre y habitacion al final del archivo .txt
void agregarHuespedAArchivo(string nombreHuesped, int numeroHabitacion){
      
    string archivo = "Hotel/hotel.txt";   
  
    ofstream archivo_salida(archivo, ios::app);

    archivo_salida << nombreHuesped << endl;
    archivo_salida << numeroHabitacion << endl;

    archivo_salida.close();

}

//metodo para agregar huespedes con sus respectivos punteros, previo y siguiente 
void AgregarHuespedes(ListaHotel *l, ListaHotel *listaHabitacion, ListaHotel *listaAlfabeto){
    string n;
    int h;
    NodoHotel *nuevo;
    NodoHotel *temp;
    bool encontroHabitacion;
    do {
        cout << "Ingrese el nombre del huesped" << endl;
        cout << "(Ingrese 'salir' cuando finalice de ingresar huespedes)" << endl;
        cin >> n;
        cout << "\n\n" << endl;
        if (n.compare("salir") != 0) {

            cout << "Ingrese el numero de habitacion del huesped" << endl;
            cin >> h;
            encontroHabitacion = false;
            temp = l->buscarListaHabitacion(h);
            while (temp != NULL) {
                // no econtro disponibilidad en la habitacion h
                temp = l->buscarListaHabitacion(h-1);
                if (temp != NULL){
                    // no encontro disponibilidad en la habitacion h-1
                    temp = l->buscarListaHabitacion(h+1);
                    if (temp != NULL){
                        // no encontro disponibilidad en la habitacion h+1
                        cout << "\n\n" << endl;
                        cout << "La habitacion solicitada, la anterior y la siguiente estan ocupadas" << endl;
                    }
                    else {
                        // encontro disponibilidad en la habitacion h+1
                        cout << "\n\n" << endl;
                        cout << "No encontramos disponibilidad en la habitacion " << h << " ni en " << h-1 << " por lo tanto le asignamos la habitacion " << h+1 << endl;
                        encontroHabitacion = true;
                        h++;
                    }
                }
                else {
                    // encontro disponibilidad en la habitacion h-1
                    cout << "\n\n" << endl;
                    cout << "No encontramos disponibilidad en la habitacion " << h << " por lo tanto le asignamos la habitacion " << h-1 << endl;
                    encontroHabitacion = true;
                    h--;
                }
                if (!(encontroHabitacion)){
                    cout << "\n\n" << endl;
                    cout << "Ingrese un nuevo numero de habitacion" << endl;
                    cin >> h;
                    temp = l->buscarListaHabitacion(h);
                }
            }
          
            l->insertarCabezaLista(n,h);
          
            agregarHuespedAArchivo(n, h);

            listaHabitacion->insertarHabitacionOrdenada(n, h);
            listaAlfabeto->insertarAlfabetoOrdenado(n, h);
        }
        cout << "\n\n" << endl;
    } while (n != "salir");
}

int main() {  
  
    int opcion = 1;
    //l sera la lista que se creara en orden de llegada
    ListaHotel *l = new ListaHotel();
  
    //listaHabitacion sera la lista que se creara en orden habitaciones
    ListaHotel *listaHabitacion = new ListaHotel();
  
    //listaAlfabeto sera la lista que se creara en orden alfabetico
    ListaHotel *listaAlfabeto = new ListaHotel();

  
    cargarHuespedesArchivo(l, listaHabitacion, listaAlfabeto);
  
    while (opcion != 0) {
        cout << "---------------------------------------------------------"<< endl;
        cout << "-----------------Bienvenido al Hotel 110-----------------"<< endl;
        cout << "---------------------------------------------------------"<< endl;
        cout << "- 1. Ingresar nuevos huespedes                          -" << endl;
        cout << "- 2. Buscar huesped por nombre                          -" << endl;
        cout << "- 3. Buscar habitacion                                  -" << endl;
        cout << "- 4. Mostrar lista de huespedes en orden alfabetico     -" << endl;
        cout << "- 5. Mostrar lista de huespedes en orden de llegada     -" << endl;
        cout << "- 6. Mostrar lista de huespedes en orden de habitacion  -" << endl;
        cout << "- 7. Mostrar vecinos de un huesped                      -" << endl;
        cout << "- 0. Salir                                              -" << endl;
        cout << "---------------------------------------------------------"<< endl;
        cout << "---------------------------------------------------------\n"<< endl;

        cout << "Ingrese la opción que desea realizar: ";
        cin >> opcion;
      
        switch (opcion) {
            case 1:
                //l->crearLista();
                AgregarHuespedes(l,listaHabitacion, listaAlfabeto);
                break;
            case 2:
                buscarNombre(l);
                break;
            case 3:
                buscarHabitacion(l);
                break;
            case 4:
                listaAlfabeto->visualizar();
                break;
            case 5:
                //l->visualizar();
                l->visualizarAlreves();
                break;
            case 6:
                listaHabitacion->visualizar();
                break;
            case 7:
                buscarVecinos(listaHabitacion);
                break;
            case 0:
                cout << "Gracias por pasar por el Hotel 110. Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
        }
    }
    return 0;
}