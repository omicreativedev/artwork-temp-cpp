#include "Dimensions.h"

Dimensions::Dimensions(double width, double height, double depth)
    : width(width), height(height), depth(depth) {}

double Dimensions::getWidth() const { return width; }

double Dimensions::getHeight() const { return height; }

double Dimensions::getDepth() const { return depth; }
