/*
PRÁCTICA 02. ANÁLISIS TEMPORAL
EQUIPO: Equipo Chipocludo.
AUTORES: Aguirre Álvarez Omar, Álvarez Méndez Laura, Bello Muñoz Edgar Alejandro, Bolaños Ramos Caleb Salomón
VERSION: 1
FECHA: 27/09/2021

Este archivo contiene los 5 algoritmos de busqueda a analizar en la practica 2 los cuales son:

1. Busqueda Lineal: 
• Comienza desde el elemento más a la izquierda de arreglo “A[]” de elementos y uno por uno compara el 
elemento buscado “x” con cada elemento de arreglo “A[]”

• Si “x” coincide con un elemento, devuelve el índice

• Si “x” no coincide con ninguno de los elementos, devuelve -1.

2. Busueda en Árbol Binario de Busqueda:  
• Implica la construcción previa de un ABB con los elementos del arreglo “A[]” de elementos en memoria 
y posteriormente una serie de consultas al árbol.

• Si “x” coincide con un elemento raíz, se termina la búsqueda e indica su valor, si no coincide 
se viaja al subárbol izquierdo si el elemento buscado es menor a la raíz o al subárbol derecho 
si el elemento buscado es mayor que la raíz.

• Si “x” no coincide con la raíz del subárbol, se vuelve a seguir el paso anterior si se llega a un árbol 
vacío se considera que el elemento no se encuentra

3. Busqueda Binaria:
• Se basa en el principio de que arreglo “A[]” donde se realiza la búsqueda está ordenado ascendentemente 
según algún criterio.

• Se consulta el elemento de en medio del arreglo y si este no coincide con el elemento buscado se compara 
si el elemento buscado puede estar del lado de los mayores (derecha) o menores (izquierda) y sabiendo el 
lado a consultar se vuelve a particionar el arreglo del lado correspondiente hasta no poder dividirlo más 
o encontrarlo.

4. Busqueda Exponencial:
• Se basa en el principio de que arreglo “A[]” donde se realiza la búsqueda está ordenado ascendentemente 
según algún criterio.

• Se encuentra el rango donde el elemento a buscar debería estar presente.

• Realiza una búsqueda binaria en el rango encontrado.

5. Busqueda de Fibonacci:
• Se basa en el principio de que arreglo “A[]” donde se realiza la búsqueda está ordenado ascendentemente 
según algún criterio.

• Divide un arreglo en partes desiguales.

• La búsqueda binaria usa el operador de división para dividir el rango, sin en
cambio la búsqueda de Fibonacci no usa “/”, pero usa “+” y “-”. Esto bajo la
idea que el operador de división puede resultar costoso en algunas CPU y se
intenta mejorar esto


*/
#include <stdio.h>
#include <math.h>
#include "arbol.c"
#include "tiempo.h"

#define TRUE 1
#define FALSE 0
#define TAMANO_A 20

void ImprimeArr(int array[]);
void Intercambio(int *x, int *y);

int busquedaLineal(int arr[], int n, int x);
int busquedaABB(int array[], int n, int x);
int busquedaBinariaMini(int array[], int n, int x);
int busquedaBinaria(int array[], int l, int r, int x);
int busquedaExponencial(int arr[], int n, int x);
int BusquedaDeFibonacci(int array[], int n, int x);
int min(int a, int b);
int *array;

int num; //elementos en el arreglo, indicará el número de enteros a buscar
double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos

int main(int argc, char *argv[]) {

    if (argc > 2) {
        int algoritmoBusqueda; //parámetro que representa que algoritmo de busqueda que se utilizará
        int valorABuscar, valorEncontrado;
        //se obtienen los primeros 3 parametros escritos en consola (los volvemos enteros)
        algoritmoBusqueda = atoi(argv[1]);
        num = atoi(argv[2]);
        valorABuscar = atoi(argv[3]);

        array = malloc(sizeof(int) * num);;
        int i;

        for (i = 0; i < num; ++i) { //recoge los valores del .txt gracias al redireccionamiento en la consola (<)
            scanf("%d", &array[i]);
        }

        
        printf("======================================================================\n");
        switch (algoritmoBusqueda) {
            case 1: //busqueda lineal
                printf("\nBusqueda lineal\n");
                valorEncontrado = busquedaLineal(array, num, valorABuscar);
                uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución
                break;
            case 2: //buesqueda en abb
                printf("Busqueda abb\n");
                valorEncontrado = busquedaABB(array, num, valorABuscar);
                uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución
                break;
            case 3: //busqueda binaria
                printf("Busqueda binaria\n");
                valorEncontrado = busquedaBinariaMini(array, num, valorABuscar);
                uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución
                break;
            case 4: //busqueda exponencial
                printf("Busqueda exponencial\n");
                valorEncontrado = busquedaExponencial(array, num, valorABuscar);
                uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución
                break;
            case 5: //busqueda de Fibonacci
                printf("Busqueda de Fibonacci\n");
                valorEncontrado = BusquedaDeFibonacci(array, num, valorABuscar);
                uswtime(&utime1, &stime1, &wtime1);//Evaluar los tiempos de ejecución
                break;
            default:
                exit(0);
                break;
        }

        //printf("\nContenido del arreglo:\n");
        //ImprimeArr(array);
        //printf("Num[%d]: %d.\n", num, array[num-1]);
        printf("\nTamaño del arreglo (n): %d\n", num);
        printf("\nElemento a buscar (x): %d\n", valorABuscar);
        printf("Coincidencias: %s\n", valorEncontrado != -1 ? "Si" : "No");

        //Mostrar los tiempos con 10 decimas
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");

        //Mostrar los tiempos en formato exponecial
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");
    }

    return 0;
}

