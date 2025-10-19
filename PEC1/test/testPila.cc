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

  //Push stack contents into queue
  Cola* cola = new Cola();
  Cola* colaC = new Cola();
  while (stack->get_size() != 0) {
    NodoPila* nodo = stack->pop();
    Aficionado* fan = nodo->get_aficionado();
    NodoCola* nodoCola1 = new NodoCola(fan, nullptr);
    NodoCola* nodoCola2 = new NodoCola(fan, nullptr);
    cola->insert(nodoCola1);
    colaC->insert(nodoCola2);
  }
  
  std::cout << "COLAC SIZE: " << colaC->get_size() << std::endl;

  cola->sort_list();
 
  NodoCola* head = cola->front();

  std::cout << "\n" << std::endl;
  std::cout << "MANUALLY GOING THROUGH NODES: \n" << std::endl;
  while (head) {
    std::cout << head->get_aficionado() << std::endl;
    head = head->get_next();
  }

  std::cout << "SHOW COLA" << std::endl;
  cola->show();

  colaC->sort_list();

  std::cout << "\nWITH POP(): \n" << std::endl;
  while(colaC->get_size() > 0) {
    NodoCola* nodo = colaC->pop();
    std::cout << nodo->get_aficionado() << std::endl;
  }
}
