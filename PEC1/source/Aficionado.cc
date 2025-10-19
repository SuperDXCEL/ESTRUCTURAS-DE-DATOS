#include "../header/Aficionado.h"
#include <ostream>

Aficionado::Aficionado(int id, int arrival_time) : id_(id), arrival_time_(arrival_time), member_(id%2==0) {}

Aficionado::~Aficionado() {}

int Aficionado::get_id() {
  return id_;
}

int Aficionado::get_arrival_time() {
  return arrival_time_;
}

bool Aficionado::get_member() {
  return member_;
}

std::ostream& operator<<(std::ostream& os, Aficionado* fan) {
  os << "ID: " << fan->get_id() << " ARRIVAL TIME: " << fan->get_arrival_time() << " MEMBER: " << fan->get_member(); 
  return os;
}
