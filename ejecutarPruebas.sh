#!/bin/bash

# PRÁCTICA 01. ANÁLISIS DE ALGORITMOS DE ORDENAMIENTO. PRUEBAS A POSTERIORI
# Script de Bash para ejecutar todas las pruebas de n
# EQUIPO: Equipo Chipocludo.
# AUTORES: Bolaños Ramos Caleb Salomon
# VERSION: 1.0
# FECHA: 4/10/2021
# En este script de bash se compila algoritmos.c para despues hacer todas 
# las pruebas en todoso los algortimos de busqueda


gcc algoritmos.c tiempo.c -o a.out

#numeros a buscar
A=( 322486 14700764 3128036 6337399 61396 10393545 2147445644 1295390003 450057883 187645041 1980098116 152503 5000 1493283650 214826 1843349527 1360839354 2109248666 2147470852 0)
#n
tamano_problema=(1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000);





for algoritmo_busqueda in {1..2};
  do
    for n in "${tamano_problema[@]}"
	do
	   	for x in "${A[@]}"
		do
		   ./a.out $algoritmo_busqueda "$n" "$x" <numeros10millones.txt >> resultados"$algoritmo_busqueda".txt
		done
	done
done

for algoritmo_busqueda in {3..5};
  do
    for n in "${tamano_problema[@]}"
	do
	   	for x in "${A[@]}"
		do
		   ./a.out $algoritmo_busqueda "$n" "$x" <10millones.txt >> resultados"$algoritmo_busqueda".txt
		done
	done
done

