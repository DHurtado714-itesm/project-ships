// =========================================================
// File: liquid.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef LIQUID_H
#define LIQUID_H

#include "heavy.h"

class LiquidContainer : public HeavyContainer {
public:
  LiquidContainer(int, int);
  LiquidContainer(const LiquidContainer&);

  double getConsumption() const;
};


LiquidContainer::LiquidContainer(int _id, int _weight) : HeavyContainer(id, weight) {
  
  id = _id;
  weight = _weight;
  
}

LiquidContainer::LiquidContainer(const LiquidContainer &other) : HeavyContainer(other){
  
  id = other.id;
  weight = other.weight;

}

double LiquidContainer::getConsumption() const{
  return weight * 4;
}

#endif
