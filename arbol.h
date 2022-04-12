/*
PRÁCTICA 01. ANÁLISIS DE ALGORITMOS DE ORDENAMIENTO. PRUEBAS A POSTERIORI
ARBOL
EQUIPO: Equipo Chipocludo.
AUTORES: Álvarez Méndez Laura
VERSION: 1.3
FECHA: 4/10/2021

En este archivo lo que se realiza es una estructura de datos conocida como árbol
*/

typedef struct arbol{
  int dato; 
  struct arbol *izquierda;//apuntador a hijo der
  struct arbol *derecha; //apuntador a hijo izq
}Arbol;



