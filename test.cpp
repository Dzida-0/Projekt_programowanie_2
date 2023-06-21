#include <SFML/Graphics.hpp>
#include "Click.h"
#include "Data.h"
#include <vector>
#include <string>

using namespace std;

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp); //Check if ywo shapes contain one another

int main()
{

    sf::RenderWindow window(sf::VideoMode(740, 580), "Paper, please", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60); // Limit the frame rate to 60 FPS
    // Disable window resizing
    int mode = 0; // 0 - menu, 1 - game, 2 - instruction, 3 - authors
    bool dragging = false;
    bool doc_view = false;
    bool pop_info_active = false;

    std::vector<Shape> shapeVec;
    Shape* currentShape = nullptr;          // keep track of current shape being moved
    for (int i = 0; i < 2; ++i) {
        auto shape = new Shape({ 90,30 });
        if (i == 1)
        {
            shape->shape.setPosition(window.getPosition().x / 1.2, window.getPosition().y / 1.6);
        }
        if (i == 0)
        {
            shape->shape.setPosition(window.getPosition().x / 8, window.getPosition().y / 1.6);
            shape->shape.setFillColor(sf::Color::Red);


        }
        shapeVec.push_back(*shape);
    }

    int num = 3;
    std::vector<Circle> circlevec;

    Circle* currentCircle = nullptr;          // keep track of current live
    for (int i = 0; i < num; ++i)
    {
        auto shape = new Circle({ 90,30 });
        shape->shape.setPosition(window.getPosition().x / 6 + 15 * i, window.getPosition().y / 20);
        shape->shape.setFillColor(sf::Color::Red);
        circlevec.push_back(*shape);
    }
    //creating all of buttons
    //////////////////////////////////////////////////////////////////////////
    Buttons zero(window.getSize().x / 4, window.getSize().y / 20, 34);
    zero.setText("PAPERS, PLEASE", "arial.ttf");

    Buttons one(window.getSize().x / 3, window.getSize().y / 6, 24);
    one.setSprite("texture.png");
    one.setText("Play", "arial.ttf");

    Buttons two(window.getSize().x / 3, window.getSize().y / 3, 24);;
    two.setSprite("texture.png");
    two.setText("Instructions", "arial.ttf");

    Buttons three(window.getSize().x / 3, window.getSize().y / 2, 24);;
    three.setSprite("heart.png");
    three.setText("Authors", "arial.ttf");

    Buttons four(window.getSize().x / 3, window.getSize().y / 4, 24);;
    four.setSprite("texture.png");
    four.setText("Documents", "arial.ttf");

    Buttons pop_info(window.getSize().x / 22, window.getSize().y / 2, 20); // instructions 
    pop_info.var1 = 3;
    pop_info.var2 = 5;
    pop_info.setSprite("texture.png");
    pop_info.setText("Check the correctess\n of the name \n and whether the document\n is expaired", "arial.ttf");

    Buttons info(window.getSize().x / 10, window.getSize().y / 6, 24); //explanation of the game
    info.var1 = 5;
    info.var2 = 4;
    info.setSprite("texture.png");
    info.setText("You're a border \n inspector who \n regulates the border\n checkpoint. You \n must determine  who\n to admit and who to\n keep out. \n Good luck.", "arial.ttf");

    Buttons authors(window.getSize().x / 10, window.getSize().y / 6, 24);
    authors.var1 = 5;
    authors.var2 = 5;
    authors.setSprite("texture.png");
    authors.setText(" Authors:\n Dominik Dzida \n Damian Fliegiel \n Martyna Kramarz \n ", "arial.ttf");

    Buttons instruct(window.getSize().x / 21, window.getSize().y / 14, 16);
    instruct.spritesize = 20;
    instruct.setSprite("texture.png");
    instruct.setText("How", "arial.ttf");

    Buttons live(window.getPosition().x / 17, window.getPosition().y / 20, 16);
    live.spritesize = 20;
    live.setSprite("texture.png");
    live.setText("Lives ", "arial.ttf");

    Buttons point(window.getPosition().x / 1.3, window.getPosition().y / 25, 16);
    int score = 0; // the score to print
    string sc = "Score: ";
    point.setText(sc + to_string(score), "arial.ttf");
    point.setSprite("texture.png");
    ////////////////////////////////////////////////
    Data dat;
    string* stri = dat.utworz_osobe();
    Document doc1(window.getSize().x / 2, window.getSize().y / 2, 20);
    doc1.var1 = 3;
    doc1.var2 = 5;
    doc1.createDoc(stri, 0);
    doc1.displayDoc();
    Document doc2(10, window.getSize().y / 2, 20);
    doc2.var1 = 3;
    doc2.var2 = 5;
    doc2.createDoc(stri, 1);
    doc2.displayDoc();
    /////////////////////////////////////////////////

   
    bool done = false;
    sf::Event event;
    auto mpos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
         // get the mouse position
         mpos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                if (mode == 0)
                    window.close();
                else
                {
                    if (mode == 1)
                    {
                        doc_view = false;
                        pop_info_active = false;
                        four.setText("Documents", "arial.ttf");
                        shapeVec[0].shape.setFillColor(sf::Color::Red);
                        shapeVec[1].shape.setFillColor(sf::Color::Green);
                        string* stri = dat.utworz_osobe();
                        doc1.createDoc(stri, 0);
                        doc1.displayDoc();
                        doc2.createDoc(stri, 1);
                        doc2.displayDoc();
                        done = false;
                        num = 3;
                        score = 0;
                        point.setText(sc + to_string(score), "arial.ttf");
                        shapeVec[0].shape.setPosition(window.getPosition().x / 8, window.getPosition().y / 1.6);
                        shapeVec[1].shape.setPosition(window.getPosition().x / 1.2, window.getPosition().y / 1.6);
                    }
                    mode = 0;
                }
            }
            if (mode == 0 && event.type == sf::Event::MouseButtonPressed)
            {
                if (isSpriteHover(one.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    mode = 1;
                else if (isSpriteHover(two.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    mode = 2;
                else if (isSpriteHover(three.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    mode = 3;

            }
            else if (mode == 1 && event.type == sf::Event::MouseButtonPressed)
            {
                if (isSpriteHover(instruct.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    pop_info_active = !pop_info_active;
                if (isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                    doc_view = !doc_view;
                if (done && num > 0 && isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                {
                    doc_view = false;
                    four.setText("Documents", "arial.ttf");
                    shapeVec[0].shape.setFillColor(sf::Color::Red);
                    shapeVec[1].shape.setFillColor(sf::Color::Green);
                    string* stri = dat.utworz_osobe();
                    doc1.createDoc(stri, 0);
                    doc1.displayDoc();
                    doc2.createDoc(stri, 1);
                    doc2.displayDoc();
                    shapeVec[0].shape.setPosition(window.getPosition().x / 8, window.getPosition().y / 1.6);
                    shapeVec[1].shape.setPosition(window.getPosition().x / 1.2, window.getPosition().y / 1.6);
                    done = false;
                }
                else if (done && num == 0 && isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true)
                   four.setText("GAME OVER", "arial.ttf");      
            }
        }
        if (mode == 1)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (mpos.x >= 0 && mpos.x < window.getSize().x && mpos.y >= 0 * mpos.y < window.getSize().y && !dragging)
                {
                    dragging = true;
                    for (auto& it : shapeVec)
                    {
                        if (it.shape.getGlobalBounds().contains(mpos.x, mpos.y))
                        {
                            it.selected = true;
                            currentShape = &it;
                            break;
                        }
                    }
                }
            }
            else
            {
                dragging = false;
                if (currentShape)
                    currentShape->selected = false;
            }
            if (dragging == true) {

                for (int i = 0; i < 2; i++) {

                    if (shapeVec[i].selected)
                    {
                        shapeVec[i].shape.setPosition(mpos.x, mpos.y);
                        if ((isSpriteHover(four.sprite.getGlobalBounds(), sf::Vector2f(shapeVec[i].shape.getPosition().x, shapeVec[i].shape.getPosition().y)) == true)&& !done)
                        {
                            if (i == 0)
                            {
                                shapeVec[i].shape.setFillColor(sf::Color::Magenta);
                                if (!dat.poprawnosc_danych)
                                {
                                    four.setText("Good ", "arial.ttf");
                                    score++;
                                    point.setText(sc + to_string(score), "arial.ttf");
                                }
                                else
                                {
                                    four.setText("Bad ", "arial.ttf");
                                    num--;

                                }
                                done = true;
                            }
                            if (i == 1)
                            {
                                shapeVec[i].shape.setFillColor(sf::Color::Cyan);
                                if (dat.poprawnosc_danych)
                                {
                                    four.setText("Good ", "arial.ttf");
                                    score++;
                                    point.setText(sc + to_string(score), "arial.ttf");
                                }
                                else
                                {
                                    four.setText("Bad ", "arial.ttf");
                                    num--;

                                }
                                done = true;

                            }
                        }
                    }
                }
            }
        }
        window.clear();
            if (mode == 0)
            {
                window.draw(zero.text);
                window.draw(one.sprite);
                window.draw(one.text);
                window.draw(two.sprite);
                window.draw(two.text);
                window.draw(three.sprite);
                window.draw(three.text);
            }
            else if (mode == 1)
            {
                for (int i = 0; i < shapeVec.size(); ++i) {
                    window.draw(shapeVec[i].shape);
                }
                for (int i = 0; i < num; i++) {
                    window.draw(circlevec[i].shape);
                }

                window.draw(four.sprite);
                window.draw(four.text);
                window.draw(instruct.sprite);
                window.draw(instruct.text);
                if (pop_info_active == true)
                {
                    window.draw(pop_info.sprite);
                    window.draw(pop_info.text);
                }
                if (doc_view == 1)
                {
                    window.draw(doc1.sprite);
                    window.draw(doc1.text);
                    window.draw(doc2.sprite);
                    window.draw(doc2.text);
                }
                window.draw(live.sprite);
                window.draw(live.text);

                window.draw(point.sprite);
                window.draw(point.text);
            }
            else if (mode == 2)
            {
                window.draw(info.sprite);
                window.draw(info.text);
            }
            else if (mode == 3)
            {
                window.draw(authors.sprite);
                window.draw(authors.text);
            }
            window.display();
        
    }
    return 0;
}
bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp) //Check if two shapes contain one another
{
    if (sprite.contains(mp)) 
        return true;
    return false;
}