#include <iostream>

typedef struct
{
    std::string name;
    int age;
} Person;

bool operator<(Person const &personA, Person const &personB)
{
    return personA.age < personB.age;
}

bool operator<=(Person const &personA, Person const &personB)
{
    return personA.age <= personB.age;
}

bool operator>(Person const &personA, Person const &personB)
{
    return !operator<=(personA, personB);
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "(" << person.name << " : " << person.age << ")";
    return os;
}