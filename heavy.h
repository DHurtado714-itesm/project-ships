// =========================================================
// File: heavy.h
// Author: Daniel Felipe Hurtado
// Date: 1 / 07 / 2022
// Description: 
// =========================================================
#ifndef HEAVY_H
#define HEAVY_H

#include "container.h"

class HeavyContainer : public Container {
public:
  HeavyContainer(int, int);
  HeavyContainer(int, int, ContainerType);
  HeavyContainer(const HeavyContainer&);

  double getConsumption() const;
};


HeavyContainer::HeavyContainer(int _id, int _weight, ContainerType _type) : Container(id, weight, type) {
  id = _id;
  weight = _weight;
  
  ContainerType _type = HEAVY;
  type = _type;
}

// Copy constructor

HeavyContainer::HeavyContainer(const HeavyContainer &other) : Container(other){
  id = other.id;
  weight = other.weight;
  type = other.type;
}

// Getters
//{}


double LightContainer::getConsumption() const{
  return weight * 3;
}


#endif
