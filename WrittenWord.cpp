#include "WrittenWord.h"

#include <iomanip>

int WrittenWord::numberOfWrittenWordItems = 0;

WrittenWord::WrittenWord(const Name& author, const Date& created,
                         const Date& acquired, const Name& donatedBy,
                         const std::string& description, Genre genre,
                         int numPages)
    : ArtWork(author, created, acquired, donatedBy, description),
      genre(genre),
      numPages(numPages) {
  numberOfWrittenWordItems++;
}

Genre WrittenWord::getGenre() const { return genre; }

int WrittenWord::getNumPages() const { return numPages; }

double WrittenWord::value() const {
  int age = getAcquired().getYear() - getCreated().getYear();
  return static_cast<double>(age * numPages) / 100.0;
}

int WrittenWord::getNumberOfWrittenWordItems() {
  return numberOfWrittenWordItems;
}

std::string genreToString(Genre genre) {
  switch (genre) {
    case Genre::Novel:
      return "Novel";
    case Genre::Song:
      return "Song";
    case Genre::Poetry:
      return "Poetry";
    default:
      return "Other";
  }
}

std::string WrittenWord::toString() const {
  std::stringstream ss;
  ss << "Written by: " << getArtist().getFirstName() << " "
     << getArtist().getLastName() << std::endl;
  ss << "Created: " << getCreated().toString() << std::endl;
  ss << "Acquired: " << getAcquired().toString() << std::endl;
  ss << "Description: " << getDescription() << std::endl;
  ss << "Genre: " << genreToString(genre) << std::endl;
  ss << "Number of Pages: " << std::to_string(numPages) << std::endl;
  ss << "Value: " << value() << std::endl;
  return ss.str();
}

// Overloaded stream output operator
std::ostream& operator<<(std::ostream& os, const WrittenWord& writtenWord) {
  os << writtenWord.toString();
  os << "Value: $" << std::fixed << std::setprecision(2) << writtenWord.value()
     << std::endl;
  os << std::endl;
  return os;
}

// COMPARISON OPERATORS
bool WrittenWord::operator==(const ArtWork& other) const {
  const WrittenWord* writtenWord = dynamic_cast<const WrittenWord*>(&other);
  return writtenWord != nullptr && value() == writtenWord->value();
}

bool WrittenWord::operator!=(const ArtWork& other) const {
  return !(*this == other);
}

bool WrittenWord::operator<(const ArtWork& other) const {
  const WrittenWord* writtenWord = dynamic_cast<const WrittenWord*>(&other);
  return writtenWord != nullptr && value() < writtenWord->value();
}

bool WrittenWord::operator>(const ArtWork& other) const {
  const WrittenWord* writtenWord = dynamic_cast<const WrittenWord*>(&other);
  return writtenWord != nullptr && value() > writtenWord->value();
}

bool WrittenWord::operator<=(const ArtWork& other) const {
  const WrittenWord* writtenWord = dynamic_cast<const WrittenWord*>(&other);
  return writtenWord != nullptr && value() <= writtenWord->value();
}

bool WrittenWord::operator>=(const ArtWork& other) const {
  const WrittenWord* writtenWord = dynamic_cast<const WrittenWord*>(&other);
  return writtenWord != nullptr && value() >= writtenWord->value();
}
