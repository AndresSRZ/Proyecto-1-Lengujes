#include "ListaHotel.h"
#include "NodoHotel.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ListaHotel::insertarHabitacionOrdenada(string nombre, int habitacion) {
  
    NodoHotel *nuevo; // Nodo nuevo
    NodoHotel *nodoAnterior = NULL;  // Sera el nodo anterior cuando se este recorriendo la lista
    NodoHotel *nodoUltimo = NULL; // Sera el ultimo nodo de la lista
    NodoHotel *n; // es el apuntador para recorrer los nodos
    bool agrego;  // variable booleana que indica si se pudo o no agregar el nuevo nodo, luego de recorrer la lista 


    // Se crea el nuevo nodo y se inicializan sus apuntadores
    nuevo = new NodoHotel(nombre, habitacion);
    nuevo->ponerPrevio(NULL);
    nuevo->ponerSiguiente(NULL);

    // se inicializa el booleano indicando que no se ha agregado el nuevo nodo, antes de recorrer la lista
    agrego = false;

    //mensaje de seguimiento cada vez que se va a agregar un nuevo nodo 
    /*cout << "*************Procesando " << habitacion << " primero " << primero <<  " primero " << primero << " Se creo el nodo  " << nuevo <<  endl;*/

  
    if (primero == 0){  //  Si nunca se ha agregado ningun nodo, se deja el nodo nuevo recien creado como priemr nodo
        primero = nuevo; //mensaje de asignacion del primer nodo
        /*cout << "Se asigno como primero el nodo " << primero << endl;*/
    }
    else
    {
        n = primero;  // Se recorre la lista desde el primer nodo, hasta llegar al ultimo nodo
        while (n != NULL && !agrego) {
            
            nodoUltimo = n;
            nodoAnterior = n->getPrevioNodo();
            // Se compara la habitacion que se va a ingresar con la habitacioon que se esta recorriendo
            // para saber en que parte de la lista se debe ingresar el nuevo nodo oredenado
            // Cuando encuentre que el nodo que quiero insertar es menor que el nodo que estoy recorriendo 
            // ese sera el punto donde se debe insertar el nuevo nodo

            //cout << "Comparando habitacion " << habitacion << " con " << n->getHabitacionNodo() << endl;
            if (habitacion < n->getHabitacionNodo() ){  
                // Si la habitacion que se va a ingresar es menor quel nodo que se ssta recoriendo, 
                // se debe ingresar el nuevo nodo. con dos opciones. 
                //      1 que se deba ingresar entre dos nodos o 
                //      2 que se deba ingresar de primeras
                if (n->getPrevioNodo() != NULL){
                    // Si el nodo que se esta recoriendo apunta a un nodo anterior,
                    // quiere decir que el nuevo nodo debe ingresarse entre dos nodos existentes
                    //cout << "Insertando Entre nodos " << habitacion << endl;
                    nodoAnterior->ponerSiguiente(nuevo);
                    nuevo->ponerPrevio(nodoAnterior);
                    nuevo->ponerSiguiente(n);
                    n->ponerPrevio(nuevo);
                    agrego = true;
                } else{
                    // Si el nodo que se esta recoriendo no tiene un nodo anterior,
                    // quiere decir que el nuevo nodo debe ingresarse de primeras en la lista
                    //cout << "Insertando de primeras " << habitacion << endl;
                    nuevo->ponerPrevio(NULL);
                    nuevo->ponerSiguiente(primero);
                    primero->ponerPrevio(nuevo);
                    primero = nuevo;
                    agrego = true;
                    //cout << "Nuevo primero  " << primero <<  endl;
                }
            }
            n = n->getSiguienteNodo();
        }
        //  Si finalmente luego de recorrer toda la lista no encontro ningun nodo 
        //     que sea menor al que se quiere ingresar, quiere decir que el nodo es mayor que todos los de la lista
        //     y por tanto se debe ingresar de ultimo en la lista
        if (!(agrego)){
            //cout << "Insertando de ultimas " << habitacion << endl;
            nuevo->ponerPrevio(nodoUltimo);
            nodoUltimo->ponerSiguiente(nuevo);
            /*if (primero == nuevo){
                nuevo->ponerPrevio(NULL);
                nuevo->ponerSiguiente(NULL);   
            }*/
        }
    }
  
    //  impresion de seguimiento para saber como quedo el nodo ingresado y sus vecinos
    
  /*  cout << "***Nodo nuevo " << nuevo << " quedo: Habitacion " << habitacion  << " previo " << nuevo->getPrevioNodo() << " siguiente " << nuevo->getSiguienteNodo() << " primero " << primero << " anterior " << nodoAnterior << " nodoUltimo " << nodoUltimo << " n " << n << endl;
    n = nuevo->getPrevioNodo();
    if (n != NULL ){
       cout << "***Nodo Anterior " << n << " quedo: Habitacion " << n->getHabitacionNodo()  << " previo " << n->getPrevioNodo() << " siguiente " << n->getSiguienteNodo() << endl;
    }
    n = nuevo->getSiguienteNodo();
    if (n != NULL ){
       cout << "***Nodo siguiente " << n << " quedo: Habitacion " << n->getHabitacionNodo()  << " previo " << n->getPrevioNodo() << " siguiente " << n->getSiguienteNodo() << endl;
    }  
    visualizarH();*/
    //  impresion 
}

