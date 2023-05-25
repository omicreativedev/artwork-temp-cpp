#pragma once

#include "ArtWork.h"
#include "Genre.h"

class WrittenWord : public ArtWork {
 private:
  // Unique Qualities
  Genre genre;
  int numPages;
  // Counter
  static int numberOfWrittenWordItems;

 public:
  WrittenWord(const Name& author, const Date& created, const Date& acquired,
              const Name& donatedBy, const std::string& description,
              Genre genre, int numPages);

  Genre getGenre() const;

  int getNumPages() const;

  static int getNumberOfWrittenWordItems();

  double value() const override;

  std::string toString() const override;

  friend std::ostream& operator<<(std::ostream& os,
                                  const WrittenWord& writtenWord);

  /*----------------*/
  bool operator==(const ArtWork& other) const override;
  bool operator!=(const ArtWork& other) const override;
  bool operator<(const ArtWork& other) const override;
  bool operator>(const ArtWork& other) const override;
  bool operator<=(const ArtWork& other) const override;
  bool operator>=(const ArtWork& other) const override;
};

std::ostream& operator<<(std::ostream& os, const WrittenWord& writtenWord);