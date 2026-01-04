#ifndef GESTOR_H_
#define GESTOR_H_

#include "../header/Pila.h"
#include "../header/Cola.h"
#include "../header/Lista.h"
#include "../header/Arbol.h"
#include <unordered_set>

class Gestor {
 public:
  Gestor();
  ~Gestor();
  int AficionadosEnPila();
  int SociosEnCola();
  int SimpatizantesEnCola();
  int AficionadosEnLista();
  int AficionadosEnArbol();
  void genera10Aficionados();
  void muestraAficionados();
  void borraAficionadosPila();
  void encolarAficionados();
  void muestraSociosCola();
  void muestraSimpatizantesCola();
  void borraAficionadosColas();
  void enlistarAficionados();
  void buscarAficionados();
  void reiniciar();
  void dibujarArbol();
  void mostrarSociosArbol();
  void mostrarSimpatizantesArbol();
  void mostrarTodosArbolInorden();
  void buscarAficionadosArbol();
  void contarAficionadosConIdentificadorPar();
  void mostrarAficionadosEnNodoHoja();
  void eliminarAficionado();
 private:
  void mostrarInorden(NodoArbol* nodo);
  void recogerAficionados(NodoArbol* nodo, Lista* lista);
  int contarNodos(NodoArbol* nodo);
  void mostrarHojas(NodoArbol* nodo);
  int contarPares(NodoArbol* nodo);
  Aficionado* buscarPorId(NodoArbol* nodo, int id);
  NodoArbol* eliminarNodo(NodoArbol* nodo, int id);
  Pila* stack_;
  Cola* member_queue_;
  Cola* fan_queue_;
  Lista* list_;
  int total_fans_;
  std::unordered_set<int> id_set_;
  Arbol* tree_;
};
#endif //GESTOR_H_
