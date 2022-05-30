//
// Created by carca on 22/05/2022.
//


#include<stdio.h>
#define MAX 10
typedef struct
{
    int tam;
    int frente, final;
    int fila[MAX];
}FILA;

int tamFila();
int iniciarFila(FILA *f, int tm);
int inDatoFila(FILA *f, int dato);
int exDatoFila(FILA *f, int *dato);
int borrarPos();
void capturarFila(FILA *f);
void RecorreDatos(FILA *f, int k);
void muestraFila(FILA *f);

int main()
{
    FILA fil;
    int tamF,posK;

    tamF=tamFila();
    posK=borrarPos();
    iniciarFila(&fil, tamF);
    capturarFila(&fil);
    RecorreDatos(&fil,posK);
    muestraFila(&fil);
}

int tamFila(){

    int tmf;
    printf("N= ");
    scanf("%d", &tmf);
    return tmf;
}


int borrarPos(){

    int k;
    printf("K= ");
    scanf("%d",&k);
    return k;
}


int iniciarFila(FILA *f, int tm)
{
    int res=0;
    if(tm <= MAX)
    {
        f->tam = tm;
        f->frente = f->final= -1;
        res = 1;
    }
    return res;
}


int inDatoFila(FILA *f, int dato)
{
    int res = 0;
    if(f->final + 1 < f->tam)
    {
        f->final++;
        f->fila[f->final] = dato;
        if(f->frente < 0)
            f->frente = 0;
        res = 1;
    }
    return res;
}


int exDatoFila(FILA *f, int *dato)
{
    int res = 0;
    if(f->frente > -1)
    {
        *dato = f->fila[f->frente];
        if(f->frente == f->final)
            f->frente = f->final=-1;
        else
            f->frente++;
        res = 1;
    }
    return res;
}


void capturarFila(FILA *f)
{
    int res, dato;
    char resp;
    do
    {
        printf("Dame un dato: ");
        scanf("%d",&dato);

        res = inDatoFila(f, dato);
        if(res == 1)
        {
            printf("Dato formado, Desea introducir otro (s/n) ");
            fflush(stdin);
            scanf("%c",&resp);
        }
        else
            printf("Dato no ingresado \n");
    }while(res == 1 && resp == 's');
}


void RecorreDatos(FILA *f, int k)
{
    int i,dato, aux;
    while(f->frente < f->final)
    {
        for(i = k-1; i > f->frente; i--)
            f->fila[i] = f->fila[i-1];
        f->frente++;
        aux = f->fila[f->frente];
        for(i = f->frente; i <= f->final; i++)
            f->fila[i-1] = f->fila[i];
        f->fila[f->final] = aux;
        k++;
    }
}


void muestraFila(FILA *f)
{
    int dato;
    while(exDatoFila(f, &dato) == 1)
        printf("%d \n", dato);
}