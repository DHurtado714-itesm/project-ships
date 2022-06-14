// =========================================================
// File: ship.h
// Author: Daniel Felipe Hurtado Giraldo
// Date: 07 / 10 / 2022
// Description:
// =========================================================
#ifndef SHIP_H
#define SHIP_H

#include <list>
#include <string>
#include <sstream>
#include <iomanip>
#include "container.h"
#include "light.h"
#include "heavy.h"
#include "refrigerated.h"
#include "liquid.h"
#include "simpleship.h"
#include "port.h"

using namespace std;

class Ship : public SimpleShip {
private:
  int currentWeight, totalWeight;
  int currentNumberOfAllContainers, maxNumberOfAllContainers;
  int currentNumberOfHeavyContainers, maxNumberOfHeavyContainers;
  int currentNumberOfRefrigeratedContainers, maxNumberOfRefrigeratedContainers;
  int currentNumberOfLiquidContainers, maxNumberOfLiquidContainers;
  double fuel, fuelConsumptionPerKM;
  Port *currentPort;
  std::list<Container*> containers; // Containers in ship

  bool contains(Container*);
  void remove(Container*);

public:
  Ship(int, Port*, int, int, int, int, int, double);
  Ship(const Ship&);

  int getId() const;
  int getCurrentWeight() const;
  int getTotalWeight() const;
  int getCurrentNumberOfAllContainers() const;
  int getMaxNumberOfAllContainers() const;
  int getCurrentNumberOfHeavyContainers() const;
  int getMaxNumberOfHeavyContainers() const;
  int getCurrentNumberOfRefrigeratedContainers() const;
  int getMaxNumberOfRefrigeratedContainers() const;
  int getCurrentNumberOfLiquidContainers() const;
  int getMaxNumberOfLiquidContainers() const;
  double getFuel() const;
  double getFuelConsumptionPerKM() const;
  Port* getCurrentPort() const;
  std::list<Container*> getCurrentContainers() const;

  bool sailTo(Port*);
  void reFuel(double);
  bool load(Container*);
  bool unLoad(Container*);

  std::string toString() const;
};

Ship::Ship(int _id, Port* _Port, int _totalWeight, int _maxNumberOfAllContainers, int _maxNumberOfHeavyContainers, int _maxNumberOfRefrigeratedContainers,int _maxNumberOfLiquidContainers, double _fuelConsumptionPerKM) : SimpleShip(_id){
  currentPort = _Port;
  totalWeight = _totalWeight;

  currentNumberOfAllContainers = 0;
  currentNumberOfHeavyContainers = 0; 
  currentNumberOfRefrigeratedContainers = 0;
  currentNumberOfLiquidContainers = 0;
  
  maxNumberOfAllContainers = _maxNumberOfAllContainers;
  maxNumberOfHeavyContainers = _maxNumberOfHeavyContainers;
  maxNumberOfRefrigeratedContainers = _maxNumberOfRefrigeratedContainers;
  maxNumberOfLiquidContainers = _maxNumberOfLiquidContainers;
  
  fuelConsumptionPerKM = _fuelConsumptionPerKM;
}

Ship::Ship(const Ship &other) : SimpleShip(other){
  currentPort = other.currentPort;
  totalWeight = other.totalWeight;

  currentNumberOfAllContainers = other.currentNumberOfAllContainers;
  currentNumberOfHeavyContainers = other.currentNumberOfHeavyContainers; 
  currentNumberOfRefrigeratedContainers = other.currentNumberOfRefrigeratedContainers;
  currentNumberOfLiquidContainers = other.currentNumberOfLiquidContainers;
  

  maxNumberOfAllContainers = other.maxNumberOfAllContainers;
  maxNumberOfHeavyContainers = other.maxNumberOfHeavyContainers;
  maxNumberOfRefrigeratedContainers = other.maxNumberOfRefrigeratedContainers;
  maxNumberOfLiquidContainers = other.maxNumberOfLiquidContainers;
  maxNumberOfLiquidContainers = other.maxNumberOfLiquidContainers;
  fuelConsumptionPerKM = other.fuelConsumptionPerKM;
  maxNumberOfAllContainers = other.maxNumberOfAllContainers;
  fuel = other.fuel;
}

