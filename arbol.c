/*
PRÁCTICA 01. ANÁLISIS DE ALGORITMOS DE ORDENAMIENTO. PRUEBAS A POSTERIORI
ARBOL
EQUIPO: Equipo Chipocludo.
AUTORES: Álvarez Méndez Laura
VERSION: 1.3
FECHA: 4/10/2021

En este archivo de lo que se realiza es una estructura de datos conocida como árbol, 
la cual tiene la funcion de busqueda implementada iterativamente
*/

#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"


Arbol* crearNodo(int dato){
    Arbol* temp = (Arbol*)malloc(sizeof(Arbol));
    temp->dato = dato; //Se guarda el dato en el nodo
    temp->izquierda = temp->derecha = NULL; //La parte derecha e izquierda apuntan a null
    return temp; //regresamos el nodo
}

Arbol* agregaNodo(Arbol* a, int dato){
    // Si el árbol está vacío, se crea un nuevo nodo 
    if (a == NULL){
      return crearNodo(dato);
    }
    /* Sino, se evalua el dato del nodo actual para guardar el dato, 
    ya sea a la izquierda o a la derecha*/
    if (dato < a->dato){
      a->izquierda = agregaNodo(a->izquierda, dato);
    }else{
      if (dato > a->dato){
        a->derecha = agregaNodo(a->derecha, dato);
      }
    } 

    //finalmente se retorna el nodo agregado
    return a;
}

int buscar(Arbol* raiz, int valor){
    // Buscamos en todos los nodos, partiendo desde la raiz hasta llegar al fondo
    while (raiz != NULL) {
        if (valor > raiz->dato){
          raiz = raiz->derecha; //pasamos al nodo derecho si el dato a buscar es mayor que el dato del nodo actual
        }else{
          if (valor < raiz->dato){
            raiz = raiz->izquierda;///pasamos al nodo izquierdo si el dato a buscar es menor que el dato del nodo actual
          }else{
            return raiz->dato; // si se encuentra el valor se retorna
          }
        }
    }
    return -1; // Si no se encuentran coincidencias regresa -1
}
