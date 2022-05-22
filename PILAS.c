//
// Created by carca on 21/05/2022.
//

#include <stdio.h>
#define MAX 10

// Necesitamos:
//  1. Un arreglo en donde se guardarán los datos - int - de tamaño MAX
//  2. Un tope, indicador/índice que nos dirá en que posición del arreglo se encuentra el último datos que insertamos


typedef struct pila {
    int data[MAX];
    int top;
} Stack;

void setup(Stack *s);
int isEmpty(Stack stack);
int isFull(Stack stack);
int push(Stack *s, int value);
int pop(Stack *s, int *v);

int main(){

    Stack stack;

    setup(&stack);

    int r;
    int value;
    r = push(&stack, 5);
    r = push(&stack, 15);
    r = push(&stack, 25);
    r = push(&stack, 35);
    r = push(&stack, 45);
    r = push(&stack, 65);
    r = push(&stack, 75);
    r = push(&stack, 85);
    r = push(&stack, 95);
    r = push(&stack, 105);

    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);
    r = pop(&stack, &value);

    return 0;
}


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




