void ListaHotel::insertarAlfabetoOrdenado(string nombre, int habitacion) {
  
    NodoHotel *nuevo; // Nodo nuevo
    NodoHotel *nodoAnterior = NULL;  // Sera el nodo anterior cuando se este recorriendo la lista
    NodoHotel *nodoUltimo = NULL; // Sera el ultimo nodo de la lista
    NodoHotel *n; // es el apuntador para recorrer los nodos
    bool agrego;  // variable booleana que indica si se pudo o no agregar el nuevo nodo, luego de recorrer la lista 


    // Se crea el nuevo nodo y se inicializan sus apuntadores
    nuevo = new NodoHotel(nombre, habitacion);
    nuevo->ponerPrevio(NULL);
    nuevo->ponerSiguiente(NULL);

    // se inicializa el booleano indicando que no se ha agregado el nuevo nodo, antes de recorrer la lista
    agrego = false;

    //mensaje de seguimiento cada vez que se va a agregar un nuevo nodo 
    /*cout << "*************Procesando " << habitacion << " primero " << primero <<  " primero " << primero << " Se creo el nodo  " << nuevo <<  endl;*/

  
    if (primero == 0){  //  Si nunca se ha agregado ningun nodo, se deja el nodo nuevo recien creado como priemr nodo
        primero = nuevo; //mensaje de asignacion del primer nodo
        /*cout << "Se asigno como primero el nodo " << primero << endl;*/
    }
    else
    {
        n = primero;  // Se recorre la lista desde el primer nodo, hasta llegar al ultimo nodo
        while (n != NULL && !agrego) {
            
            nodoUltimo = n;
            nodoAnterior = n->getPrevioNodo();
            // Se compara la habitacion que se va a ingresar con la habitacioon que se esta recorriendo
            // para saber en que parte de la lista se debe ingresar el nuevo nodo oredenado
            // Cuando encuentre que el nodo que quiero insertar es menor que el nodo que estoy recorriendo 
            // ese sera el punto donde se debe insertar el nuevo nodo

            //cout << "Comparando habitacion " << habitacion << " con " << n->getHabitacionNodo() << endl;

            if (nombre.compare(n->getNombreNodo()) < 0){  
                // Si la habitacion que se va a ingresar es menor quel nodo que se ssta recoriendo, 
                // se debe ingresar el nuevo nodo. con dos opciones. 
                //      1 que se deba ingresar entre dos nodos o 
                //      2 que se deba ingresar de primeras
                if (n->getPrevioNodo() != NULL){
                    // Si el nodo que se esta recoriendo apunta a un nodo anterior,
                    // quiere decir que el nuevo nodo debe ingresarse entre dos nodos existentes
                    //cout << "Insertando Entre nodos " << habitacion << endl;
                    nodoAnterior->ponerSiguiente(nuevo);
                    nuevo->ponerPrevio(nodoAnterior);
                    nuevo->ponerSiguiente(n);
                    n->ponerPrevio(nuevo);
                    agrego = true;
                } else{
                    // Si el nodo que se esta recoriendo no tiene un nodo anterior,
                    // quiere decir que el nuevo nodo debe ingresarse de primeras en la lista
                    //cout << "Insertando de primeras " << habitacion << endl;
                    nuevo->ponerPrevio(NULL);
                    nuevo->ponerSiguiente(primero);
                    primero->ponerPrevio(nuevo);
                    primero = nuevo;
                    agrego = true;
                    //cout << "Nuevo primero  " << primero <<  endl;
                }
            }
            n = n->getSiguienteNodo();
        }
        //  Si finalmente luego de recorrer toda la lista no encontro ningun nodo 
        //     que sea menor al que se quiere ingresar, quiere decir que el nodo es mayor que todos los de la lista
        //     y por tanto se debe ingresar de ultimo en la lista
        if (!(agrego)){
            //cout << "Insertando de ultimas " << habitacion << endl;
            nuevo->ponerPrevio(nodoUltimo);
            nodoUltimo->ponerSiguiente(nuevo);
            /*if (primero == nuevo){
                nuevo->ponerPrevio(NULL);
                nuevo->ponerSiguiente(NULL);   
            }*/
        }
    }
  
    //  impresion de seguimiento para saber como quedo el nodo ingresado y sus vecinos
    
  /*  cout << "***Nodo nuevo " << nuevo << " quedo: Habitacion " << habitacion  << " previo " << nuevo->getPrevioNodo() << " siguiente " << nuevo->getSiguienteNodo() << " primero " << primero << " anterior " << nodoAnterior << " nodoUltimo " << nodoUltimo << " n " << n << endl;
    n = nuevo->getPrevioNodo();
    if (n != NULL ){
       cout << "***Nodo Anterior " << n << " quedo: Habitacion " << n->getHabitacionNodo()  << " previo " << n->getPrevioNodo() << " siguiente " << n->getSiguienteNodo() << endl;
    }
    n = nuevo->getSiguienteNodo();
    if (n != NULL ){
       cout << "***Nodo siguiente " << n << " quedo: Habitacion " << n->getHabitacionNodo()  << " previo " << n->getPrevioNodo() << " siguiente " << n->getSiguienteNodo() << endl;
    }  
    visualizarH();*/
    //  impresion 
}

