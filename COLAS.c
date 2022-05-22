//
// Created by carca on 19/05/2022.
//

#include <stdio.h>

#define MAX 10 // capacidad de la cola

typedef struct cola {
    int datos[MAX + 1];
    int inicio;
    int fin;
}Cola;

void inicializaCola(Cola *c);   //Encabezado
int estaVacia(Cola cola);
int estaLlena(Cola cola);
int insertar(Cola *c, int valor);
int eliminar(Cola *c, int *v);



int main(){

    Cola cola;
    int r;
    int valor;

    inicializaCola(&cola);

    r = estaVacia(cola);
    printf("Valor de r: %d", r);

    r = insertar(&cola, 7);
    r = insertar(&cola, 18);
    r = insertar(&cola, 3);
    r = insertar(&cola, 13);
    r = insertar(&cola, 23);

    r = insertar(&cola, &valor);
    r = insertar(&cola, &valor);
    r = insertar(&cola, &valor);

    return 0;
}

int eliminar(Cola *c, int *v){

    int r = 0;

    if(estaVacia(*c) == 0){  // !estavacia(*c)
        *v = c->datos[c->inicio];

        c->inicio = (c->inicio + 1) % (MAX + 1);
        r = 1;
    }
    return r;
}


int insertar(Cola *c, int valor){

    int r = 0;

    if(estaLlena(*c) == 0) { //Hay espacio para insertar, la cola no está llena

        //Poner el valor dentro del arreglo en la posición que dice fin
        c->datos[c->fin] = valor;

        //Mover fin a la siguiente casilla libre
        c->fin++; // Incremento el valor de fin

        if(c->fin == MAX + 1)
            c->fin = 0;

        // c->fin = (c->fin + 1) % (MAX + 1);

        r = 1;
    }

    return r;
}


int estaVacia(Cola cola){


    if(cola.inicio == cola.fin)
        return 1;
    return 0;
}


int estaLlena(Cola cola){

    if(cola.fin == cola.inicio -1 || (cola.inicio == 0 && cola.fin == MAX))
        return 1;

    return 0;
}


void inicializaCola(Cola *c){

    c->fin = 0;
    c->inicio = 0;
}


// Las operaciones básicas sobre la cola son:
//      1. INICIALIZARLA - Asegurarnos que al inicio todo está en orden para usarla.
//      2. SABER CUANDO ESTÁ LLENA. Si fin está una posicicón antes que inicoo entonces está llena y debe regresar un 1
//      3. SABER CUANDO ESTÁ VACÍA. Si inicio es igual a fin entonces la cola está vacía y debe regresar 1, 0 en caso contrario
//      4. INSERTAR (enqueque). Regresar 1 si se pudo insertar y 0 si no.
//          4.1 Preguntar si hay espacio en la cola. Que no esté llena
//          4.2 Inserta en la posición que me dice fin
//          4.3 Incremento fin
//      5. ELIMINAR (dequeque). Regresamos 1 si se pudo sacar de la cola y 0 si no
//          5.1 Preguntar si hay valores en la cola. Es decir, que no está vacía
//          5.2 Obtenemos el valor que está en la posición inicio
//          5.3 Regresamos ese valor
//          5.4 Incrementamos inicio