#ifndef GESTOR_H_
#define GESTOR_H_

#include "../header/Pila.h"
#include "../header/Cola.h"
#include "../header/Lista.h"

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
 private:
  Pila* stack_;
  Cola* member_queue_;
  Cola* fan_queue_;
  Lista* list_;
  int total_fans_;
};
#endif //GESTOR_H_
