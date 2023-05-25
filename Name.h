#pragma once
#include <string>

class Name {
 private:
  std::string firstName;
  std::string lastName;

 public:
  Name() = default;  
  Name(const std::string& firstName, const std::string& lastName);

  std::string getFirstName() const;
  std::string getLastName() const;
};
