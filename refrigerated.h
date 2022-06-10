// =========================================================
// File: refrigerated.h
// Author:
// Date:
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

RefrigeratedContainer::RefrigeratedContainer(int _id, int _weight) : HeavyContainer(id, weight) {
  
  id = _id;
  weight = _weight;
  
}

RefrigeratedContainer::RefrigeratedContainer(const RefrigeratedContainer &other) : HeavyContainer(other){
  
  id = other.id;
  weight = other.weight;

}

double RefrigeratedContainer::getConsumption() const{
  return weight * 5;
}


#endif
