// =========================================================
// File: refrigerated.h
// Author: Daniel Felipe Hurtado Giraldo
// Date: 07 / 10 / 2022
// Description: 
// =========================================================
#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "heavy.h"

class RefrigeratedContainer : public HeavyContainer {
public:
  RefrigeratedContainer(int, int);
  RefrigeratedContainer(const RefrigeratedContainer&);

  double getConsumption() const;
};

RefrigeratedContainer::RefrigeratedContainer(int _id, int _weight) : HeavyContainer(_id, _weight, REFRIGERATED) {}

RefrigeratedContainer::RefrigeratedContainer(const RefrigeratedContainer &other) : HeavyContainer(other){}

double RefrigeratedContainer::getConsumption() const{
  return weight * 5;
}


#endif