void ImprimeArr(int array[]) {
    int i;
    printf("\n");
    for (i = 0; i < num; i++) {
        printf("Num[%d]: %d.\n", i + 1, array[i]);
    }
    printf("\n");
}

int busquedaLineal(int arr[], int n, int x){
    int i;
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1; // Si no se encuentran coincidencias retorna -1
}

int busquedaABB(int array[], int n, int x) {
    uswtime(&utime0, &stime0, &wtime0);

    int i;
    Arbol *a = NULL;    //Para guardar el árbol
    a = agregaNodo(a, array[0]);//creamos el árbol
    for (i = 1; i < n; i++) {
        //Creamos un nodo por cada i de nuestro array
        agregaNodo(a, array[i]);
    }
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);
    int resultado = buscar(a, x);
    return resultado;
}

int busquedaBinariaMini(int array[], int n, int x){
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    int l = 0;//izquierda 
    int r = n-1;//derecha
    return busquedaBinaria(array, l, r, x);

}

int busquedaBinaria(int array[], int l, int r, int x){
    
    while (l <= r) {
        int m = l + (r - l) / 2;
  
        // Checa que el valor a buscar esté en medio y retorna su posicion
        if (array[m] == x)
            return m;
  
        // Si el valor a buscar es mayor, se ignora el resto de la mitad de la izquierda
        if (array[m] < x)
            l = m + 1;
  
        // Si el valor a buscar es menor, se ignora el resto de la mitad de la derecha
        else
            r = m - 1;
    }
  
    return -1; // Si no se encuentran coincidencias se retorna -1
}

int busquedaExponencial(int array[], int n, int x){
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    // Checa si el valor a buscar se encuentra en la primera posición
    if (array[0] == x)
        return 0;
 
    // Se calcula un rango para la busqueda binaria elevando 2^n su paso y verificando 
    //que el index sea menor o igual al valor a encontrar
    int i = 1;
    while (i < n && array[i] <= x)
        i = i*2;
 
    //Se hace una busqueda binaria con el rango calculado.
    return busquedaBinaria(array, i/2, min(i, n-1), x);
}

int BusquedaDeFibonacci(int array[], int n, int x){
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);

    /* Inicializa los primeros números de Fibonacci */
    int fibMMm2 = 0; // (m-2)ésimo numero de Fibonacci.
    int fibMMm1 = 1; // (m-1)ésimo numero de Fibonacci.
    int fibM = fibMMm2 + fibMMm1; // (m)ésimo numero de Fibonacci
 
    /* la variable fibM se encargará de guardar el número de Fibonacci más 
    pequeño que sea menor o igual a n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marca el rango eliminado del frente
    int compensacion = -1;
 
    /* 
       El while se cumplira mientras haya elementos con los que se puede operar
       Dentro del while se compara que el valor de arr[fibMm2] con el valor a buscar
       Cuándo fibM toma el valor de 1, fibMm2 toma el valor de 0  */
    while (fibM > 1) {
        // Verifica que fibMm2 isea una valida locacion
        int i = min(compensacion + fibMMm2, n - 1);
 
        /* Si el número buscar es mayor que el valor en el index de fibMm2,
        se corta el rango del arreglo desde la compensasion hasta i*/
        if (array[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            compensacion = i;
        }
 
        /* Si el número buscar es menor que el valor en el index de fibMm2,
           se corta el rango después de i+1  */
        else if (array[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
 
        /* El valor a buscar es encontrado y se retorna su posicion */
        else
            return i;
    }
 
    /* Compara el ultimo elemento con el numero a encontrar */
    if (fibMMm1 && array[compensacion + 1] == x)
        return compensacion + 1;
 
    // Si no se encuentran coincidencias se retorna -1
    return -1;
}

int min(int a, int b){
    return (a < b ? a : b);// retorna el número más pequeño a través de un ternario
}
