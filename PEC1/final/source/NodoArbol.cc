#include "../header/NodoArbol.h"

NodoArbol::NodoArbol(Aficionado* aficionado)
{
    this->dato = aficionado;
    this->izq = nullptr;
    this->der = nullptr;
}

Aficionado* NodoArbol::get_dato() {
    return dato;
}

NodoArbol* NodoArbol::get_izq() {
    return izq;
}

NodoArbol* NodoArbol::get_der() {
    return der;
}

void NodoArbol::set_izq(NodoArbol* nodo) {
    izq = nodo;
}

void NodoArbol::set_der(NodoArbol* nodo) {
    der = nodo;
}

NodoArbol::~NodoArbol() {}