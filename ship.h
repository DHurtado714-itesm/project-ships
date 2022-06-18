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
  id = _id;

  currentPort = _Port;

  currentPort = _Port;
  totalWeight = _totalWeight;

  currentWeight = 0;
  currentNumberOfAllContainers = 0;
  currentNumberOfHeavyContainers = 0; 
  currentNumberOfRefrigeratedContainers = 0;
  currentNumberOfLiquidContainers = 0;
  
  maxNumberOfAllContainers = _maxNumberOfAllContainers;
  maxNumberOfHeavyContainers = _maxNumberOfHeavyContainers;
  maxNumberOfRefrigeratedContainers = _maxNumberOfRefrigeratedContainers;
  maxNumberOfLiquidContainers = _maxNumberOfLiquidContainers;

  fuel = 0.0;
  fuelConsumptionPerKM = _fuelConsumptionPerKM;

  currentPort->incomingShip(this);
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

int Ship::getId() const{return id;}

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

// Methods

bool Ship::sailTo(Port* aport){
  double comsumption = 0.0;

  for(Container* i : containers){comsumption += i ->getConsumption();}

  comsumption += fuelConsumptionPerKM * currentPort->getDistance(aport);

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
  if(amount > 0){
    fuel += amount;
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

  currentWeight += container->getWeight();

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
  std::list<Container*>::iterator acontainer = find(containers.begin(), containers.end(), container);

  if(container == *acontainer) // Verified if ship carries container
  { 
    containers.remove(container);
    currentPort->add(container);

    currentNumberOfAllContainers -= 1;
    currentWeight -= container->getWeight();

    switch (container->getType())
    {
    case 1:
      currentNumberOfHeavyContainers--;
      break;
    case 2:
      currentNumberOfRefrigeratedContainers--;
      break;
    case 3:
      currentNumberOfLiquidContainers--;
      break;
    }
    return true;
  } 
  
  else{return false;}
  
}

std::string Ship::toString() const{
  stringstream ship_data; // Stream of information
  ship_data << "\tShip " << id << ": "<< std::fixed << std::setprecision(2) << fuel << "\n";

  string id_light = "", id_heavy = "", id_refri = "", id_liquid = ""; // Define iterators

  if(containers.size() != 0){
    std::list<Container*>::const_iterator iterator;

    for(Container* iterator:containers){ // Use the position of Container type, to difine the container
      if(iterator->getType() == LIGHT){ // Use funtion get type, to retrieved the type of container
        id_light += std::to_string(iterator->getId());
        id_light += " ";
      }
    }
    ship_data << "\t\t" << "Light Containers: " << id_light << "\n";

    for(Container* iterator:containers){
      if(iterator->getType() == HEAVY){ // Use funtion get type, to retrieved the type of container
        id_heavy += std::to_string(iterator->getId());
        id_heavy += " ";
      }
    }
    ship_data << "\t\t" << "Heavy Containers: " << id_heavy << "\n";

    for(Container* iterator:containers){
      if(iterator->getType() == REFRIGERATED){ // Use funtion get type, to retrieved the type of container
        id_refri += std::to_string(iterator->getId());
        id_refri += " ";
      }
    }
    ship_data << "\t\t" << "Refrigerated Containers: " << id_refri << "\n";

    for(Container* iterator:containers){
      if(iterator->getType() == LIQUID){ // Use funtion get type, to retrieved the type of container
        id_liquid += std::to_string(iterator->getId());
        id_liquid += " ";
      }
    }
    ship_data << "\t\t" << "Liquid Containers: " << id_liquid << "\n";
  }

  return ship_data.str();
}


#endif
