#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"
#include "primitivos.h"


int main() {

    // Prueba con enteros

    int n1 = 25;
    int n2 = 20;
    int n3 = 27;
    int n4 = 18;
    int n5 = 15;
    int n6 = 11;
    int n7 = 23;
    int n8 = 24;
    int n9 = 9;
    int n10 = 30;
    int n11 = 32;

    int nInexistente = 22;

    NodoPtr raiz = crearNodo(&n1);

    insertarDato(&raiz, &n2, compararIntVoid);
    insertarDato(&raiz, &n3, compararIntVoid);
    insertarDato(&raiz, &n4, compararIntVoid);
    insertarDato(&raiz, &n5, compararIntVoid);
    insertarDato(&raiz, &n6, compararIntVoid);
    insertarDato(&raiz, &n7, compararIntVoid);
    insertarDato(&raiz, &n8, compararIntVoid);
    insertarDato(&raiz, &n9, compararIntVoid);
    insertarDato(&raiz, &n10, compararIntVoid);
    insertarDato(&raiz, &n11, compararIntVoid);

    printf("--------------- ARBOL AVL DE ENTEROS ---------------\n\n");

    printf("---------- PREORDEN ----------\n");
    preorden(raiz, mostrarIntVoid);
    printf("\n\n");

    printf("---------- INORDEN ----------\n");
    inorden(raiz, mostrarIntVoid);
    printf("\n\n");

    printf("---------- POSTORDEN ----------\n");
    postorden(raiz, mostrarIntVoid);
    printf("\n\n");

    int busqueda32 = busquedaBinaria(raiz, &n11, compararIntVoid);
    int busqueda22 = busquedaBinaria(raiz, &nInexistente, compararIntVoid);

    printf("\n---------- RESULTADOS DE LA BUSQUEDA ----------\n");
    printf("1 = EXISTE EN EL ARBOL ; 0 = NO EXISTE EN EL ARBOL\n\n");
    printf("BUSQUEDA NUMERO 32: %d\n", busqueda32);
    printf("BUSQUEDA NUMERO 22: %d\n", busqueda22);

    destruirNodo(raiz);

    printf("\n\n\n\n");



    // Prueba con cadenas

    char s1[15] = "Dario";
    char s2[15] = "Bernardo";
    char s3[15] = "Carlos";
    char s4[15] = "Federico";
    char s5[15] = "Gabriel";
    char s6[15] = "Rodrigo";
    char s7[15] = "Tomas";

    char sInexistente[15] = "Roberto";

    raiz = crearNodo(s1);

    insertarDato(&raiz, s2, compararStringVoid);
    insertarDato(&raiz, s3, compararStringVoid);
    insertarDato(&raiz, s4, compararStringVoid);
    insertarDato(&raiz, s5, compararStringVoid);
    insertarDato(&raiz, s6, compararStringVoid);
    insertarDato(&raiz, s7, compararStringVoid);

    printf("--------------- ARBOL AVL DE CADENAS ---------------\n\n");

    printf("---------- PREORDEN ----------\n");
    preorden(raiz, mostrarStringVoid);
    printf("\n\n");

    printf("---------- INORDEN ----------\n");
    inorden(raiz, mostrarStringVoid);
    printf("\n\n");

    printf("---------- POSTORDEN ----------\n");
    postorden(raiz, mostrarStringVoid);
    printf("\n\n");

    int busquedaBernardo = busquedaBinaria(raiz, s2, compararStringVoid);
    int busquedaRoberto = busquedaBinaria(raiz, sInexistente, compararStringVoid);

    printf("\n---------- RESULTADOS DE LA BUSQUEDA ----------\n");
    printf("1 = EXISTE EN EL ARBOL ; 0 = NO EXISTE EN EL ARBOL\n\n");
    printf("BUSQUEDA CADENA \"Bernardo\": %d\n", busquedaBernardo);
    printf("BUSQUEDA CADENA \"Roberto\": %d\n", busquedaRoberto);

    destruirNodo(raiz);

    printf("\n");


    return 0;
}
