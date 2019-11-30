/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 18.06.2019.
 */

#include "Cat.h"

/**
 * Construcotr
 * @param name {string} Name
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Cat::Cat(std::string name) : Pet(std::move(name)) {

}

/**
 * Cat meows !
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Cat::shout() {
    std::cout << "Meow\n";
}
