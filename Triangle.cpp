// Copyright 2022 Zachary Gilbert
#include "Triangle.h"
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
Triangle::~Triangle() {
}
void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states)const {
}
Triangle::Triangle() {
}
sf::ConvexShape createTriangle(double x, double y, double length) { //Helper function that can draw triangles when given an X and Y position, and a Length variable
    sf::ConvexShape temp;
    temp.setPosition(x, y);
    double tl = length/2.0;
    double height = sqrt((tl * tl) - (tl/2.0 * tl/2.0)); // Calculates the height using the hypotenuse
    double gx = tl;
    double gy = height;
    temp.setPointCount(3);
    temp.setOutlineThickness(2);
    temp.setOutlineColor(sf::Color::Black);
    temp.setPoint(0, sf::Vector2f(-gx, -gy));
    temp.setPoint(1, sf::Vector2f(gx, -gy));
    temp.setPoint(2, sf::Vector2f(0, gy));
    return temp;
}
void Triangle::setIncrement(int i) { //Setter function
    increment = i;
}
int Triangle::getIncrement() { //Getter function
    return increment;
}
