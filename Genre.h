#pragma once
#include <string>
enum class Genre { Novel, Song, Poetry, Other };

class GenreUtils {
 public:
  static Genre FromString(const std::string& genreString);
};

inline Genre GenreUtils::FromString(const std::string& genreString) {
  if (genreString == "Novel") {
    return Genre::Novel;
  } else if (genreString == "Song") {
    return Genre::Song;
  } else if (genreString == "Poetry") {
    return Genre::Poetry;
  } else {
    return Genre::Other;
  }
}
