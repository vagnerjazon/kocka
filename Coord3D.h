#pragma once

class Coord3D
{
public:
	int x;
	int y;
	int z;

	Coord3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Coord3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

