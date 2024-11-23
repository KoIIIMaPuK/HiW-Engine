#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class EUIController
{
private:
    sf::CircleShape CbuttonShape;

    sf::RectangleShape buttonShape;
    sf::RectangleShape background;
    sf::RenderWindow button_window;
    sf::Text buttonText;
    sf::Font font;

public:
    EUIController(float text_size, float x, float y, float width, float height, std::string text);
    EUIController(float text_size, float xy, float x, float y, std::string text);
    EUIController(float text_size, float x, float y, float width, float height, std::string text, const sf::Color& button_color, const sf::Color& new_button_color, const sf::Color& text_color);
    EUIController(float text_size, float xy, float x, float y, std::string text, const sf::Color& button_color, const sf::Color& new_button_color, const sf::Color& text_color);


    void draw(sf::RenderWindow& window)
    {
        window.draw(buttonShape);
        window.draw(CbuttonShape);
        window.draw(buttonText);
    }

    bool isMouseOverCircle(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        return CbuttonShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    }
    bool isMouseOver(sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        return buttonShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    }

    void update(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, const sf::Color& button_color, const sf::Color& new_button_color);

    void onClick();


    //void setNewWindow( std::string bckgrd, const std::string& text, float xw, float yw, sf::Event& event);

    bool press_check(sf::Event& event);

    void centerText(float radius, float x, float y) {
        // Центрирование текста в круге
        sf::FloatRect textBounds = buttonText.getLocalBounds();
        buttonText.setOrigin(textBounds.width / 2, textBounds.height / 2);
        buttonText.setPosition(x + radius, y + radius); // Центрирование текста относительно центра круга
    }


};