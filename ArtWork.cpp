#include "ArtWork.h"
#include <iomanip>
#include <sstream>
#include <string>

#include "Date.h"
#include "Name.h"

ArtWork::ArtWork(const Name& artist, const Date& created, const Date& acquired,
                 const Name& donatedBy, const std::string& description)
    : artist(artist),
      created(created),
      acquired(acquired),
      donatedBy(donatedBy),
      description(description) {}

Name ArtWork::getArtist() const { return artist; }

Name ArtWork::getDonatedBy() const { return donatedBy; }

Date ArtWork::getCreated() const { return created; }

Date ArtWork::getAcquired() const { return acquired; }

std::string ArtWork::getDescription() const { return description; }

std::string ArtWork::toString() const {
  std::stringstream ss;
  ss << "Artist: " << artist.getFirstName() << " " << artist.getLastName()
     << std::endl;
  ss << "Created: " << created.toString() << std::endl;
  ss << "Acquired: " << acquired.toString() << std::endl;
  ss << "Donated by: " << donatedBy.getFirstName() << " "
     << donatedBy.getLastName() << std::endl;
  ss << "Description: " << description << std::endl;
  return ss.str();
}

std::ostream& operator<<(std::ostream& os, const ArtWork& artwork) {
  os << artwork.toString();
  os << "Value: $" << std::fixed << std::setprecision(2) << artwork.value()
     << std::endl << std::endl;
  return os;
}

bool ArtWork::operator==(const ArtWork& other) const {
  return value() == other.value();
}
bool ArtWork::operator!=(const ArtWork& other) const {
  return value() != other.value();
}
bool ArtWork::operator<(const ArtWork& other) const {
  return value() < other.value();
}
bool ArtWork::operator>(const ArtWork& other) const {
  return value() > other.value();
}
bool ArtWork::operator<=(const ArtWork& other) const {
  return value() <= other.value();
}
bool ArtWork::operator>=(const ArtWork& other) const {
  return value() >= other.value();
}
