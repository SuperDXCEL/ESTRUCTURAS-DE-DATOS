#include "../header/Gestor.h"
#include "../header/NodoCola.h"
#include "../header/NodoPila.h"
#include "../header/NodoLista.h"
#include <iostream>
#include <cstddef>

int random_time() {
  int arrival_time = rand() % 61;
  std::cout << arrival_time << std::endl;
  return arrival_time;
}
int random_id(int max) {
  int id = rand() % max;
  std::cout << id << std::endl;
  return id;
}
Gestor::Gestor() {
  stack_ = new Pila();
  member_queue_ = new Cola();
  fan_queue_ = new Cola();
  list_ = new Lista();
  total_fans_ = 0;
}
Gestor::~Gestor() {
  // Call destructors
}
//void AficionadosEnPila();
//void SociosEnCola();
//void SimpatizantesEnCola();
//void AficionadosEnLista();
//void AficionadosEnArbol();
void Gestor::genera10Aficionados() {
  /**
   * Cada vez que se use esta opción el programa generará 10 aficionados aleatorios
   * con sus correspondientes ID único, hora de llegada y el tipo de aficionados que son (socio o simpatizante).
   * La primera vez que se use esta opción el ID del aficionado será un número aleatorio entre 1 y 10,
   * la segunda vez entre 11 y 20 y así sucesivamente.  
   */
  for (int i = total_fans_; i < (total_fans_+10); i++) {
    Aficionado* fan = new Aficionado(i, random_time());
    NodoPila* nodo = new NodoPila(fan, nullptr);
    stack_->push(nodo);
  }
  total_fans_ += 10;
}
void Gestor::muestraAficionados() {
  /**
   * Esta opción mostrará todos los aficionados almacenados en la pila.
   */
  while (stack_->get_size() > 0) {
    Aficionado* fan = stack_->pop();
    std::cout << fan << std::endl;
  }
}
