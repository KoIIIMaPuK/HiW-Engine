#include "GGenerator.h"

GGenerator::GGenerator(int width, int height)
	: width(width), height(height), level(height, std::vector<TileType>(width, EMPTY))
{
	generatorLevel();
	if (!this->texture.loadFromFile("Images/BlockGrass.png"))
	{
		std::cerr << "Faild load to file";
	}
}





void GGenerator::generatorLevel()
{
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y) {
			level[2][x] = BlockGrass;
		}
	}
}





void GGenerator::printLevel(sf::RenderWindow& window) const
{
	float tileSize = 64.0f;


	for (size_t y = 0; y < level.size(); ++y) {
		for (size_t x = 0; x < level[y].size(); ++x) {
			sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
			tile.setPosition(x * tileSize, y * tileSize);

			if (level[y][x] == BlockGrass) {


				tile.setTexture(&texture);					// G - Grass
			}
			else {
				tile.setFillColor(sf::Color::Transparent);	// . - Empty
			}

			window.draw(tile);
		}
	}
}