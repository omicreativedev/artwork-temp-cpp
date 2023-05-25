//#pragma once
#include "ArtWork.h"
#include "Dimensions.h"

class Sculpture : public ArtWork {
 private:
  // Unique Qualities
  std::string medium;
  Dimensions dimensions;
  double weight;
  // Counter
  static int numberOfSculptures;

 public:
  Sculpture(const Name& artist, const Date& created, const Date& acquired,
            const Name& donatedBy, const std::string& description,
            const std::string& medium, const Dimensions& dimensions,
            double weight);

  std::string toString() const override;

  double value() const override;

  // Getter methods
  std::string getMedium() const;
  Dimensions getDimensions() const;
  double getWeight() const;
  static int getNumberOfSculptures();
  friend std::ostream& operator<<(std::ostream& os, const Sculpture& sculpture);

  /*---------------*/
  bool operator==(const ArtWork& other) const override;
  bool operator!=(const ArtWork& other) const override;
  bool operator<(const ArtWork& other) const override;
  bool operator>(const ArtWork& other) const override;
  bool operator<=(const ArtWork& other) const override;
  bool operator>=(const ArtWork& other) const override;
};
std::ostream& operator<<(std::ostream& os, const Sculpture& sculpture);
