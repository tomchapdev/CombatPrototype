#include <assert.h>
#include <string>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

bool LoadTexture(const string& file, Texture& tex)
{
	if (tex.loadFromFile(file))
	{
		tex.setSmooth(true);
		return true;
	}
	assert(false);
	return false;
}