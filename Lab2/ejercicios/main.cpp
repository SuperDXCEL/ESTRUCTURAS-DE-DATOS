#include <iostream>
#include "persona.cpp"
#include <vector>

int main() {
  std::vector<Persona*> myPeople;
  for (int i = 18; i < 28; i++) {
    Persona* myPerson = new Persona(i);
    myPeople.push_back(myPerson);
    myPerson->mostrar();
    delete myPerson;
  }
  for (int i = 0; i < myPeople.size(); i++) {
    myPeople[i]->mostrar();
  }
}
