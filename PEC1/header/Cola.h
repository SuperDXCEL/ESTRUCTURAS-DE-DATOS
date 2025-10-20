#ifndef COLA_H_
#define COLA_H_

#include "NodoCola.h"

class Cola {
 public:
  Cola();
  // Automatic copy operator
  Cola(const Cola& cola);
  ~Cola();
  int get_size();
  void insert(Aficionado* nodo);
  Aficionado* pop();
  Aficionado* front();
  Aficionado* back();
  NodoCola* merge_sort(NodoCola* nodo);
  NodoCola* sortList(NodoCola* nodo);
  void sort_list();
  void show();
 private:
  NodoCola* first_element_;
  NodoCola* last_element_;
  int size_;
};

#endif //PILA_H_
