#ifndef PRIMITIVOS_H_INCLUDED
#define PRIMITIVOS_H_INCLUDED


/// Int
void mostrarInt(int a);
void mostrarIntVoid(void *a);
int compararInt(int a, int b);
int compararIntVoid(void *a, void *b);


/// String (char *)
void mostrarString(char a[]);
void mostrarStringVoid(void *a);
int compararString(char a[], char b[]);
int compararStringVoid(void *a, void *b);


#endif // PRIMITIVOS_H_INCLUDED
