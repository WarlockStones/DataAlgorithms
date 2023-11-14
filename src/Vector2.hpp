#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2 {
	float x{}, y{};

	Vector2(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

#endif