#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"


struct Nodo {
    void *dato;
    NodoPtr izquierdo;
    NodoPtr derecho;
};


NodoPtr crearNodo(void *dato) {
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));

    nodo->dato = dato;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;

    return nodo;
}

void destruirNodo(NodoPtr nodo) {
    if(nodo == NULL) {
        return;
    }

    // Al destruir el nodo, tambien se destruye su descendencia
    destruirNodo(nodo->izquierdo);
    destruirNodo(nodo->derecho);
    free(nodo);
}

void insertarDato(NodoPtr *nodo, void *dato, int (*comparar)(void *, void *)) {
    if(*nodo == NULL) {
        return;
    }

    int comparacion = (*comparar)(dato, (*nodo)->dato);

    if(comparacion == 0) {
        return;
    }

    if(comparacion == -1) {
        if((*nodo)->izquierdo == NULL) {
            (*nodo)->izquierdo = crearNodo(dato);
        } else {
            insertarDato(&((*nodo)->izquierdo), dato, comparar);
        }
    }

    if(comparacion == 1) {
        if((*nodo)->derecho == NULL) {
            (*nodo)->derecho = crearNodo(dato);
        } else {
            insertarDato(&((*nodo)->derecho), dato, comparar);
        }
    }

    balancearArbol(nodo);

}


int obtenerAltura(NodoPtr nodo) {

    if(nodo == NULL){
        return 0;
    }

    int alturaIzquierdo = 0;
    int alturaDerecho = 0;

    alturaIzquierdo = obtenerAltura(nodo->izquierdo);
    alturaDerecho = obtenerAltura(nodo->derecho);

    if(alturaDerecho > alturaIzquierdo){
        return alturaDerecho + 1;
    } else {
        return alturaIzquierdo + 1;
    }

}

int obtenerDiferenciaAltura(NodoPtr nodo) {
    if(nodo == NULL) {
        return 0;
    }

    int alturaSubDerecho = obtenerAltura(nodo->derecho);
    int alturaSubIzquierdo = obtenerAltura(nodo->izquierdo);
    int diferenciaSubArboles = alturaSubDerecho - alturaSubIzquierdo;

    return diferenciaSubArboles;
}

void balancearArbol(NodoPtr *nodo) {
    int diferenciaAlturaSubArboles = obtenerDiferenciaAltura(*nodo);

    if(diferenciaAlturaSubArboles < -1) {
        if(obtenerDiferenciaAltura((*nodo)->izquierdo) <= -1) {
            rotacionSimpleDerecha(nodo);
        } else if(obtenerDiferenciaAltura((*nodo)->izquierdo) >= 1) {
            rotacionSimpleIzquierda(&((*nodo)->izquierdo));
            rotacionSimpleDerecha(nodo);
        }
    } else if(diferenciaAlturaSubArboles > 1) {
        if(obtenerDiferenciaAltura((*nodo)->derecho) >= 1) {
            rotacionSimpleIzquierda(nodo);
        } else if(obtenerDiferenciaAltura((*nodo)->derecho) <= -1) {
            rotacionSimpleDerecha(&((*nodo)->derecho));
            rotacionSimpleIzquierda(nodo);
        }
    }

}

void rotacionSimpleIzquierda(NodoPtr *nodo) {

    NodoPtr viejaRaiz = *nodo;
    NodoPtr subDerecho = (*nodo)->derecho;
    NodoPtr subIzquierdo = (*nodo)->izquierdo;
    NodoPtr subDerechoIzquierdo = (*nodo)->derecho->izquierdo;

    (*nodo)->derecho = NULL;
    (*nodo)->izquierdo = NULL;

    *nodo = subDerecho;
    viejaRaiz->derecho = subDerechoIzquierdo;
    viejaRaiz->izquierdo = subIzquierdo;
    (*nodo)->izquierdo = viejaRaiz;

}

void rotacionSimpleDerecha(NodoPtr *nodo) {

    NodoPtr viejaRaiz = *nodo;
    NodoPtr subIzquierdo = (*nodo)->izquierdo;
    NodoPtr subDerecho = (*nodo)->derecho;
    NodoPtr subIzquierdoDerecho = (*nodo)->izquierdo->derecho;

    (*nodo)->izquierdo = NULL;
    (*nodo)->derecho = NULL;

    *nodo = subIzquierdo;
    viejaRaiz->izquierdo = subIzquierdoDerecho;
    viejaRaiz->derecho = subDerecho;
    (*nodo)->derecho = viejaRaiz;

}

void preorden(NodoPtr nodo, void (*mostrarDato)(void *)) {
    if(nodo != NULL) {
        (*mostrarDato)(nodo->dato);
        preorden(nodo->izquierdo, mostrarDato);
        preorden(nodo->derecho, mostrarDato);
    }
}

void inorden(NodoPtr nodo, void (*mostrarDato)(void *)) {
    if(nodo != NULL) {
        inorden(nodo->izquierdo, mostrarDato);
        (*mostrarDato)(nodo->dato);
        inorden(nodo->derecho, mostrarDato);
    }
}

void postorden(NodoPtr nodo, void (*mostrarDato)(void *)) {
    if(nodo != NULL) {
        postorden(nodo->izquierdo, mostrarDato);
        postorden(nodo->derecho, mostrarDato);
        (*mostrarDato)(nodo->dato);
    }
}

int busquedaBinaria(NodoPtr nodo, void *dato, int (*comparar)(void *, void *)) {
    if(nodo == NULL) {
        return 0;
    }

    if(nodo->dato == NULL) {
        return 0; // El nodo no tiene dato
    }

    if((*comparar)(dato, nodo->dato) == 1) {
        return busquedaBinaria(nodo->derecho, dato, comparar);
    }

    if((*comparar)(dato, nodo->dato) == -1) {
        return busquedaBinaria(nodo->izquierdo, dato, comparar);
    }

    return 1;
}



