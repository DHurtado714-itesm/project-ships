// =========================================================
// File: simpleship.h
// Author: Daniel Felipe Hurtado Giraldo
// Date: 06 / 10 / 2022
// Description:
// =========================================================

#ifndef SIMPLE_SHIP_H
#define SIMPLE_SHIP_H

class SimpleShip {
protected:
  int id;

public:
  SimpleShip(int);
  SimpleShip(const SimpleShip&);

  int getId() const;

  bool operator==(const SimpleShip*);
  bool operator==(const SimpleShip&);

  bool operator<(const SimpleShip*);
  bool operator<(const SimpleShip&);

  virtual std::string toString() const = 0;
};


SimpleShip::SimpleShip(int _id){
  id = _id; // ship identifier

}

// Copy constructor

SimpleShip::SimpleShip(const SimpleShip &other){
  id = other.id;

}

// Getter

int SimpleShip::getId() const{
  return id;
}

// Operator overcharge

bool SimpleShip::operator==(const SimpleShip*right){
  return(id == right->getId());
}

bool SimpleShip::operator==(const SimpleShip&right){
  return(id == right.getId());
}

bool SimpleShip::operator<(const SimpleShip*right){
  return(id < right->getId());
}

bool SimpleShip::operator<(const SimpleShip&right){
  return(id < right.getId());
}

#endif
