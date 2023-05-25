#include "Name.h"

Name::Name(const std::string& firstName, const std::string& lastName)
    : firstName(firstName), lastName(lastName) {}

std::string Name::getFirstName() const { return firstName; }

std::string Name::getLastName() const { return lastName; }
