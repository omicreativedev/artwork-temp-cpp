#pragma once

class Dimensions {
 private:
  double width;
  double height;
  double depth;

 public:
  Dimensions(double width, double height, double depth = 0.0);

 
  double getWidth() const;
  double getHeight() const;
  double getDepth() const;
};
