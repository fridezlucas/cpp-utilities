/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#include "Pet.h"

/**
 * Default constructor
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Pet::Pet() {
    // Nothing to do here !
}

/**
 * Constructor
 * @param name {string} Name
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Pet::Pet(std::string name) {
    this->name = name;
}