ListaHotel::ListaHotel() {primero = NULL; primero = NULL;}//inicializamos el puntero primero con NULL al momento de crear la lista, es decir este es el puntero head cuando se crea la lista}

void ListaHotel::insertarCabezaLista(string n, int h) {
    NodoHotel *nuevo;
    nuevo = new NodoHotel(n, h);
    nuevo->ponerSiguiente(primero); // enlaza nuevo con primero
    if(primero != NULL){
        primero->ponerPrevio(nuevo);
    }
    primero = nuevo; // mueve primero y apunta al nuevo nodo
}

/*
void ListaHotel::insertarUltimo(string n, int h) {
    NodoHotel *ultimo = this->getUltimo();//seobtine la dirmem del último nodo
    ultimo->ponerSiguiente(new NodoHotel(n, h));//se crea el nuevo nodo con el valor de entrada
}*/
/*
NodoHotel *ListaHotel::getUltimo() {
    NodoHotel *n = primero;
    if (n == NULL) throw "Error, lista vacía";
    while (n->getSiguienteNodo() != NULL) n = n->getSiguienteNodo();
    return n;
}*/
/*
void ListaHotel::insertarLista(NodoHotel *anterior, string n, int h) {
    NodoHotel *nuevo;
    nuevo = new NodoHotel(n, h);
    nuevo->ponerSiguiente(anterior->getSiguienteNodo());
    anterior->ponerSiguiente(nuevo);
}
*/
NodoHotel *ListaHotel::buscarListaNombre(string destino) {
    NodoHotel *temp;
    for (temp = primero; temp != NULL; temp = temp->getSiguienteNodo()) {
        if (destino == temp->getNombreNodo())
            return temp;
    }
    return NULL;
}

NodoHotel *ListaHotel::buscarListaHabitacion(int destino) {
    NodoHotel *temp;
    for (temp = primero; temp != NULL; temp = temp->getSiguienteNodo()) {
        if (destino == temp->getHabitacionNodo())
            return temp;
    }
    return NULL;
}

void ListaHotel::visualizar() {
    NodoHotel *n;
    n = primero;
    while (n != NULL) {
        cout << "Nombre:     " << n->getNombreNodo() << endl;
        cout << "Habitacion: " << n->getHabitacionNodo() << "\n"<< endl;
        n = n->getSiguienteNodo();
    }
    cout << "\n" << endl;
}

void ListaHotel::visualizarAlreves() {
    NodoHotel *n;
    int k = 0;
    NodoHotel *ultimoNodo;
    n = primero;
    ultimoNodo = primero;
  
    while (n != NULL) {
        ultimoNodo = n;
        n = n->getSiguienteNodo();
    }
    while (ultimoNodo != NULL){
        cout << "Nombre:     " << ultimoNodo->getNombreNodo() << endl;
        cout << "Habitacion: " << ultimoNodo->getHabitacionNodo() << "\n"<< endl;
        ultimoNodo = ultimoNodo->getPrevioNodo();
    }
    
    cout << "\n" << endl;
}
/*
void ListaHotel::eliminarNombre(string entrada) {
    NodoHotel *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado) {
        encontrado = (actual->getNombreNodo() == entrada);
        if (!encontrado) {
            anterior = actual;
            actual = actual->getSiguienteNodo();
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != NULL) {
        // distingue entre cabecera y resto de la lista
        if (actual == primero) {
            primero = actual->getSiguienteNodo();
        } else {
            anterior->ponerSiguiente(actual->getSiguienteNodo());
        }
        delete actual;
    }
}*/
/*
void ListaHotel::eliminarHabitacion(int entrada) {
    NodoHotel *actual, *anterior;
    bool encontrado;
    actual = primero;
    anterior = NULL;
    encontrado = false;
    // búsqueda del nodo y del anterior
    while ((actual != NULL) && !encontrado) {
        encontrado = (actual->getHabitacionNodo() == entrada);
        if (!encontrado) {
            anterior = actual;
            actual = actual->getSiguienteNodo();
        }
    }
    // enlace del nodo anterior con el siguiente
    if (actual != NULL) {
        // distingue entre cabecera y resto de la lista
        if (actual == primero) {
            primero = actual->getSiguienteNodo();
        } else {
            anterior->ponerSiguiente(actual->getSiguienteNodo());
        }
        delete actual;
    }
}*/
