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

#endif
