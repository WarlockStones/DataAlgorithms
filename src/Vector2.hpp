#ifndef VECTOR2_H
#define VECTOR2_H
#include <functional> // std::hash

struct Vector2 {
	float x{}, y{};

	Vector2(float x = 0.0f, float y = 0.0f)
	{
		this->x = x;
		this->y = y;
	}

  ~Vector2() = default;

	friend bool operator== (const Vector2& left, const Vector2& right) {
		if (left.x == right.x || left.y == right.y)
				return true;
		return false;
	}
};

template<>
struct std::hash<Vector2>
{
	std::size_t operator()(const Vector2& v) const noexcept
	{
		// To be honest, I do not really know what I am doing, just copied cppreference...
		std::size_t h1 = std::hash<int>{}(v.x);
		std::size_t h2 = std::hash<int>{}(v.y);
		return h1 ^ (h2 << 1); // Bitwise operators. Optimizing store bools in ints and stuff
	}

};

#endif
