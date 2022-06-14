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
  if (_weight < 0){
    _weight = 0;
  }
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

// Operator overcharge

bool Container::operator==(const Container *right){
  
  return(id == right->getId() && weight == right->getWeight() && type == right->getType());

}

bool Container::operator==(const Container &right){
  return(id == right.getId() && weight == right.getWeight() && type == right.getType());
}

bool Container::operator<(const Container *right){
  
  if(type == right->getType() && id < right->getId()){
    return true;

  }else if (type != right->getType() && type < right->getType()){
    return true;
  } else{
    return false;
  }
  
}

bool Container::operator<(const Container &right){
  
  if(type == right.getType() && id < right.getId()){
    return true;

  }else if (type != right.getType() && type < right.getType()){
    return true;
  } else {
    return false;
  }
  
}

#endif
