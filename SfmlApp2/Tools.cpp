#include "stdafx.h"
#include "Tools.h"

sf::Font loadFontFromFile(const char* fontName)
{
	sf::Font font;
	if (!font.loadFromFile(fontName))
		throw std::bad_exception();
	return font;
}

sf::Texture loadImageFromFile(const char * fileName)
{
	sf::Texture image;
	image.loadFromFile(fileName);
	return image;
}
