/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#ifndef CPP_UTILITIES_PET_H
#define CPP_UTILITIES_PET_H

#include <iostream>

/**
 * Pet class
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Pet {
private:
    std::string name;
public:
    Pet();

    Pet(std::string name);

    virtual void shout() = 0;
};


#endif //CPP_UTILITIES_PET_H
