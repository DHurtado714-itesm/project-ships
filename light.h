// =========================================================
// File: light.h
// Author: Daniel Felipe Hurtado
// Date: 1 / 06 / 2022
// Description: 
// =========================================================
#ifndef LIGHT_H
#define LIGHT_H

#include "container.h"

using namespace std;

typedef enum{LIGHT, HEAVY, REFRIGERATED, LIQUID} ContainerType;

class LightContainer : public Container {
public:
  LightContainer(int, int, ContainerType) : Container(id, weight, type){};
  LightContainer(const LightContainer&);

  double getConsumption() const;
};

LightContainer::LightContainer(int _id, int _weight, ContainerType _type) : Container(id, weight, type) {
  id = _id;
  weight = _weight;
  
  ContainerType _type = LIGHT;
  type = _type;
}

// Copy constructor

LightContainer::LightContainer(const LightContainer &other) : Container(other){
  id = other.id;
  weight = other.weight;
  type = other.type;
}

// Getters

ContainerType LightContainer::getType() const{
  return type;
}

int LightContainer::getId() const{
  return id;
}

int LightContainer::getLightWeight() const{
  getweight();
  
  return weight;
}

double LightContainer::getConsumption() const{
  return weight * 2.5;
}

#endif
