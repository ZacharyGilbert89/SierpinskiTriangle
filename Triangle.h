// Copyright 2022 Zachary Gilbert
#ifndef Triangle_H //NOLINT
#define Triangle_H //NOLINT
#include <vector>
#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Triangle : public sf::Drawable {
 public:
    Triangle(); //default constructor
    std::vector<sf::ConvexShape> Tree; //Creates a vector to hold all the triangles that way we can iterate through each triangle and display it
    std::vector<sf::Vector2f> positions;//This holds the positions of all the triangles
    virtual ~Triangle();//deconstructor
    sf::ConvexShape triangle; //Creates a triangle
   void setIncrement(int i);
   int getIncrement();
 private:
   int increment = 1;
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;//NOLINT
};
sf::ConvexShape createTriangle(double x, double y, double length);
#endif //NOLINT
