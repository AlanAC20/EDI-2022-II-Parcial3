#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "cola.h"

#define CIRCLE_SANDWICH 0
#define SQUARE_SANDWICH 1

void sell_sandwich(Cola *c, Stack *s);

int main(){

    Stack stack;
    Cola cola;
    Estudiante estudiante;

    // Inicializamos las estructuras
    inicializaCola(&cola);
    setup(&stack);

    // Insertar los sandwich
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, SQUARE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);

    // Formar a los estudiantes en la Cola
    strcpy(estudiante.nombre, "Juan");
    estudiante.sandwich = CIRCLE_SANDWICH;

    insertar(&cola, estudiante);

    strcpy(estudiante.nombre, "Angelica");
    estudiante.sandwich = CIRCLE_SANDWICH;

    insertar(&cola, estudiante);

    strcpy(estudiante.nombre, "Pedro");
    estudiante.sandwich = CIRCLE_SANDWICH;

    insertar(&cola, estudiante);

    strcpy(estudiante.nombre, "Chris");
    estudiante.sandwich = SQUARE_SANDWICH;

    insertar(&cola, estudiante);

    sell_sandwich(&cola, &stack);

    return 0;
}

void sell_sandwich(Cola *c, Stack *s){


    Estudiante estudianteActual;
    int sandwichActual;
    while (estaVacia(*c) == 0){ // Mientras la cola no esté vacía

        eliminar(c, &estudianteActual);
        pop(s, &sandwichActual);

        printf("\nEl estudiante %s quiere un sandwich: %d y en la pila hay: %d", estudianteActual.nombre, estudianteActual.sandwich, sandwichActual);

        if(estudianteActual.sandwich != sandwichActual){

            printf("\n\tNo se pudo entregar, regresando el estudiante a la cola y el sandwich a la pila.");
            insertar(c, estudianteActual);
            push(s, sandwichActual);

        } else{
            printf("\n\tEl sandwich se entrego");
        }
    }

}
















