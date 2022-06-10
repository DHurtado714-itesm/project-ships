// =========================================================
// File: port.h
// Author: Daniel Felipe Hurtado Giraldo
// Date: 06 / 10 / 2022
// Description:
// =========================================================
#ifndef PORT_H
#define PORT_H

#include <list>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "container.h"
#include "simpleship.h"

class Port {
private:
  int id;
  double x, y;
  std::list<Container*> containers; // list of containers
  std::list<SimpleShip*> history; // ships that have been in port
  std::list<SimpleShip*> current; // ships in port

public:
  Port(int, double, double);
  Port(const Port&);

  int getId() const;
  double getX() const;
  double getY() const;
  std::list<Container*> getContainers() const;
  std::list<SimpleShip*> getHistory() const;
  std::list<SimpleShip*> getCurrent() const;

  double getDistance(Port*) const;
  void incomingShip(SimpleShip*);
  void outgoingShip(SimpleShip*);

  bool contains(Container*);
  void add(Container*);
  void remove(Container*);

  std::string toString() const;
};

// Constructor

Port::Port(int _id, double _x, double _y){
  id = _id;
  x = _x;
  y = _y;
}

// Copy constructor

Port::Port(const Port &other){
  id = other.id;
  x = other.x;
  y = other.y;
}

// Getters

int Port::getId() const{
  return id;
}

double Port::getX() const{
  return x;
}

double Port::getY() const{
  return y;
}

std::list<Container*> Port::getContainers() const{
  return containers;
}

std::list<SimpleShip*> Port::getHistory() const{
  return history;
}

std::list<SimpleShip*> Port::getCurrent() const{
  return current;
}

// distance

double Port::getDistance(Port*other) const{
  return(sqrt(pow((x - other->x), 2) + pow((y - other->y), 2)));
} // Preguntarle al profe, por que no funciona el acesso de este puntero

//Low key
void Port::incomingShip(SimpleShip *ship){

}

void Port::outgoingShip(SimpleShip *ship){
  
}

bool Port::contains(Container *container){
  return 0;
}

std::string Port::toString() const{
  // return("Port " id " : " (x, y))
}


#endif
