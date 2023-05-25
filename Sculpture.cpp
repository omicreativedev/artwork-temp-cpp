#include "Sculpture.h"

#include <iomanip>
#include <sstream>

int Sculpture::numberOfSculptures = 0;

Sculpture::Sculpture(const Name& artist, const Date& created,
                     const Date& acquired, const Name& donatedBy,
                     const std::string& description, const std::string& medium,
                     const Dimensions& dimensions, double weight)
    : ArtWork(artist, created, acquired, donatedBy, description),
      medium(medium),
      dimensions(dimensions),
      weight(weight) {
  numberOfSculptures++;
}

std::string Sculpture::toString() const {
  std::stringstream ss;
  ss << "Sculpture by: " << getArtist().getFirstName() << " "
     << getArtist().getLastName() << std::endl;
  ss << "Medium: " << medium << std::endl;
  ss << "Dimensions: " << dimensions.getWidth() << " x "
     << dimensions.getHeight() << " x " << dimensions.getDepth() << " inches"
     << std::endl;
  ss << "Weight: " << weight << " lbs" << std::endl;
  ss << "Created: " << getCreated().toString() << std::endl;
  ss << "Acquired: " << getAcquired().toString() << std::endl;
  ss << "Description: " << getDescription() << std::endl;
  ss << "Value: " << value() << std::endl;

  return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Sculpture& sculpture) {
  os << sculpture.toString();
  os << "Value: $" << std::fixed << std::setprecision(2) << sculpture.value()
     << std::endl;
  os << std::endl;
  return os;
}

double Sculpture::value() const {
  int age = std::abs(getAcquired().getYear() - getCreated().getYear());
  double weightIn100lbs = weight * 2.20462 / 100.0;
  return age * weightIn100lbs;
}

std::string Sculpture::getMedium() const { return medium; }

Dimensions Sculpture::getDimensions() const { return dimensions; }

double Sculpture::getWeight() const { return weight; }

int Sculpture::getNumberOfSculptures() { return numberOfSculptures; }

// COMPARISON OPERATORS

bool Sculpture::operator==(const ArtWork& other) const {
  const Sculpture* sculpture = dynamic_cast<const Sculpture*>(&other);
  return sculpture != nullptr && value() == sculpture->value() &&
         weight == sculpture->weight;
}

bool Sculpture::operator!=(const ArtWork& other) const {
  return !(*this == other);
}

bool Sculpture::operator<(const ArtWork& other) const {
  const Sculpture* sculpture = dynamic_cast<const Sculpture*>(&other);
  return sculpture != nullptr && value() < sculpture->value();
}

bool Sculpture::operator>(const ArtWork& other) const {
  const Sculpture* sculpture = dynamic_cast<const Sculpture*>(&other);
  return sculpture != nullptr && value() > sculpture->value();
}

bool Sculpture::operator<=(const ArtWork& other) const {
  const Sculpture* sculpture = dynamic_cast<const Sculpture*>(&other);
  return sculpture != nullptr && value() <= sculpture->value();
}

bool Sculpture::operator>=(const ArtWork& other) const {
  const Sculpture* sculpture = dynamic_cast<const Sculpture*>(&other);
  return sculpture != nullptr && value() >= sculpture->value();
}
