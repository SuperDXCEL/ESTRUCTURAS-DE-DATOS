#ifndef GESTOR_H_
#define GESTOR_H_

#include "../header/Pila.h"
#include "../header/Cola.h"
#include "../header/Lista.h"

class Gestor {
 public:
  Gestor();
  ~Gestor();
  void AficionadosEnPila();
  void SociosEnCola();
  void SimpatizantesEnCola();
  void AficionadosEnLista();
  void AficionadosEnArbol();
  //void genera10Aficionados();
  void muestraAficionados();
 private:
  Pila* stack_;
  Cola* member_queue_;
  Cola* fan_queue_;
  Lista* list_;
  int total_fans_;
};
#endif //GESTOR_H_
