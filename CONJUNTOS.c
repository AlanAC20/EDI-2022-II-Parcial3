//
// Created by carca on 16/05/2022.
//

// Set - Conjunto
// 1.   Grupo de elementos que no se repite
// 2.   Operaciones:
//      2.1 Agregar al conjunto - Verificar que el elemento no existe dentro del conjunto - Si hay espacio
//      2.2 Eliminar un elemento de un conjunto - Exista - Elimina
//      2.3 Pertenencia - Elemento X pertenece al conjunto
// 3. Operaciones entre conjuntos. Dado dos conjuntos.
//      3.1 Calcular su intereección - Valores comunes a los dos conjuntos


//      3.2 Unón - Todos los elementos de A + Todos los elementos de B sin repetidos
//      3.3 Complemento - Complemento de A. Todos los elemnentos que no pertenezcan a A
//      3.4 Diferencia - A - B. Todo lo que esté en A que no esté en B


#include <stdio.h>
#define SET_CAPACITY 10

typedef struct set{

    int data[SET_CAPACITY];
    int size;       //cuantos elementos se han insertado en el conjunto
}Set;

void init_set(Set *s);
int add(Set *s, int value);
int find(Set set, int value);
int remove_set(Set *s, int value);
int exist(Set set, int value);
void intersect(Set setA, Set setB, Set *setC);
void print_set(Set set);
void union_set(Set setA, Set setB, Set *setC);
void complement_set(Set setA, Set setB, Set *setC);
void diference_set(Set setA, Set setB, Set *setC);

void main() {

    Set setA;
    Set setB;
    Set setC;

    init_set(&setA);
    add(&setA, 23);
    add(&setA, 11);
    add(&setA, 16);
    add(&setA, 5);
    add(&setA, 7);

    init_set(&setB);
    add(&setB, 10);
    add(&setB, 11);
    add(&setB, 21);
    add(&setB, 5);

    init_set(&setC);

    printf("SET A:\t");
    print_set(setA);
    printf("SET B:\t");
    print_set(setB);
    printf("SET C:\t");
    print_set(setC);


    printf("\n\n");
    intersect(setA, setB, &setC);
    printf("\n\n");
    printf("INTERSECT OF A + B: \n");
    print_set(setC);

    init_set(&setC);
    printf("\nUNION OF A + B: \n");
    union_set(setA, setB, &setC);
    print_set(setC);

    init_set(&setC);
    printf("\nCOMPLEMENT OF A + B\n");
    complement_set(setA, setB, &setC);
    print_set(setC);

    init_set(&setC);
    printf("\nCOMPLEMENT OF B + A\n");
    complement_set(setB, setA, &setC);
    print_set(setC);

    init_set(&setC);
    printf("\nDIFERENCE A - B\n");
    diference_set(setA, setB, &setC);
    print_set(setC);

    init_set(&setC);
    printf("\nDIFERENCE B - A\n");
    diference_set(setB, setA, &setC);
    print_set(setC);

}

void init_set(Set *s){

    s->size = 0; //para asegurar que al principio está vacío
}

int add(Set *s, int value){

    int exists = 0;
    int result = 0;
    // Si hay espacio y el valor no existe en el conjunto
    if(s->size < SET_CAPACITY){  //si hay espacio

        //find es una función que busca el valor dentro del conjunto(búsqueda binaria)
        //regresa -1 si no lo encontró y si no regresa el índice en donde se encuentra

        exists = find(*s, value);
        if(exists == -1){ // No encontró el valor

            //insertar el valor en el arreglo de forma ordenada
            // Vamos a empezar a revisar desde la posición size-1 mientras el valor que esté en la posición
            // sea mayor al valor que voy a insertar -> lo recorra

            int index;

            for (index = s->size-1; index >= 0 && s->data[index] > value; --index){
                s->data[index +1] = s->data[index];
            }
            s->data[index + 1] = value;
            s->size++;
            result = 1;
        }
    }
    return result;
}

int remove_set(Set *s, int value){

    //Find regresa -1 cuando no encuentra el valor
    //      y la posición si es que se encuentra

    int index = find(*s, value);

    if(index != -1)  //Si lo encontró
    {
        s->size--;
        for (index = index ; index <= s->size -1; ++index) {

            s->data[index] = s->data[index + 1];
        }
        return 1;
    }
    return 0;
}

int find(Set set, int value){

    //Esta función debe buscar el valor value dentro
    // del arreglo set.data y regresar -1 si no lo encontró y el índice donde se encuentra  si si lo encontró
    //usando búsqueda binaria

    int inicio = 0;
    int fin = set.size -1;
    int mitad;
    int encontrado = 0;

    //Mientras los índices no se crucen y no haya encontrado el valor
    while(inicio <= fin && encontrado == 0){
        mitad = inicio + (fin - inicio) / 2;

        if(set.data[mitad] == value)
            encontrado = 1;
        else
        if(set.data[mitad] > value) // Seguiría buscando en la mitad inferior
            fin = mitad -1;
        else // Seguiría buscando en la mitad superior
            inicio = mitad + 1;
    }

    if(encontrado == 1)
        return mitad;
    else
        return -1;
}

int exist(Set set, int value){

    int index = find(set, value);

    if(index == -1)
        return 0; //No existe
    return 1;
}

void intersect(Set setA, Set setB, Set *setC){

    int e;
    for (int index = 0; index < setA.size; ++index)
    {
        printf("setA.data[%d] = %d\n", index, setA.data[index]);
        e = exist(setB, setA.data[index]);
        if(e == 1)
        {
            printf("\t%d exists in B\n", setA.data[index]);
            add(setC, setA.data[index]);
        }
    }
}

void print_set(Set set){

    printf("[ ");
    for (int index = 0; index < set.size; ++index){

        printf("%d ", set.data[index]);
    }
    printf("]\n");

}

void union_set(Set setA, Set setB, Set *setC){

    int index;
    int e;

    for(index = 0; index < setA.size; index++){
        add(setC, setA.data[index]);
    }

    for(index = 0; index < setB.size; index++){
        e = exist(*setC, setB.data[index]);
        if(e == 0)
            add(setC, setB.data[index]);
    }
}


void complement_set(Set setA, Set setB, Set *setC) {
    int e;
    for (int index = 0; index < setB.size; ++index) {

        e = exist(setA, setB.data[index]);
        if(e == 0)
            add(setC, setB.data[index]);
    }
}

void diference_set(Set setA, Set setB, Set *setC){

    int e;
    for (int index = 0; index < setA.size; ++index) {
        e = exist(setB, setA.data[index]);
        if(e == 0)
            add(setC, setA.data[index]);
    }
}







