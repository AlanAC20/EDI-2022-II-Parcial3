#include "common.h"


typedef struct pila {
    int data[MAX];
    int top;
} Stack;

//Inicializa el tope de la pila (top)
void setup(Stack *s){

    s->top = -1;  // Se inicializa en -1 porque no es un índice válido del arreglo
    // Nos indica que la pila está vacía
}

// Regresa 1 si la pila está vacía 0 en caso contrario
int isEmpty(Stack stack){

    if(stack.top == -1)
        return 1;
    return 0;

}


//Regrese 1 cuando la pila está llena y 0 en caso contrario
int isFull(Stack stack){

    return(stack.top == MAX - 1) ? 1 : 0;
}


// Inserta un valor (value) en la pila
// Regresa 1 si pudo insertar y 0 si no

int push(Stack *s, int value){

    int r = 0;
    if(isFull(*s) == 0){

        s->top++;
        s->data[s->top] = value;
        r = 1;
    }
    return r;
}


// Elimina el elemento del tope de la pila
// Regresa 1 si pudo eliminar y 0 si no
// Regresa el dato que eliminó
int pop(Stack *s, int *v){

    if(!isEmpty(*s)) { // Si no está vacía

        *v = s->data[s->top];
        s->top--;
        return 1;
    }
    return 0;
}