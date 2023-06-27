#include "Utilities.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


int randRange(int start, int end)
{
	static bool first = true;
	if(first)
	{
		std::srand(static_cast<unsigned>(time(NULL)));
		first = false;
	}
	if (start == end) return start;
	return (std::rand() % ((end + 1) - start)) + start;
}

float length(sf::Vector2f vector)
{
	return static_cast<float>(std::sqrt(vector.x * vector.x + vector.y * vector.y));
}

sf::Vector2i abs(sf::Vector2i vector)
{
	vector.x = abs(vector.x);
	vector.y = abs(vector.y);
	return vector;
}