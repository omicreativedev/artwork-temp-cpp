#pragma once
#include <string>

#include "Date.h"
#include "Name.h"

class ArtWork {
 private:
  Name artist;
  Date created;
  Date acquired;
  Name donatedBy;
  std::string description;

 public:
  ArtWork(const Name& artist, const Date& created, const Date& acquired,
          const Name& donatedBy, const std::string& description);

  virtual std::string toString() const = 0;
  virtual double value() const = 0;
  virtual ~ArtWork() {}

  Name getArtist() const;
  Date getCreated() const;
  Date getAcquired() const;
  Name getDonatedBy() const;
  std::string getDescription() const;

  friend std::ostream& operator<<(std::ostream& os, const ArtWork& artwork);

  virtual bool operator==(const ArtWork& other) const = 0;
  virtual bool operator!=(const ArtWork& other) const = 0;
  virtual bool operator<(const ArtWork& other) const = 0;
  virtual bool operator>(const ArtWork& other) const = 0;
  virtual bool operator<=(const ArtWork& other) const = 0;
  virtual bool operator>=(const ArtWork& other) const = 0;
};

std::ostream& operator<<(std::ostream& os, const ArtWork& artwork);