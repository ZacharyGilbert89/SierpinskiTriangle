// Copyright 2022 Zachary Gilbert
#include "Triangle.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
void fTree(Triangle* triangle, int len, int count, int times);
int main(int argc, char* argv[]) {
    const double dispSize = 1000;
    sf::RenderWindow window(sf::VideoMode(dispSize, dispSize), "PS3");
    sf::RectangleShape background;
    sf::RenderTexture finalImage;//Render Texture
    sf::Sprite backgroundSprite; //Background Sprite
    background.setSize(sf::Vector2f(dispSize, dispSize));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color::White);
    int L = atof(argv[1]);
    int N = atof(argv[2]);
    Triangle branch;
    branch.Tree.push_back(createTriangle(dispSize/2, dispSize/2, L)); // Base triangle
    finalImage.create(dispSize, dispSize);
    finalImage.clear(sf::Color::White);

    fTree(&branch, L, 0, N);

    std::cout << branch.Tree.size() << std::endl;
    for (int i = 0; i < branch.Tree.size(); ++i) {
        finalImage.draw(branch.Tree[i]);//Draws the triangles to the render texture
    }
    finalImage.display();
    backgroundSprite.setTexture(finalImage.getTexture());//Sets the render texture to the sprite
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.draw(background);
        window.draw(backgroundSprite);//Sprite is rendered as a texture instead of constantly drawing X amount of triangles.
        window.display();
    }
    return 0;
}
void fTree(Triangle* triangle, int len, int count, int times) {
    double tempx;
    double tempy;
    int inc;
    double height = sqrt((len/2.0 * len/2.0) - ((len/2.0)/2.0 * (len/2.0)/2.0));
    if (times == 0) {
        return;
    } else {
    tempx = abs(triangle->Tree[count].getPoint(0).x)-
        triangle->Tree[count].getPosition().x;
    tempy = abs(triangle->Tree[count].getPoint(0).y)-
        triangle->Tree[count].getPosition().y+height/2.0;
    triangle->Tree.push_back(createTriangle(-tempx, -tempy, len/2.0)); //Left triangle

    tempx = triangle->Tree[count].getPosition().x-
        abs(triangle->Tree[count].getPoint(1).x)+len+len/4.0;

    tempy = triangle->Tree[count].getPosition().y-
        abs(triangle->Tree[count].getPoint(1).y)+height/2.0;

    triangle->Tree.push_back(createTriangle(tempx, tempy, len/2.0)); //Right triangle

    tempx = triangle->Tree[count].getPosition().x-
        abs(triangle->Tree[count].getPoint(2).x)-len/4.0;

    tempy = triangle->Tree[count].getPosition().y+
        abs(triangle->Tree[count].getPoint(2).y)+height/2.0;
    triangle->Tree.push_back(createTriangle(tempx, tempy, len/2.0)); //Bottom Triangle
    count++;
    inc = triangle->getIncrement();
    if (count == inc) { //This if statement is used to help draw out the triangles in the right order
        len *= .5;
        inc = (triangle->getIncrement() * 3) + 1;
        triangle->setIncrement(inc);
        times--;
    }
        fTree(triangle, len, count, times);//recursion call
    }
}
