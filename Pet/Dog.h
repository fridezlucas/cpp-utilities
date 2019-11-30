/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#ifndef CPP_UTILITIES_DOG_H
#define CPP_UTILITIES_DOG_H

#include <iostream>
#include "Pet.h"

/**
 * Dog class
 * Inherit from Pet
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Dog : public Pet {
private:

public:
    Dog(std::string name);

    void shout() override;
};


#endif //CPP_UTILITIES_DOG_H
