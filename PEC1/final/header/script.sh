#!/bin/bash

array=("Aficionado" "NodoPila" "NodoCola" "NodoLista" "Pila" "Cola" "Lista" "Gestor")

for str in ${array[@]}; do
  touch "$str".cc
done
