#include "../header/Gestor.h"
#include <iostream>
#include <cstdlib>

int random_time() {
  int arrival_time = rand() % 61;
  std::cout << arrival_time << std::endl;
  return arrival_time;
}
int random_id(int max) {
  int id = rand() % (max + 1);
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
  delete stack_;
  delete member_queue_;
  delete fan_queue_;
  delete list_;
  stack_ = nullptr;
  member_queue_ = nullptr;
  fan_queue_ = nullptr;
  list_ = nullptr;
}
int Gestor::AficionadosEnPila() {
  if (stack_)
    return stack_->get_size();
  return 0;
}
int Gestor::SociosEnCola() {
  if (member_queue_)
    return member_queue_->get_size();
  return 0;
}
int Gestor::SimpatizantesEnCola() {
  if (fan_queue_)
    return fan_queue_->get_size();
  return 0;
}
int Gestor::AficionadosEnLista() {
  if (list_)
    return list_->get_size();
  return 0;
}
//int AficionadosEnArbol();
void Gestor::genera10Aficionados() {
  /**
   * Cada vez que se use esta opción el programa generará 10 aficionados aleatorios
   * con sus correspondientes ID único, hora de llegada y el tipo de aficionados que son (socio o simpatizante).
   * La primera vez que se use esta opción el ID del aficionado será un número aleatorio entre 1 y 10,
   * la segunda vez entre 11 y 20 y así sucesivamente.  
   */
  for (int i = 0; i <= 10; i++) {
    Aficionado* fan = new Aficionado(total_fans_+10, random_time());
    stack_->push(fan);
  }
  total_fans_ += 10;
}
void Gestor::muestraAficionados() {
  /**
   * Esta opción mostrará todos los aficionados almacenados en la pila.
   */
  if (stack_->get_size() > 0) {
	  Pila* stackCopy = new Pila(stack_);
	  while (stackCopy->get_size() > 0) {
	    Aficionado* fan = stackCopy->pop();
	    std::cout << fan << std::endl;
	  }
    delete stackCopy;
  }
}
void Gestor::borraAficionadosPila() {
  /**
   * Esta opción borrará todos los aficionados almacenados en la pila y generados en la opción A.
   */
  while (stack_->get_size() > 0) {
    Aficionado* fan = stack_->pop();
  }
}
void Gestor::encolarAficionados() {
  /**
   * Esta opción extraerá los aficionados de la pila y los almacenará en la cola de socios o en la
   * cola de simpatizantes en función del tipo de aficionado.
   */
  while (stack_->get_size() > 0) {
    Aficionado* fan = stack_->pop();
    fan->get_member() ? member_queue_->insert(fan) : fan_queue_->insert(fan); 
  }
}
void Gestor::muestraSociosCola() {
  /**
   * Esta opción mostrará la cola de aficionados que son socios.
   */
  Cola queue_copy = *member_queue_;
  while (queue_copy.get_size() > 0) {
    Aficionado* fan = queue_copy.pop();
    std::cout << fan << std::endl;  
  }
}
void Gestor::muestraSimpatizantesCola() {
  /**
   * Esta opción mostrará la cola de aficionados que son simpatizantes.
   */
  Cola queue_copy = *fan_queue_;
  while (queue_copy.get_size() > 0) {
    Aficionado* fan = queue_copy.pop();
    std::cout << fan << std::endl;  
  }
}
void Gestor::borraAficionadosColas() {
  /**
   * Esta opción borrará los aficionados almacenados en ambas colas.
   */
  if (member_queue_) {
    member_queue_;
    member_queue_ = new Cola();
  }
  if (fan_queue_) {
    delete fan_queue_;
    fan_queue_ = new Cola();
  }
}
void Gestor::enlistarAficionados() {
  /**
   * Esta opción extraerá los aficionados de las colas de aficionados y los almacenará en una 
   * lista de forma ordenada. Es decir, se empezará extrayendo los aficionados que hay en la
   * cola de socios y se almacenarán en la lista de forma ordenada en función de la hora de
   * llegada de cada socio.
   * Una vez se hayan insertado todos los socios se hará lo mismo con los
   * simpatizantes que también estarán ordenados en función de su hora de llegada.
   */
  member_queue_->sort_list();
  while (member_queue_->get_size() > 0) {
    Aficionado* fan = member_queue_->pop();
    list_->append(fan);
  }
  while (fan_queue_->get_size() > 0) {
    Aficionado* fan = fan_queue_->pop();
    list_->append(fan);
  }
}
void Gestor::buscarAficionados() {
  /**
   * Esta opción buscará en la lista y mostrará los siguientes 4 aficionados:
   *   - El primer aficionado en acceder al estadio.
   *   - El último socio en acceder al estadio.
   *   - El primer simpatizante en acceder al estadio.
   *   - El último aficionado en acceder al estadio.
   */
  //Need to implement copy operator, without it shallow copy means
  //Lista object and Lista* list_ point to the same nodes,
  //which deletes the list_ object after scope of Lista object is finished.
  //This applies to all objects/attributes affected by this and subsequent
  //destructors.
  Lista object = *list_;
  Aficionado* first_fan = object[0];
  Aficionado* last_member = object[0];
  Aficionado* first_non_member_fan = nullptr;
  Aficionado* last_fan = object[object.get_size()-1];
  for (int i = 1; i < object.get_size(); i++) {
    if (object[i]->get_member() && last_member->get_arrival_time() < object[i]->get_arrival_time()) {
      last_member = object[i];
    }
    if (!object[i]->get_member() && !first_non_member_fan) {
      first_non_member_fan = object[i];
    }
  }
  std::cout << "FIRST_FAN: " << first_fan << std::endl;
  std::cout << "LAST_MEMBER: " << last_member << std::endl;
  std::cout << "FIRST_NON_MEMBER_FAN: " << &first_non_member_fan << std::endl;
  std::cout << "LAST_FAN: " << last_fan << std::endl;
}
void Gestor::reiniciar() {
  /**
   * Reiniciar el programa a su estado inicial.
   */
  delete stack_;
  stack_ = new Pila();
  delete list_;
  list_ = new Lista();
  delete member_queue_;
  member_queue_ = new Cola();
  delete fan_queue_;
  fan_queue_ = new Cola();
}
