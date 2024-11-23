#include "EActor.h"

/**
*
*   @ABOUT:
*       �����������, ������� �������������� ����� � �������� �������� � ���������.
*
*   @PARAM position: ������� ����� �� �����.
*   @PARAM texturePath: ���� � �������� ��� �����.
*
*   @THROW std::runtime_error: ���� �������� �� ����� ���� ���������.
*
*/
EActor::EActor(const sf::Vector2f position, const std::string& texturePath)
    : position(position), velocity(0, 0), rotation(0.0), scaleX(1.0f), scaleY(1.0f)
{
    // ================================================================================================
    //
    // ���� ���:
    //      ��������� �������� �� �������� �������� �������� �� ����� 
    //      ������������ ��������� ������
    //
    if (!objectTexture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture from: " + texturePath);
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� �������� �������
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� ������� �������
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================

}







/**
*
*   @ABOUT:
*       ����������� �� ���������, ������� �������������� ����� � ��������� �� ���������.
*
*   @THROW std::runtime_error: ���� �������� �� ����� ���� ���������.
*
*/
EActor::EActor()
    : position(0, 0), velocity(0, 0), rotation(0.0), scaleX(1.0f), scaleY(1.0f)
{
    // ================================================================================================
    //
    // ���� ���:
    //      ��������� �������� �� �������� �������� �������� �� ����� 
    //      ������������ ��������� ������
    //
    if (!objectTexture.loadFromFile("Images/BlackUnitExpectation1.png"))
    {
        throw std::runtime_error("Failed to load texture from: Images/BlackUnitExpectation1.png");
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� �������� �������
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� ������� �������
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================
}








/**
*
*   @ABOUT:
*       �����������, ������� �������������� ����� � �������� �������� � ��������� �� ���������.
*
*   @PARAM position: ������� ����� �� �����.
*
*   @THROW std::runtime_error: ���� �������� �� ����� ���� ���������.
*
*/
EActor::EActor(const sf::Vector2f position)
    : position(position), velocity(0, 0), rotation(0.0), scaleX(1.0f), scaleY(1.0f)
{
    // ================================================================================================
    //
    // ���� ���:
    //      ��������� �������� �� �������� �������� �������� �� ����� 
    //      ������������ ��������� ������
    //
    if (!objectTexture.loadFromFile("Images/BlackUnitExpectation1.png"))
    {
        throw std::runtime_error("Failed to load texture from: Images/BlackUnitExpectation1.png");
    }
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� �������� �������
    //
    objectActorSprite.setTexture(objectTexture);
    //
    // ================================================================================================

    // ================================================================================================
    //
    // ������������� ������� �������
    //
    objectActorSprite.setPosition(this->position);
    //
    // ================================================================================================
}









/**
*
*   @ABOUT:
*       ����� ��� ��������� ����� �� �������� ����.
*
*   @PARAM window: ����, �� ������� ����� ��������� ����.
*
*/
void EActor::draw(sf::RenderWindow& window)
{
    window.draw(objectActorSprite);
}









/**
*
*   @ABOUT:
*       ��������� ������� �����.
*
*   @PARAM position: ����� ������� �����.
*
*/
void EActor::setPosition(const sf::Vector2f& position)
{
    this->position = position;
}










/**
*
*   @ABOUT:
*       ��������� ������� ������� �����.
*
*   @RETURN: ������� ������� �����.
*
*/
sf::Vector2f EActor::getPosition()
const {
    return this->position;
}










/**
*
*   @ABOUT:
*       ��������� ���� �������� �����.
*
*   @PARAM angle: ����� ���� �������� �����.
*
*/
void EActor::setRotation(float angle)
{
    this->rotation = angle;
}










/**
*
*   @ABOUT:
*       ��������� ���� �������� �����.
*
*   @RETURN: ������� ���� �������� �����.
*
*/
float EActor::getRotation()
const {
    return this->rotation;
}










/**
*
*   @ABOUT:
*       ��������� �������� �����.
*
*   @PARAM velocity: ����� �������� �����.
*
*/
void EActor::setVelocity(const sf::Vector2f& velocity)
{
    this->velocity = velocity;
}










/**
*
*   @ABOUT:
*       ��������� �������� �����.
*
*   @RETURN: ������� �������� �����.
*
*/
sf::Vector2f EActor::getVelocity()
const {
    return this->velocity;
}














/**
*
*   @ABOUT:
*       ���������� ��������� ����� �� ������ ���������� �������.
*       ����� ��������� ������� �����, �������� �������� � ��������� ��������.
*       ����� ������������� ������� � ���� �������� �������.
*
*   @PARAM deltaTime: �����, ��������� � ���������� ���������� (� ��������).
* 
*   @EXAMPLE:
*       ��� ������������� ������ Update, ����� ������������ sf::Clock ��� ��������� 
*       �������� deltaTime. ������:
*
*       sf::Clock clock;
*       while (window.isOpen()) {
*           // ��������� �������...
*
*           float deltaTime = clock.restart().asSeconds(); // �������� ����� � ���������� �����
*           actor.Update(deltaTime); // ��������� ��������� �����
*
*           // ���������...
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
*       ��������� ������� ����� �� ���� ���� (X � Y).
*       ������������� ���������� ������� ��� ����� ����.
*
*   @PARAM scaleXY: ����� ������� ��� ����� ����.
*
*   @EXAMPLE:
*       actor.setScaleXY(1.5f); // ���������� ������� ����� �� 150%
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
*       ��������� ������� ����� �� ��� X.
*       ������������� ����� ������� ��� ��� X.
*
*   @PARAM scaleX: ����� ������� ��� ��� X.
*
*   @EXAMPLE:
*       actor.setScaleX(2.0f); // ���������� ������� ����� �� ��� X �� 200%
*
*/
void EActor::setScaleX(const float scaleX)
{
    this->scaleX = scaleX;
}








/**
*
*   @ABOUT:
*       ��������� ������� ����� �� ��� Y.
*       ������������� ����� ������� ��� ��� Y.
*
*   @PARAM scaleY: ����� ������� ��� ��� Y.
*
*   @EXAMPLE:
*       actor.setScaleY(0.5f); // ���������� ������� ����� �� ��� Y �� 50%
*
*/
void EActor::setScaleY(const float scaleY)
{
    this->scaleY = scaleY;
}