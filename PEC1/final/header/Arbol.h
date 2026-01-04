#ifndef ARBOL_H
#define ARBOL_H

#include "NodoArbol.h"
#include <vector>

using namespace std;

class Arbol {
 public:
  Arbol();
  NodoArbol* get_raiz();
  void insertar(Aficionado* aficionado);
  void pintar();
  void dibujar();
  ~Arbol();
 private:
  NodoArbol* raiz;
  NodoArbol* insertarEnArbol(NodoArbol*, Aficionado* aficionado);
  void pintar(NodoArbol*);
  int altura(NodoArbol*);
  void dibujarNodo(vector<string>& output, vector<string>& linkAbove, NodoArbol* nodo, int nivel, int minPos, char linkChar);
};

#endif // ARBOL_H
