#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "primitivos.h"


int compararInt(int a, int b) {
    return (a < b) ? -1 : (a > b) ? 1 : 0;
}

int compararIntVoid(void *a, void *b) {
    return compararInt(*(int *)a, *(int *)b);
}

int compararString(char a[], char b[]) {
    return strcmp(a, b);
}

int compararStringVoid(void *a, void *b) {
    return compararString((char *)a, (char *)b);
}

void mostrarInt(int a) {
    printf("{ %d }", a);
}

void mostrarIntVoid(void *a) {
    mostrarInt(*(int *)a);
}

void mostrarString(char a[]) {
    printf("{ %s }", a);
}

void mostrarStringVoid(void *a) {
    mostrarString((char *)a);
}
