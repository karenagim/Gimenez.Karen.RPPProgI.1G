#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMNOT 5
typedef struct
{
    int id;
    int procesador;
    char marca[20];
    float precio;

}Notebook;


float aplicarDescuento(int precioProd);
int contarCaracteres(char cadena[], char caracter);
void ordenarNotebooks(Notebook lista[],int tam);

int main()
{
      char letras[]= {'r', 'e', 'c','u', 'p', 'e', 'r','a','t', 'o', 'r', 'i','o'};
      printf("La cantidad es : %d\n\n",contarCaracteres(letras,'r'));

        int precioProd =1000;
        float conDescuento= aplicarDescuento(precioProd);
        printf("El precio $ %d , con el descuento queda: %.2f\n",precioProd,conDescuento);

     Notebook notebooks [TAMNOT]=
     {
         {1, 111,"PCBOX",1500.50},
         {2,222,"SORNY",1800.50},
         {3,777,"COMMODORE",3000},
         {4,888,"DELL",7000.80},
         {5,999,"MAC",7500}
     };


    ordenarNotebooks(notebooks,TAMNOT);
    printf(" ID   Procesador        Marca         Precio\n\n");
    for(int i=0; i<TAMNOT; i++)
    {
        printf(" %d     %d        %6s       %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }


    return 0;
}

//------EJERCICIO 1




float aplicarDescuento(int precioProd)
{
    float precioConDescuento;
    precioConDescuento=precioProd -precioProd*5/100;
    return precioConDescuento;
}

//------EJERCICIO 2


int contarCaracteres(char cadena[], char caracter)
{
    int contador = 0;
    int largo = strlen(cadena);

    for(int i=0; i<largo;i++)
    {
        if(cadena[i]== caracter)
        {
            contador++;
        }
    }
    return contador;
}
//------EJERCICIO3

void ordenarNotebooks(Notebook lista[],int tam)
{
    Notebook aux;

    for (int i=0; i<tam-1;i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            if(strcmp(lista[i].marca,lista[j].marca)> 0)
            {
                aux= lista[i];
                lista[i]=lista[j];
                lista[j]= aux;
            }
            else if(strcmp(lista[i].marca,lista[j].marca)==0 && lista[i].precio<lista[j].precio)
            {
                aux= lista[i];
                lista[i]=lista[j];
                lista[j]= aux;
            }
        }
    }
}