// Getters
{
int Ship::getCurrentWeight() const{return currentWeight;}
int Ship::getTotalWeight() const{return totalWeight;}
int Ship::getCurrentNumberOfAllContainers() const{return currentNumberOfAllContainers;}
int Ship::getMaxNumberOfAllContainers() const{return maxNumberOfAllContainers;}
int Ship::getCurrentNumberOfHeavyContainers() const{return currentNumberOfHeavyContainers;}
int Ship::getMaxNumberOfHeavyContainers() const{return maxNumberOfHeavyContainers;}
int Ship::getCurrentNumberOfRefrigeratedContainers() const{return currentNumberOfRefrigeratedContainers;}
int Ship::getMaxNumberOfRefrigeratedContainers() const{return maxNumberOfRefrigeratedContainers;}
int Ship::getCurrentNumberOfLiquidContainers() const{return currentNumberOfLiquidContainers;}
int Ship::getMaxNumberOfLiquidContainers() const{return maxNumberOfLiquidContainers;}
double Ship::getFuel() const{return fuel;}
double Ship::getFuelConsumptionPerKM() const{return fuelConsumptionPerKM;}
Port* Ship::getCurrentPort() const {return currentPort;};
std::list<Container*> Ship::getCurrentContainers() const{return containers;};
}
// Methods

bool Ship::sailTo(Port* aport){
  double comsumption = 0.0;

  for(Container* i : containers){comsumption += i ->getConsumption();}

  comsumption += fuelConsumptionPerKM;
  comsumption *= currentPort->getDistance(aport);

  if(fuel>comsumption){
    fuel -= comsumption;
    currentPort -> outgoingShip(this); // Erase itself from list.
    currentPort = aport; // Change port pointer.
    currentPort -> incomingShip(this); // Add itself to the other port.

    return true;
  }

  return false;
}

void Ship::reFuel(double amount){
  while(amount > 0){
    amount += fuel;
  }
}

bool Ship::load(Container* container){
  if(!currentPort->contains(container) || currentNumberOfAllContainers >= maxNumberOfAllContainers || currentWeight + container->getWeight() >= totalWeight){
    return false;
  }

  bool flag = true;

  switch (container->getType())
  {
  case 1:
    flag = maxNumberOfHeavyContainers >= currentNumberOfHeavyContainers + 1; // Add a container.
    break;
  case 2:
    flag = maxNumberOfRefrigeratedContainers >= currentNumberOfRefrigeratedContainers + 1;
    break;
  case 3:
    flag = maxNumberOfLiquidContainers >= currentNumberOfLiquidContainers + 1;
    break;
  }
  
  if(!flag){return false;}

  currentPort->remove(container);
  containers.push_back(container);

  currentNumberOfAllContainers ++;

  switch (container->getType())
  {
  case 1:
    currentNumberOfHeavyContainers++;
    break;
  case 2:
    currentNumberOfRefrigeratedContainers ++;
    break;
  case 3:
    currentNumberOfLiquidContainers ++;
    break;
  }
  
  return true;

}

bool Ship::contains(Container *container){
  std::list<Container*>::iterator acontainer = find(containers.begin(), containers.end(), container);

  if(acontainer != containers.end()){
    return true;
  }
  
  return false;

}

void Ship::remove(Container *container){
  containers.remove(container);
}

bool Ship::unLoad(Container *container){
}

std::string Ship::toString() const{
  stringstream ship_data; // Stream of information

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

  ship_data << "Ship " << id << "\n";
  ship_data << "\t" << "Light Containers: " << ilight << "\n";
  ship_data << "\t" << "Heavy Containers: " << iheavy << "\n";
  ship_data << "\t" << "Refrigerated Containers: " << irefri << "\n";
  ship_data << "\t" << "Liquid Containers: " << iliquid << "\n";
  
  for(Ship* iterator:containers){
    ship_data << iterator->toString();
  }

  return ship_data.str();
}


#endif
