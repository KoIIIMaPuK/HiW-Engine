#include "EActor.h"

/**
*
*   @ABOUT:
*       Конструктор, который инициализирует актёра с заданной позицией и текстурой.
*
*   @PARAM position: Позиция актёра на сцене.
*   @PARAM texturePath: Путь к текстуре для актёра.
*
*   @THROW std::runtime_error: Если текстура не может быть загружена.
*
*/
EActor::EActor(const sf::Vector2f position, const std::string& texturePath)
    : position(position), velocity(0, 0), rotation(0.0), scaleX(1.0f), scaleY(1.0f)
{
    // ================================================================================================
    //
    // Этот код:
    //      выполняет проверку на успешную загрузку текстуры из файла 
    //      обрабатывает возможную ошибку
    //
    if (!objectTexture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture from: " + texturePath);
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // Устанавливаем текстуру спрайту
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // Устанавливаем позицию спрайта
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================

}







/**
*
*   @ABOUT:
*       Конструктор по умолчанию, который инициализирует актёра с текстурой по умолчанию.
*
*   @THROW std::runtime_error: Если текстура не может быть загружена.
*
*/
EActor::EActor()
    : position(0, 0), velocity(0, 0), rotation(0.0), scaleX(1.0f), scaleY(1.0f)
{
    // ================================================================================================
    //
    // Этот код:
    //      выполняет проверку на успешную загрузку текстуры из файла 
    //      обрабатывает возможную ошибку
    //
    if (!objectTexture.loadFromFile("Images/BlackUnitExpectation1.png"))
    {
        throw std::runtime_error("Failed to load texture from: Images/BlackUnitExpectation1.png");
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // Устанавливаем текстуру спрайту
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // Устанавливаем позицию спрайта
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================
}








/**
*
*   @ABOUT:
*       Конструктор, который инициализирует актёра с заданной позицией и текстурой по умолчанию.
*
*   @PARAM position: Позиция актёра на сцене.
*
*   @THROW std::runtime_error: Если текстура не может быть загружена.
*
*/
EActor::EActor(const sf::Vector2f position)
    : position(position), velocity(0, 0), rotation(0.0), scaleX(1.0f), scaleY(1.0f)
{
    // ================================================================================================
    //
    // Этот код:
    //      выполняет проверку на успешную загрузку текстуры из файла 
    //      обрабатывает возможную ошибку
    //
    if (!objectTexture.loadFromFile("Images/BlackUnitExpectation1.png"))
    {
        throw std::runtime_error("Failed to load texture from: Images/BlackUnitExpectation1.png");
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // Устанавливаем текстуру спрайту
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // Устанавливаем позицию спрайта
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================
}









/**
*
*   @ABOUT:
*       Метод для отрисовки актёра на заданном окне.
*
*   @PARAM window: Окно, на котором будет отрисован актёр.
*
*/
void EActor::draw(sf::RenderWindow& window)
{
    window.draw(objectActorSprite);
}









/**
*
*   @ABOUT:
*       Установка позиции актёра.
*
*   @PARAM position: Новая позиция актёра.
*
*/
void EActor::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}










/**
*
*   @ABOUT:
*       Получение текущей позиции актёра.
*
*   @RETURN: Текущая позиция актёра.
*
*/
sf::Vector2f EActor::getPosition()
const {
    return this->position;
}










/**
*
*   @ABOUT:
*       Установка угла поворота актёра.
*
*   @PARAM angle: Новый угол поворота актёра.
*
*/
void EActor::setRotation(float angle)
{
    this->rotation = angle;
}










/**
*
*   @ABOUT:
*       Получение угла поворота актёра.
*
*   @RETURN: Текущий угол поворота актёра.
*
*/
float EActor::getRotation()
const {
    return this->rotation;
}










/**
*
*   @ABOUT:
*       Установка скорости актёра.
*
*   @PARAM velocity: Новая скорость актёра.
*
*/
void EActor::setVelocity(const sf::Vector2f& velocity)
{
    this->velocity = velocity;
}










/**
*
*   @ABOUT:
*       Получение скорости актёра.
*
*   @RETURN: Текущая скорость актёра.
*
*/
sf::Vector2f EActor::getVelocity()
const {
    return this->velocity;
}














/**
*
*   @ABOUT:
*       Обновление состояния актёра на основе прошедшего времени.
*       Метод обновляет позицию актёра, применяя скорость и временной интервал.
*       Также устанавливает масштаб и угол поворота спрайта.
*
*   @PARAM deltaTime: Время, прошедшее с последнего обновления (в секундах).
* 
*   @EXAMPLE:
*       Для использования метода Update, можно использовать sf::Clock для получения 
*       значения deltaTime. Пример:
*
*       sf::Clock clock;
*       while (window.isOpen()) {
*           // Обработка событий...
*
*           float deltaTime = clock.restart().asSeconds(); // Получаем время с последнего кадра
*           actor.Update(deltaTime); // Обновляем состояние актёра
*
*           // Отрисовка...
*       }
*
*/
void EActor::Update(float deltaTime)
{
    this->position += this->velocity * deltaTime;
    this->objectActorSprite.setScale(this->scaleX, this->scaleY);
    this->objectActorSprite.setPosition(this->position);
    this->objectActorSprite.setRotation(this->rotation);
}









/**
*
*   @ABOUT:
*       Изменение размера актёра по двум осям (X и Y).
*       Устанавливает одинаковый масштаб для обеих осей.
*
*   @PARAM scaleXY: Новый масштаб для обеих осей.
*
*   @EXAMPLE:
*       actor.setScaleXY(1.5f); // Установить масштаб актёра на 150%
*
*/
void EActor::setScaleXY(const float scaleXY)
{
    scaleX = scaleXY;
    scaleY = scaleXY;
}








/**
*
*   @ABOUT:
*       Изменение размера актёра по оси X.
*       Устанавливает новый масштаб для оси X.
*
*   @PARAM scaleX: Новый масштаб для оси X.
*
*   @EXAMPLE:
*       actor.setScaleX(2.0f); // Установить масштаб актёра по оси X на 200%
*
*/
void EActor::setScaleX(const float scaleX)
{
    this->scaleX = scaleX;
}








/**
*
*   @ABOUT:
*       Изменение размера актёра по оси Y.
*       Устанавливает новый масштаб для оси Y.
*
*   @PARAM scaleY: Новый масштаб для оси Y.
*
*   @EXAMPLE:
*       actor.setScaleY(0.5f); // Установить масштаб актёра по оси Y на 50%
*
*/
void EActor::setScaleY(const float scaleY)
{
    this->scaleY = scaleY;
}