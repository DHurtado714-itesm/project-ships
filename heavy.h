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

HeavyContainer::HeavyContainer(int _id, int _weight) : Container(_id, _weight, HEAVY){}

HeavyContainer::HeavyContainer(int _id, int _weight, ContainerType _type) : Container(_id, _weight, _type) {}

// Copy constructor

HeavyContainer::HeavyContainer(const HeavyContainer &other) : Container(other){}

double HeavyContainer::getConsumption() const{
  return weight * 3;
}

#endif
