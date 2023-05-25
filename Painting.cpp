

#include "Painting.h"

#include <iomanip>
#include <sstream>

int Painting::numberOfPaintings = 0;

Painting::Painting(const Name& artist, const Date& created,
                   const Date& acquired, const Name& donatedBy,
                   const std::string& description, const std::string& medium,
                   const Dimensions& dimensions)
    : ArtWork(artist, created, acquired, donatedBy, description),
      medium(medium),
      dimensions(dimensions) {
  numberOfPaintings++;
}

std::string Painting::toString() const {
  // Format the painting information as a string
  std::stringstream ss;
  ss << "Painting by: " << getArtist().getFirstName() << " "
     << getArtist().getLastName() << std::endl;
  ss << "Medium: " << medium << std::endl;
  ss << "Dimensions: " << dimensions.getWidth() << " x "
     << dimensions.getHeight() << " inches" << std::endl;
  ss << "Created: " << getCreated().toString() << std::endl;
  ss << "Acquired: " << getAcquired().toString() << std::endl;
  ss << "Description: " << getDescription() << std::endl;
  ss << "Value: " << value() << std::endl;
  return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Painting& painting) {
  os << painting.toString();
  os << "Value: $" << std::fixed << std::setprecision(2) << painting.value()
     << std::endl;
  os << std::endl;
  return os;
}

double Painting::value() const {
  int age = std::abs(getAcquired().getYear() - getCreated().getYear());
  double area = dimensions.getWidth() * dimensions.getHeight();
  return age * area;
}

std::string Painting::getMedium() const { return medium; }

Dimensions Painting::getDimensions() const { return dimensions; }

int Painting::getNumberOfPaintings() { return numberOfPaintings; }

// COMPARISON OPERATORS

bool Painting::operator==(const ArtWork& other) const {
  const Painting* painting = dynamic_cast<const Painting*>(&other);
  return painting != nullptr && value() == painting->value();
}

bool Painting::operator!=(const ArtWork& other) const {
  return !(*this == other);
}

bool Painting::operator<(const ArtWork& other) const {
  const Painting* painting = dynamic_cast<const Painting*>(&other);
  return painting != nullptr && value() < painting->value();
}

bool Painting::operator>(const ArtWork& other) const {
  const Painting* painting = dynamic_cast<const Painting*>(&other);
  return painting != nullptr && value() > painting->value();
}

bool Painting::operator<=(const ArtWork& other) const {
  const Painting* painting = dynamic_cast<const Painting*>(&other);
  return painting != nullptr && value() <= painting->value();
}

bool Painting::operator>=(const ArtWork& other) const {
  const Painting* painting = dynamic_cast<const Painting*>(&other);
  return painting != nullptr && value() >= painting->value();
}
