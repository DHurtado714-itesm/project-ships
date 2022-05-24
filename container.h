// =========================================================
// File: container.h
// Author: Daniel Felipe Hurtado
// Date: 24 / 05 / 2022
// Description: 
// =========================================================
#ifndef CONTAINER_H
#define CONTAINER_H

typedef enum{LIGHT, HEAVY, REFRIGERATED, LIQUID} ContainerType;

class Container {
protected:
  int id, weight;
  ContainerType type;

public:
  Container(int, int, ContainerType);
  Container(const Container&);

  ContainerType getType() const;
  int getId() const;
  int getWeight() const;

  bool operator==(const Container*);
  bool operator==(const Container&);
  bool operator<(const Container*);
  bool operator<(const Container&);

  virtual double getConsumption() const = 0;
};

// Constructor with 3 parameters

Container::Container(int _id, int _weight, ContainerType _type){
  id = _id;
  weight = _weight;
  type = _type;
}

// Copy constructor

Container::Container(const Container &other){
  id = other.id;
  weight = other.weight;
  type = other.type;
}

// Getters

ContainerType Container::getType() const{
  return type;
}

int Container::getId() const{
  return id;
}

int Container::getWeight() const{
  return weight;
}

#endif
