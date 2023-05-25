#include "Date.h"

#include <sstream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}
int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

std::string Date::toString() const {
  std::stringstream ss;
  ss << year << "-" << month << "-" << day;
  return ss.str();
}

Date stringToDate(const std::string& dateString) {
  int year, month, day;
  std::stringstream ss(dateString);
  ss >> year;
  ss.ignore(1);
  ss >> month;
  ss.ignore(1);
  ss >> day;
  return Date(year, month, day);
}