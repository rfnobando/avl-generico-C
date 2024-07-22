#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED


struct Nodo;
typedef struct Nodo * NodoPtr;


NodoPtr crearNodo(void *dato);
void destruirNodo(NodoPtr nodo);

void insertarDato(NodoPtr *nodo, void *dato, int (*comparar)(void *, void *));
int obtenerAltura(NodoPtr nodo);
int obtenerDiferenciaAltura(NodoPtr nodo);
void balancearArbol(NodoPtr *nodo);
void rotacionSimpleIzquierda(NodoPtr *nodo);
void rotacionSimpleDerecha(NodoPtr *nodo);

void preorden(NodoPtr nodo, void (*mostrarDato)(void *));
void inorden(NodoPtr nodo, void (*mostrarDato)(void *));
void postorden(NodoPtr nodo, void (*mostrarDato)(void *));

int busquedaBinaria(NodoPtr nodo, void *dato, int (*comparar)(void *, void *));


#endif // NODO_H_INCLUDED
