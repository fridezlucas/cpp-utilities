/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#ifndef CPP_UTILITIES_CAT_H
#define CPP_UTILITIES_CAT_H

#include "Pet.h"
#include <iostream>

/**
 * Cat class
 * Inherit from Pet
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Cat : public Pet {
private:

public:
    Cat(std::string name);

    void shout() override;
};


#endif //CPP_UTILITIES_CAT_H
