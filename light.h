// =========================================================
// File: light.h
// Author: Daniel Felipe Hurtado
// Date: 1 / 06 / 2022
// Description: 
// =========================================================
#ifndef LIGHT_H
#define LIGHT_H

#include "container.h"

class LightContainer : public Container {
public:
  LightContainer(int, int);
  LightContainer(const LightContainer&);

  double getConsumption() const;
};

LightContainer::LightContainer(int _id, int _weight){
  id = _id;
  weight = _weight;
  
  ContainerType _type = LIGHT;
  type = _type;
} // Corregir

LightContainer::Container(){

}

// Getters

ContainerType LightContainer::getType() const{
  return type;
}

int LightContainer::getId() const{
  return id;
}

int LightContainer::getWeight() const{
  return weight;
}

double getConsumption() const{
  // Consumo = container weight *  2.5
}

#endif
