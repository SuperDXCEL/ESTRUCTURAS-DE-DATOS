#include <iostream>
#include "../header/Pila.h"
#include "../header/Cola.h"
#include <cstdlib>

int random_time() {
  int arrival_time = rand() % 61;
  std::cout << arrival_time << std::endl;
  return arrival_time;
}

int random_id() {
  int id = rand() % 102930;
  std::cout << id << std::endl;
  return id;
}

int main(int argc, char** argv) {
  Pila* stack = new Pila();
  NodoPila* next = nullptr;
  for (int i = 0; i < 10; i++) {
    Aficionado* new_fan = new Aficionado(random_id(), random_time());
    NodoPila* nodo = new NodoPila(new_fan, next);
    next = nodo;
    stack->push(nodo);
  }
  while (stack->get_size() != 0) {
    NodoPila* nodo = stack->pop();
    if (stack->get_size() % 2 == 0) {
      delete nodo;  
    } else {
        Aficionado* fan = nodo->get_aficionado();
        std::cout << fan << std::endl;
    }
  }
}
