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

using namespace std;

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
  x = _x; y = _y;
}

// Copy constructor

Port::Port(const Port &other){
  id = other.id;
  x = other.x; y = other.y;
}

// Getters

int Port::getId() const{return id;}

double Port::getX() const{return x;}

double Port::getY() const{return y;}

std::list<Container*> Port::getContainers() const{return containers;}

std::list<SimpleShip*> Port::getHistory() const{return history;}

std::list<SimpleShip*> Port::getCurrent() const{return current;}

// distance

double Port::getDistance(Port*other) const{
  return(sqrt(pow((x - other->x), 2) + pow((y - other->y), 2)));
}

//Low key

void Port::incomingShip(SimpleShip *ship){

  std::list<SimpleShip*>::iterator aship = find(current.begin(), current.end(), ship);

  if(aship != current.end()){
    return;
  }

  current.push_back(ship);
}

void Port::outgoingShip(SimpleShip *ship){
  std::list<SimpleShip*>::iterator aship = find(current.begin(), current.end(), ship);

  if(aship != current.end()){
    current.remove(ship);
    aship = find(history.begin(), history.end(), ship);
    if(aship == history.end()){
      history.push_back(ship);
    }
  }

}

bool Port::contains(Container *container){
  std::list<Container*>::iterator acontainer = find(containers.begin(), containers.end(), container);

  if(acontainer != containers.end()){
    return true;
  }
  
  return false;

}

void Port::add(Container* container){
  containers.push_back(container);
}

void Port::remove(Container* container){
  containers.remove(container);
}

std::string Port::toString() const{
  stringstream data; // Stream of information

  int ilight = 0, iheavy = 0, irefri = 0, iliquid = 0; // Define iterators

  for(Container* iterator:containers){ // Use the position of Container type, to difine the container
    if(iterator->getType() == 0){ // Use funtion get type, to retrieved the type of container
      ilight++;
    } else if (iterator->getType() == 1){
      iheavy++;
    } else if (iterator->getType() == 2){
      irefri++;
    } else{
      iliquid++;
    }
  }

  data << "Port " << id << ": (" << x << ", " << y << ")"<< "\n";
  data << "\t" << "Light Containers: " << ilight << "\n";
  data << "\t" << "Heavy Containers: " << iheavy << "\n";
  data << "\t" << "Refrigerated Containers: " << irefri << "\n";
  data << "\t" << "Liquid Containers: " << iliquid << "\n";
  
  for(SimpleShip* iterator:current){
    data << iterator->toString();
  }

  return data.str();
}

#endif
