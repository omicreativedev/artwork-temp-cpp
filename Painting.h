#pragma once
#include "ArtWork.h"
#include "Date.h"
#include "Dimensions.h"
#include "Name.h"

class Painting : public ArtWork {
 private:
  // Unique Qualities
  std::string medium;
  Dimensions dimensions;
  // Counter
  static int numberOfPaintings;

 public:
  Painting(const Name& artist, const Date& created, const Date& acquired,
           const Name& donatedBy, const std::string& description,
           const std::string& medium, const Dimensions& dimensions);

  std::string toString() const override;
  double value() const override;

  std::string getMedium() const;
  Dimensions getDimensions() const;
  static int getNumberOfPaintings();
  friend std::ostream& operator<<(std::ostream& os, const Painting& painting);

  /*-----------------*/
  bool operator==(const ArtWork& other) const override;
  bool operator!=(const ArtWork& other) const override;
  bool operator<(const ArtWork& other) const override;
  bool operator>(const ArtWork& other) const override;
  bool operator<=(const ArtWork& other) const override;
  bool operator>=(const ArtWork& other) const override;
};
std::ostream& operator<<(std::ostream& os, const Painting& painting);