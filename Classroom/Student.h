/*
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 * @date 20.06.2019.
 */

#ifndef CPP_UTILITIES_STUDENT_H
#define CPP_UTILITIES_STUDENT_H

#include <iostream>
#include "Formation.cpp"

/**
 * Student class
 * @author Lucas Fridez <lucas.fridez@he-arc.ch>
 * @version 1.0
 */
class Student {
private:
    std::string surname;
    std::string name;
    Formation formation;

public:
    Student();

    Student(std::string surname, std::string name);

    Student(std::string surname, std::string name, Formation formation);

    Student(Student &student);

    Student(Student *&student);

    virtual ~Student();

    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    const std::string &getName() const;

    void setName(const std::string &name);

    Formation getFormation() const;

    void setFormation(Formation formation);

    friend std::ostream &operator<<(std::ostream &os, const Student &student);
};


#endif //CPP_UTILITIES_STUDENT_H
