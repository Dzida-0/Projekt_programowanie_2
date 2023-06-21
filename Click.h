#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Shape
{
public:
	Shape(sf::Vector2f size) {
		shape.setSize(size);
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineThickness(1.f);
		shape.setOutlineColor(sf::Color::Black);
	}
	
		sf::RectangleShape shape;
	
	bool selected = false;

	Shape() {};
};
class Circle 
{
public:

	Circle(sf::Vector2f size) {
		shape.setRadius(5);
		shape.setFillColor(sf::Color::Green);
		shape.setOutlineThickness(1.f);
		shape.setOutlineColor(sf::Color::Black);
	}
	
	sf::CircleShape shape;
	

	Circle() {};
};


class Buttons
{
protected:
	int x{}, y{}, sizeText{};
public:
	
	int var1 = 1;
	int var2 = 3;
	int spritesize = 60;
	
	Buttons(int xx, int yy, int sizeT);
	Buttons() {};
	void setSprite(string spritename);
	void setText(string a, string fontname);
	sf::Font font;
	sf::Sprite sprite;
	sf::Text text;
};
class Document :public Buttons
{
public:
	string Doc = "";
	Document(int xx, int yy, int sizeT);
	string createDoc(string* x,int i);
	void displayDoc();
};


