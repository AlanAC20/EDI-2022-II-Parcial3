#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Archivos{
    char name[50];
    char lastName[50];
    float prom;
}Alumnos;

int LeerAlumnos(char *filename, Alumnos *alm);
void OrdenaQuick(Alumnos *Arr1, int b, int c);
void OrdenaAlumnos(Alumnos *alumnos, int a);
void ImprimeAlumnos(Alumnos *alumnos, int a);

int main()
{
    Alumnos alumnos[MAX];

    int tam;

    fopen("ejemplo.txt", "r");
    tam = LeerAlumnos("./aprendizaje2.dat", alumnos);
    OrdenaAlumnos(alumnos,tam);
    ImprimeAlumnos(alumnos,tam);

    return 0;
}


int LeerAlumnos(char *filename, Alumnos *alm)
{
    FILE* fp;

    fp=fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("El archivo no se encontro");
        return 0;
    }

    int a = fread(alm, sizeof(Alumnos), MAX, fp);

    if(fclose(fp) == EOF)
        printf("No se pudo cerrar el archivo");

    return a;
}


void OrdenaQuick(Alumnos *Arr1, int b, int c)
{

    if(b >= c)
        return;

    Alumnos arr = Arr1[c];
    int i = b - 1;

    for(int j = b; j <= c - 1; j++)
    {
        if(strcmp(Arr1[j].lastName, arr.lastName) < 0)
        {
            i++;
            Alumnos aux = Arr1[i];
            Arr1[i] = Arr1[j];
            Arr1[j] = aux;
        }
    }

    Alumnos aux= Arr1[i + 1];
    Arr1[i + 1] = Arr1[c];
    Arr1[c] = aux;

    int aux2 = (i + 1);
    OrdenaQuick(Arr1, b, aux2 - 1);
    OrdenaQuick(Arr1, aux2 + 1, c);
}


void OrdenaAlumnos(Alumnos *alumnos, int a)
{
    OrdenaQuick(alumnos, 0, a - 1);
}


void ImprimeAlumnos(Alumnos *alumnos, int a)
{
    for(int i = 0; i < a; i++)
        printf("%s, %s: %.1f \n", alumnos[i].lastName, alumnos[i].name, alumnos[i].prom);
}