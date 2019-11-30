/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 20.06.2019.
 */

#include "Student.h"

/**
 * Default constructor
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Student::Student() {
    surname = "Unknown";
    name = "Person";
}

/**
 * Constructor
 * @param surname {string} Surname
 * @param name {string} name
 */
Student::Student(std::string surname, std::string name) {
    this->surname = surname;
    this->name = name;
}

/**
 * Constructor
 * @param surname {string} Surname
 * @param name {string} Name
 * @param formation {Formation} Formation
 */
Student::Student(std::string surname, std::string name, Formation formation) {
    this->surname = surname;
    this->name = name;
    this->formation = formation;
}

/**
 * Copy Constructor
 * @param student {Student} to recopy
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Student::Student(Student &student) {
    surname = student.surname;
    name = student.name;
    formation = student.formation;
}

/**
 * Copy constructor (with pointer)
 * @param student {Student*} Student to recopy
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Student::Student(Student *&student) {
    surname = student->surname;
    name = student->name;
    formation = student->formation;
}

/**
 * Destructor
 */
Student::~Student() {
    // Nothing to do here !
}

/**
 * @return {string} Surname
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
const std::string &Student::getSurname() const {
    return surname;
}

/**
 * Update surname
 * @param surname {string} new Surname
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Student::setSurname(const std::string &surname) {
    Student::surname = surname;
}

/**
 * @return {string} Name
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
const std::string &Student::getName() const {
    return name;
}

/**
 * Update Name
 * @param name {string} new Name
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Student::setName(const std::string &name) {
    Student::name = name;
}

/**
 * @return {Formation} Formation
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
Formation Student::getFormation() const {
    return formation;
}

/**
 * update Formation
 * @param formation {Formation} new Formation
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
void Student::setFormation(Formation formation) {
    Student::formation = formation;
}

bool Student::operator==(const Student &rhs) const {
    return surname == rhs.surname &&
           name == rhs.name &&
           formation == rhs.formation;
}

bool Student::operator!=(const Student &rhs) const {
    return !(rhs == *this);
}

/**
 * Write Student on console
 * @param os {ostream}
 * @param student {Student}
 * @return {ostream}
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << "Student " << student.surname << " " << student.name << ", " << student.formation;
    return os;
}
