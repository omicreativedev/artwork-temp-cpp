#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#include "ArtWork.h"
#include "Date.h"
#include "Painting.h"
#include "Sculpture.h"
#include "WrittenWord.h"
#include "findMinMax.hpp"

int main() {
  std::vector<ArtWork*> userArtworks;

  // Example Painting
  Name name_artist("Sally", "TheArtist");
  Date created_artist(2000, 6, 15);
  Date acquired_artist(2022, 4, 1);
  Name donatedBy_artist("Elizabeth", "Bunker");
  Dimensions dimensions_artist(24.0, 36.0);
  Painting painting_example(name_artist, created_artist, acquired_artist,
                            donatedBy_artist, "Ego Musk", "AIArt",
                            dimensions_artist);

  // Example Sculpture
  Name name_sculpture("Wu", "TangClan");
  Date created_sculpture(1998, 5, 12);
  Date acquired_sculpture(2020, 10, 3);
  Name donatedBy_sculpture("Alice", "InChains");
  Dimensions dimensions_sculpture(12.0, 18.0, 6.0);
  Sculpture sculpture_example(name_sculpture, created_sculpture,
                              acquired_sculpture, donatedBy_sculpture,
                              "Really cool model of a sailboat", "Metal",
                              dimensions_sculpture, 150.0);

  // Example Written Word
  Name name_writtenWord("Michael", "Jackson");
  Date created_writtenWord(1884, 1, 1);
  Date acquired_writtenWord(2021, 8, 17);
  Name donatedBy_writtenWord("Dolly", "Pardon");
  WrittenWord writtenWord_example(name_writtenWord, created_writtenWord,
                                  acquired_writtenWord, donatedBy_writtenWord,
                                  "A song on the top of the pop charts",
                                  Genre::Song, 5);

  // Add example artworks to userArtworks vector
  userArtworks.push_back(&painting_example);
  userArtworks.push_back(&sculpture_example);
  userArtworks.push_back(&writtenWord_example);

  // Variable to track if the user wants to add another artwork
  bool addAnotherArtwork = true;

  while (addAnotherArtwork && userArtworks.size() < 10) {
    // Ask the user for the artwork type
    int artworkType;
    std::cout << "Enter the artwork type:\n"
              << "1. Painting\n"
              << "2. Sculpture\n"
              << "3. Written Word\n"
              << "4. Exit\n"
              << "Choice: ";
    std::cin >> artworkType;

    if (artworkType == 1) {
      // SELECTION — PAINTING
      std::string authorFirstName, authorLastName;
      std::string createdStr, acquiredStr;
      std::string description;
      std::string donatedByFirstName, donatedByLastName;
      std::string medium;
      double width, height;

      std::cout << "Author First name: ";
      std::cin.ignore();
      std::getline(std::cin, authorFirstName);

      std::cout << "Author Last name: ";
      // std::cin.ignore();
      std::getline(std::cin, authorLastName);

      bool validFormat = false;
      while (!validFormat) {
        std::cout << "Created date YYYY-MM-DD: ";
        std::getline(std::cin, createdStr);

        // Must be YYYY-MM-DD
        if (createdStr.size() == 10 && createdStr[4] == '-' &&
            createdStr[7] == '-') {
          bool onlyDigitsAndDash = true;

          // Must be # or -
          for (char c : createdStr) {
            if ((c < '0' || c > '9') && c != '-') {
              onlyDigitsAndDash = false;
              break;
            }
          }

          if (onlyDigitsAndDash) {
            validFormat = true;
          } else {
            std::cout
                << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
                << std::endl;
          }
        } else {
          std::cout
              << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
              << std::endl;
        }
      }
      Date created = stringToDate(createdStr);

      validFormat = false;
      while (!validFormat) {
        std::cout << "Acquired date YYYY-MM-DD: ";
        std::getline(std::cin, acquiredStr);

        // Must be YYYY-MM-DD
        if (acquiredStr.size() == 10 && acquiredStr[4] == '-' &&
            acquiredStr[7] == '-') {
          bool onlyDigitsAndDash = true;

          // Must be # or -
          for (char c : acquiredStr) {
            if ((c < '0' || c > '9') && c != '-') {
              onlyDigitsAndDash = false;
              break;
            }
          }

          if (onlyDigitsAndDash) {
            validFormat = true;
          } else {
            std::cout
                << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
                << std::endl;
          }
        } else {
          std::cout
              << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
              << std::endl;
        }
      }
      Date acquired = stringToDate(acquiredStr);

      std::cout << "Description: ";
      // std::cin.ignore();
      std::getline(std::cin, description);

      std::cout << "Medium: ";
      // std::cin.ignore();
      std::getline(std::cin, medium);

      std::cout << "Donor First Name: ";
      // std::cin.ignore();
      std::getline(std::cin, donatedByFirstName);

      std::cout << "Donor Last Name: ";
      // std::cin.ignore();
      std::getline(std::cin, donatedByLastName);

      std::cout << "Width: ";
      std::cin >> width;

      std::cout << "Height: ";
      std::cin >> height;

      Painting* painting =
          new Painting(Name(authorFirstName, authorLastName), created, acquired,
                       Name(donatedByFirstName, donatedByLastName), description,
                       medium, Dimensions(width, height));

      // Add the Painting to the userArtworks vector
      userArtworks.push_back(painting);

    } else if (artworkType == 2) {
      // SELECTION - SCULPTURE
      std::string authorFirstName, authorLastName;
      std::string createdStr, acquiredStr;
      std::string description;
      std::string donatedByFirstName, donatedByLastName;
      std::string medium;
      double width, height, depth, weight;

      std::cout << "Author First name: ";
      std::cin.ignore();
      std::getline(std::cin, authorFirstName);

      std::cout << "Author Last name: ";
      // std::cin.ignore();
      std::getline(std::cin, authorLastName);

      bool validFormat = false;
      while (!validFormat) {
        std::cout << "Created date YYYY-MM-DD: ";
        std::getline(std::cin, createdStr);

        // Must be YYYY-MM-DD
        if (createdStr.size() == 10 && createdStr[4] == '-' &&
            createdStr[7] == '-') {
          bool onlyDigitsAndDash = true;

          // Must be # or -
          for (char c : createdStr) {
            if ((c < '0' || c > '9') && c != '-') {
              onlyDigitsAndDash = false;
              break;
            }
          }

          if (onlyDigitsAndDash) {
            validFormat = true;
          } else {
            std::cout
                << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
                << std::endl;
          }
        } else {
          std::cout
              << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
              << std::endl;
        }
      }
      Date created = stringToDate(createdStr);

      validFormat = false;
      while (!validFormat) {
        std::cout << "Acquired date YYYY-MM-DD: ";
        std::getline(std::cin, acquiredStr);

        // Must be YYYY-MM-DD
        if (acquiredStr.size() == 10 && acquiredStr[4] == '-' &&
            acquiredStr[7] == '-') {
          bool onlyDigitsAndDash = true;

          // Must be # or -
          for (char c : acquiredStr) {
            if ((c < '0' || c > '9') && c != '-') {
              onlyDigitsAndDash = false;
              break;
            }
          }

          if (onlyDigitsAndDash) {
            validFormat = true;
          } else {
            std::cout
                << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
                << std::endl;
          }
        } else {
          std::cout
              << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
              << std::endl;
        }
      }
      Date acquired = stringToDate(acquiredStr);

      std::cout << "Description: ";
      // std::cin.ignore();
      std::getline(std::cin, description);

      std::cout << "Medium: ";
      // std::cin.ignore();
      std::getline(std::cin, medium);

      std::cout << "Donor First Name: ";
      // std::cin.ignore();
      std::getline(std::cin, donatedByFirstName);

      std::cout << "Donor Last Name: ";
      // std::cin.ignore();
      std::getline(std::cin, donatedByLastName);

      std::cout << "Width: ";
      std::cin >> width;

      std::cout << "Height: ";
      std::cin >> height;

      std::cout << "Depth: ";
      std::cin >> depth;

      std::cout << "Weight: ";
      std::cin >> weight;

      Sculpture* sculpture = new Sculpture(
          Name(authorFirstName, authorLastName), created, acquired,
          Name(donatedByFirstName, donatedByLastName), description, medium,
          Dimensions(width, height, depth), weight);

      // Add the Sculpture to the userArtworks vector
      userArtworks.push_back(sculpture);

    } else if (artworkType == 3) {
      // SELECTION - WRITTEN WORD
      std::string authorFirstName, authorLastName;
      std::string createdStr, acquiredStr;
      std::string description;
      std::string genre;
      std::string donatedByFirstName, donatedByLastName;
      int numPages;

      std::cout << "Author First name: ";
      std::cin.ignore();
      std::getline(std::cin, authorFirstName);

      std::cout << "Author Last name: ";
      // std::cin.ignore();
      std::getline(std::cin, authorLastName);

      bool validFormat = false;
      while (!validFormat) {
        std::cout << "Created date YYYY-MM-DD: ";
        std::getline(std::cin, createdStr);

        // Must be YYYY-MM-DD
        if (createdStr.size() == 10 && createdStr[4] == '-' &&
            createdStr[7] == '-') {
          bool onlyDigitsAndDash = true;

          // Must be # or -
          for (char c : createdStr) {
            if ((c < '0' || c > '9') && c != '-') {
              onlyDigitsAndDash = false;
              break;
            }
          }

          if (onlyDigitsAndDash) {
            validFormat = true;
          } else {
            std::cout
                << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
                << std::endl;
          }
        } else {
          std::cout
              << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
              << std::endl;
        }
      }
      Date created = stringToDate(createdStr);

      validFormat = false;
      while (!validFormat) {
        std::cout << "Acquired date YYYY-MM-DD: ";
        std::getline(std::cin, acquiredStr);

        // Must be YYYY-MM-DD
        if (acquiredStr.size() == 10 && acquiredStr[4] == '-' &&
            acquiredStr[7] == '-') {
          bool onlyDigitsAndDash = true;

          // Must be # or -
          for (char c : acquiredStr) {
            if ((c < '0' || c > '9') && c != '-') {
              onlyDigitsAndDash = false;
              break;
            }
          }

          if (onlyDigitsAndDash) {
            validFormat = true;
          } else {
            std::cout
                << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
                << std::endl;
          }
        } else {
          std::cout
              << "\t !!! Date must be YYYY-MM-DD. Only numbers and dashes."
              << std::endl;
        }
      }
      Date acquired = stringToDate(acquiredStr);

      std::cout << "Description: ";
      // std::cin.ignore();
      std::getline(std::cin, description);

      std::cout << "Enter the Genre: ";
      // std::cin.ignore();
      std::getline(std::cin, genre);

      std::cout << "Donor First Name: ";
      // std::cin.ignore();
      std::getline(std::cin, donatedByFirstName);

      std::cout << "Donor Last Name: ";
      // std::cin.ignore();
      std::getline(std::cin, donatedByLastName);

      std::cout << "Number of Pages: ";
      std::cin >> numPages;

      WrittenWord* writtenWord =
          new WrittenWord(Name(authorFirstName, authorLastName), created,
                          acquired, Name(donatedByFirstName, donatedByLastName),
                          description, GenreUtils::FromString(genre), numPages);

      // Add the WrittenWord to the userArtworks vector
      userArtworks.push_back(writtenWord);

    } else if (artworkType == 4) {
      // Exit the loop if the user chooses to exit
      addAnotherArtwork = false;
    }
  }

  // Print the user input artworks
  std::cout << "User input artworks:" << std::endl;
  for (unsigned long i = 0; i < userArtworks.size(); i++) {
    std::cout << "\nIndex " << i << std::endl;
    std::cout << userArtworks[i] << std::endl;
    std::cout << userArtworks[i]->toString();
    std::cout << "Value: $" << std::fixed << std::setprecision(2)
              << userArtworks[i]->value() << std::endl;
    std::cout << std::endl;
  }

  // Find the minimum and maximum artworks
  const ArtWork* minWrittenWord = findMinimumValue(userArtworks);
  const ArtWork* maxWrittenWord = findMaximumValue(userArtworks);

  // Display the minimum artwork
  if (minWrittenWord != nullptr) {
    std::cout << "Minimum Artwork:" << std::endl;
    std::cout << minWrittenWord->toString() << std::endl;
  } else {
    std::cout << "No artworks found." << std::endl;
  }

  // Display the maximum artwork
  if (maxWrittenWord != nullptr) {
    std::cout << "Maximum Artwork:" << std::endl;
    std::cout << maxWrittenWord->toString() << std::endl;
  } else {
    std::cout << "No artworks found." << std::endl;
  }

  for (unsigned long i = 3; i < userArtworks.size(); i++) {
    delete userArtworks[i];
  }

  // Clear and shrink the vector
  userArtworks.clear();
  userArtworks.shrink_to_fit();

  return 0;
}
