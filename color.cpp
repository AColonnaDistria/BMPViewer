#include "color.hpp"

Color::Color(char a, char r, char g, char b) {
    this->a = a;
    this->r = r;
    this->g = g;
    this->b = b;
}
Color::Color(char r, char g, char b) {
    this->a = 255;
    this->r = r;
    this->g = g;
    this->b = b;
}