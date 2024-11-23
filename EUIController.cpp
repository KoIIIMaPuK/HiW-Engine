// EUIController.cpp
#include "EUIController.h"
#include <SFML/Graphics.hpp>






void EUIController::onClick() {
    std::cout << "Button clicked!" << std::endl;
}

bool EUIController::press_check(sf::Event& event)
{
    return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && event.mouseButton.x > 640 && event.mouseButton.x < 840 && event.mouseButton.y> 400 && event.mouseButton.y < 600;
}










EUIController::EUIController(float text_size, float x, float y, float width, float height, std::string text)
{
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setPosition(x, y);
    buttonShape.setFillColor(sf::Color::Green);

    // Создание текста кнопки
    font.loadFromFile("Fonts/arialmt.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(text_size);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(
        x + (width / 2.f) - (buttonText.getGlobalBounds().width / 2.f),
        y + (height / 2.f) - (buttonText.getGlobalBounds().height / 2.f)
    );


}

EUIController::EUIController(float text_size, float xy, float x, float y, std::string text)
{
    CbuttonShape.setPosition(x, y);
    CbuttonShape.setRadius(xy);
    CbuttonShape.setFillColor(sf::Color::Green);

    // Создание текста кнопки
    font.loadFromFile("Fonts/arialmt.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(text_size);
    buttonText.setFillColor(sf::Color::White);
    centerText(xy, x, y);
}



void EUIController::update(sf::RenderWindow& window)
{
    if (isMouseOverCircle(window))
    {
        // Изменение цвета при наведении мыши
        CbuttonShape.setFillColor(sf::Color::Blue);

        // Обработка нажатия кнопки
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            onClick();
            //std::cout << "Updating button state..." << std::endl;
        }
    }
    else if (isMouseOver(window))
    {
        // Изменение цвета при наведении мыши
        buttonShape.setFillColor(sf::Color::Blue);

        // Обработка нажатия кнопки
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            onClick();
            //std::cout << "Updating button state..." << std::endl;
        }
    }
    else
    {
        // Если мышь не над кнопкой, устанавливаем цвет обратно
        CbuttonShape.setFillColor(sf::Color::Green);
        buttonShape.setFillColor(sf::Color::Green);
    }
}


EUIController::EUIController(float text_size, float x, float y, float width, float height, std::string text, const sf::Color& button_color, const sf::Color& new_button_color, const sf::Color& text_color)
{
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setPosition(x, y);
    buttonShape.setFillColor(button_color);

    // Создание текста кнопки
    font.loadFromFile("Fonts/arialmt.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(text_size);
    buttonText.setFillColor(text_color);
    buttonText.setPosition(
        x + (width / 2.f) - (buttonText.getGlobalBounds().width / 2.f),
        y + (height / 2.f) - (buttonText.getGlobalBounds().height / 2.f)
    );
}




EUIController::EUIController(float text_size, float xy, float x, float y, std::string text, const sf::Color& button_color, const sf::Color& new_button_color, const sf::Color& text_color)
{
    CbuttonShape.setPosition(x, y);
    CbuttonShape.setRadius(xy);
    CbuttonShape.setFillColor(button_color);

    // Создание текста кнопки
    font.loadFromFile("Fonts/arialmt.ttf");
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(text_size);
    buttonText.setFillColor(text_color);
    centerText(xy, x, y);



}

void EUIController::update(sf::RenderWindow& window, const sf::Color& button_color, const sf::Color& new_button_color)
{
    if (isMouseOverCircle(window))
    {
        // Изменение цвета при наведении мыши
        CbuttonShape.setFillColor(new_button_color);

        // Обработка нажатия кнопки
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            onClick();
            //std::cout << "Updating button state..." << std::endl;
        }
    }
    else if (isMouseOver(window))
    {
        // Изменение цвета при наведении мыши
        buttonShape.setFillColor(new_button_color);

        // Обработка нажатия кнопки
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            onClick();
        }
    }
    else
    {
        // Если мышь не над кнопкой, устанавливаем цвет обратно
        CbuttonShape.setFillColor(button_color);
        buttonShape.setFillColor(button_color);
    }
}




/*x
void EUIController::setNewWindow(std::string bckgrd, const std::string& text, float xw, float yw,sf::Event& event)
{
    sf::Texture texture;
    if (!texture.loadFromFile(bckgrd)) {

    }
    sf::Sprite sprite(texture);



    if (press_check(event))
    {
        sf::RenderWindow Nwindow(sf::VideoMode(xw, yw), text);
        sprite.setScale(
            static_cast<float>(Nwindow.getSize().x) / texture.getSize().x,
            static_cast<float>(Nwindow.getSize().y) / texture.getSize().y
        );

        while (Nwindow.isOpen())
        {
            sf::Event event; // Объявляем переменную события

            // Получаем события из окна
            while (Nwindow.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    Nwindow.close(); // Закрываем окно при получении события закрытия


            }
            Nwindow.clear(); // Очищаем окно
            Nwindow.draw(sprite);
            Nwindow.display(); // Отображаем содержимое окна
        }
    }
}*/

