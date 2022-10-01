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
    Triangle();
    std::vector<sf::ConvexShape> Tree;
    std::vector<sf::Vector2f> positions;
    virtual ~Triangle();
    sf::ConvexShape triangle;
   void setIncrement(int i);
   int getIncrement();
 private:
   int increment = 1;
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;//NOLINT
};
sf::ConvexShape createTriangle(double x, double y, double length);
#endif //NOLINT
