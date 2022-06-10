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


class LightContainer : public Container {
public:
  LightContainer(int, int, ContainerType);
  LightContainer(const LightContainer&);

  double getConsumption() const;
};

LightContainer::LightContainer(int _id, int _weight, ContainerType _type) : Container(id, weight, LIGHT) {
}

// Copy constructor

LightContainer::LightContainer(const LightContainer &other) : Container(other){
  id = other.id;
  weight = other.weight;
  type = other.type;
}


double LightContainer::getConsumption() const{
  return weight * 2.5;
}

#endif
