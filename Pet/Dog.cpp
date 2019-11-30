/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#include "Dog.h"

/**
 * Doc constructor
 * @param name {string} Name
 */
Dog::Dog(std::string name) : Pet(name) {

}

/**
 * Dog shout !
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Dog::shout() {
    std::cout << "Wouaf\n";
}
