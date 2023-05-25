#pragma once
#include <string>

class Date {
 private:
  int day;
  int month;
  int year;

 public:
  Date(int day, int month, int year);

  std::string toString() const;

  int getDay() const;
  int getMonth() const;
  int getYear() const;
};

Date stringToDate(const std::string& dateString);