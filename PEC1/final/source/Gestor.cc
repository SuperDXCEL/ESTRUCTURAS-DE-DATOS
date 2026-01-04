#include "../header/Gestor.h"
#include <iostream>
#include <cstdlib>

int random_time() {
  int arrival_time = rand() % 61;
  return arrival_time;
}
int random_id(int max, std::unordered_set<int>& id_set_) {
  int id = rand() % (max + 1) + 1;
  while (id_set_.find(id) != id_set_.end()) {
    id = rand() % (max + 1) + 1;
  }
  id_set_.insert(id);
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
int Gestor::AficionadosEnArbol() {
  if (!tree_ || !tree_->get_raiz()) {
    return 0;
  }
  int count = 0;
  count += contarNodos(tree_->get_raiz()->get_izq());
  count += contarNodos(tree_->get_raiz()->get_der());
  return count;
}
int Gestor::contarNodos(NodoArbol* nodo) {
  if (!nodo) return 0;
  return 1 + contarNodos(nodo->get_izq()) + contarNodos(nodo->get_der());
}
void Gestor::genera10Aficionados() {
  total_fans_ += 10;
  for (int i = 1; i <= 10; i++) {
    Aficionado* fan = new Aficionado(random_id(total_fans_, id_set_), random_time());
    stack_->push(fan);
  }
}
void Gestor::muestraAficionados() {
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
  while (stack_->get_size() > 0) {
    Aficionado* fan = stack_->pop();
  }
}
void Gestor::encolarAficionados() {
  while (stack_->get_size() > 0) {
    Aficionado* fan = stack_->pop();
    fan->get_member() ? member_queue_->insert(fan) : fan_queue_->insert(fan); 
  }
}
void Gestor::muestraSociosCola() {
  Cola queue_copy = *member_queue_;
  while (queue_copy.get_size() > 0) {
    Aficionado* fan = queue_copy.pop();
    std::cout << fan << std::endl;  
  }
}
void Gestor::muestraSimpatizantesCola() {
  Cola queue_copy = *fan_queue_;
  while (queue_copy.get_size() > 0) {
    Aficionado* fan = queue_copy.pop();
    std::cout << fan << std::endl;  
  }
}
void Gestor::borraAficionadosColas() {
  if (member_queue_) {
    delete member_queue_;
    member_queue_ = new Cola();
  }
  if (fan_queue_) {
    delete fan_queue_;
    fan_queue_ = new Cola();
  }
}
void Gestor::enlistarAficionados() {
  member_queue_->sort_list();
  while (member_queue_->get_size() > 0) {
    Aficionado* fan = member_queue_->pop();
    std::cout << "MEMBER: " << fan << std::endl;
    list_->append(fan);
  }
  fan_queue_->sort_list();
  while (fan_queue_->get_size() > 0) {
    Aficionado* fan = fan_queue_->pop();
    std::cout << "FAN: " << fan << std::endl;
    list_->append(fan);
  }
}
void Gestor::buscarAficionados() {
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
  std::cout << "FIRST_NON_MEMBER_FAN: " << first_non_member_fan << std::endl;
  std::cout << "LAST_FAN: " << last_fan << std::endl;
}
void Gestor::reiniciar() {
  delete stack_;
  stack_ = new Pila();
  delete list_;
  list_ = new Lista();
  delete member_queue_;
  member_queue_ = new Cola();
  delete fan_queue_;
  fan_queue_ = new Cola();
}
void Gestor::dibujarArbol() {
  if (tree_) {
    tree_ = new Arbol();
  }
  for (int i = 0; i < list_->get_size(); i++) {
    Aficionado* new_aficionado = new Aficionado(
      (*list_)[i]->get_id(), 
      (*list_)[i]->get_arrival_time()
    );
    tree_->insertar(new_aficionado);
  }
  tree_->dibujar();
}
void Gestor::mostrarSociosArbol() {
  if (!tree_->get_raiz() || !tree_->get_raiz()->get_izq()) {
    std::cout << "No hay socios en el árbol." << std::endl;
    return;
  }
  mostrarInorden(tree_->get_raiz()->get_izq());
}
void Gestor::mostrarInorden(NodoArbol* nodo) {
  if (!nodo) return;
  mostrarInorden(nodo->get_izq());
  std::cout << nodo->get_dato() << std::endl;
  mostrarInorden(nodo->get_der());
}
void Gestor::mostrarSimpatizantesArbol() {
  if (!tree_->get_raiz() || !tree_->get_raiz()->get_der()) {
    std::cout << "No hay simpatizantes en el árbol." << std::endl;
    return;
  }
  mostrarInorden(tree_->get_raiz()->get_der());
}
void Gestor::mostrarTodosArbolInorden() {
  if (!tree_->get_raiz()) {
    std::cout << "El árbol está vacío." << std::endl;
    return;
  }
  mostrarInorden(tree_->get_raiz()->get_izq());
  mostrarInorden(tree_->get_raiz()->get_der());
}
void Gestor::buscarAficionadosArbol() {
  Lista* todos = new Lista();
  recogerAficionados(tree_->get_raiz()->get_izq(), todos);
  recogerAficionados(tree_->get_raiz()->get_der(), todos);
  if (todos->get_size() == 0) {
    std::cout << "No hay aficionados en el árbol." << std::endl;
    delete todos;
    return;
  }
  Aficionado* primer_aficionado = (*todos)[0];
  Aficionado* ultimo_socio = nullptr;
  Aficionado* primer_simpatizante = nullptr;
  Aficionado* ultimo_aficionado = (*todos)[todos->get_size() - 1];
  for (int i = 0; i < todos->get_size(); i++) {
    Aficionado* fan = (*todos)[i];
    if (fan->get_arrival_time() < primer_aficionado->get_arrival_time()) {
      primer_aficionado = fan;
    }
    if (fan->get_arrival_time() > ultimo_aficionado->get_arrival_time()) {
      ultimo_aficionado = fan;
    }
    if (fan->get_member()) {
      if (!ultimo_socio || fan->get_arrival_time() > ultimo_socio->get_arrival_time()) {
        ultimo_socio = fan;
      }
    }
    if (!fan->get_member()) {
      if (!primer_simpatizante || fan->get_arrival_time() < primer_simpatizante->get_arrival_time()) {
        primer_simpatizante = fan;
      }
    }
  }
  std::cout << "Primer aficionado en acceder: " << primer_aficionado << std::endl;
  std::cout << "Último socio en acceder: " << ultimo_socio << std::endl;
  std::cout << "Primer simpatizante en acceder: " << primer_simpatizante << std::endl;
  std::cout << "Último aficionado en acceder: " << ultimo_aficionado << std::endl;
  delete todos;
}
void Gestor::recogerAficionados(NodoArbol* nodo, Lista* lista) {
  if (!nodo) return;
  lista->append(nodo->get_dato());
  recogerAficionados(nodo->get_izq(), lista);
  recogerAficionados(nodo->get_der(), lista);
}
void Gestor::contarAficionadosConIdentificadorPar() {
  int count = contarPares(tree_->get_raiz());
  std::cout << "Número de aficionados con ID par: " << count << std::endl;
}
int Gestor::contarPares(NodoArbol* nodo) {
  if (!nodo) return 0;
  int count = 0;
  if (nodo->get_dato()->get_id() != 0 && nodo->get_dato()->get_id() % 2 == 0) {
    count = 1;
  }
  return count + contarPares(nodo->get_izq()) + contarPares(nodo->get_der());
}
void Gestor::mostrarAficionadosEnNodoHoja() {
  std::cout << "Aficionados en nodos hoja:" << std::endl;
  mostrarHojas(tree_->get_raiz());
}
void Gestor::mostrarHojas(NodoArbol* nodo) {
  if (!nodo) return;
  if (!nodo->get_izq() && !nodo->get_der()) {
    if (nodo->get_dato()->get_id() != 0) {
      std::cout << nodo->get_dato() << std::endl;
    }
    return;
  }
  mostrarHojas(nodo->get_izq());
  mostrarHojas(nodo->get_der());
}
void Gestor::eliminarAficionado() {
  int id;
  std::cout << "Ingrese el ID del aficionado a eliminar: ";
  std::cin >> id;
  std::cout << "\n--- Árbol antes de eliminar ---" << std::endl;
  tree_->dibujar();
  Aficionado* fan = buscarPorId(tree_->get_raiz(), id);
  if (!fan) {
    std::cout << "Aficionado con ID " << id << " no encontrado." << std::endl;
    return;
  }
  if (fan->get_member()) {
    tree_->get_raiz()->set_izq(eliminarNodo(tree_->get_raiz()->get_izq(), id));
  } else {
    tree_->get_raiz()->set_der(eliminarNodo(tree_->get_raiz()->get_der(), id));
  }
  std::cout << "\n--- Árbol después de eliminar ---" << std::endl;
  tree_->dibujar();
}
Aficionado* Gestor::buscarPorId(NodoArbol* nodo, int id) {
  if (!nodo) return nullptr;
  if (nodo->get_dato()->get_id() == id) {
    return nodo->get_dato();
  }
  Aficionado* izq = buscarPorId(nodo->get_izq(), id);
  if (izq) return izq;
  return buscarPorId(nodo->get_der(), id);
}
NodoArbol* Gestor::eliminarNodo(NodoArbol* nodo, int id) {
  if (!nodo) return nullptr;
  if (id < nodo->get_dato()->get_id()) {
    nodo->set_izq(eliminarNodo(nodo->get_izq(), id));
  } else if (id > nodo->get_dato()->get_id()) {
    nodo->set_der(eliminarNodo(nodo->get_der(), id));
  } else {
    if (!nodo->get_izq() && !nodo->get_der()) {
      delete nodo->get_dato();
      delete nodo;
      return nullptr;
    }
    if (!nodo->get_izq()) {
      NodoArbol* temp = nodo->get_der();
      delete nodo->get_dato();
      delete nodo;
      return temp;
    }
    if (!nodo->get_der()) {
      NodoArbol* temp = nodo->get_izq();
      delete nodo->get_dato();
      delete nodo;
      return temp;
    }
    NodoArbol* sucesor = nodo->get_der();
    while (sucesor->get_izq()) {
      sucesor = sucesor->get_izq();
    }
    nodo->get_dato()->set_id(sucesor->get_dato()->get_id());
    nodo->get_dato()->set_arrival_time(sucesor->get_dato()->get_arrival_time());
    nodo->set_der(eliminarNodo(nodo->get_der(), sucesor->get_dato()->get_id()));
  }
  return nodo;
}