#include "Part.h"


bool Part::isTranslatableAlongX(int steps) const
{
	for (int i = (4 - steps); i < 4; i++) //x
		for (int j = 0; j < 4; j++) //y
			for (int k = 0; k < 4; k++) //z
				if(getVoxel(i, j, k))
					return false;
	return true;
}

bool Part::isTranslatableAlongY(int steps) const
{
	for (int i = 0; i < 4; i++) //x
		for (int j = (4 - steps); j < 4; j++) //y
			for (int k = 0; k < 4; k++) //z
				if (getVoxel(i, j, k))
					return false;
	return true;
}

bool Part::isTranslatableAlongZ(int steps) const
{
	for (int i = 0; i < 4; i++) //x
		for (int j = 0; j < 4; j++) //y
			for (int k = (4 - steps); k < 4; k++) //z
				if (getVoxel(i, j, k))
					return false;
	return true;
}

void Part::translateAlongX(int steps)
{
	while (steps--)
		for (int i = 3; i >= 0; i--) //x //from 3!
			for (int j = 0; j < 4; j++) //y
				for (int k = 0; k < 4; k++) //z
					if (i == 0)
						setVoxel(i, j, k, 0);
					else
						setVoxel(i, j, k, getVoxel(i - 1, j, k)); //i-1
}

void Part::translateAlongY(int steps)
{
	while (steps--)
		for (int i = 0; i < 4; i++) //x
			for (int j = 3; j >= 0; j--) //y //from 3!
				for (int k = 0; k < 4; k++) //z
					if (j == 0)
						setVoxel(i, j, k, 0);
					else
						setVoxel(i, j, k, getVoxel(i, j - 1, k)); //j-1
}

void Part::translateAlongZ(int steps)
{
	while (steps--)
		for (int i = 0; i < 4; i++) //x
			for (int j = 0; j < 4; j++) //y
				for (int k = 3; k >= 0; k--) //z //from 3!
					if (k == 0)
						setVoxel(i, j, k, 0);
					else
						setVoxel(i, j, k, getVoxel(i, j, k - 1)); //k-1
}

void Part::rotXfaceP90() //rotation around the X direction, (the axis is in the middle of the cube face)
{
	Part copy = *this;
	for (int i = 0; i < 4; i++) //x (going through slices perpendicular to the X axis)
		for (int j = 0; j < 4; j++) //y
			for (int k = 0; k < 4; k++) //z
				this->setVoxel(i, (-k + 3), j, copy.getVoxel(i, j, k));
}

void Part::rotXfaceM90()
{
	Part copy = *this;
	for (int i = 0; i < 4; i++) //x
		for (int j = 0; j < 4; j++) //y
			for (int k = 0; k < 4; k++) //z
				this->setVoxel(i, k, (-j + 3), copy.getVoxel(i, j, k));
}

void Part::rotYfaceP90()
{
	Part copy = *this;
	for (int j = 0; j < 4; j++) //y
		for (int i = 0; i < 4; i++) //x
			for (int k = 0; k < 4; k++) //z
				this->setVoxel(k, j, (-i + 3), copy.getVoxel(i, j, k));
}

void Part::rotYfaceM90()
{
	Part copy = *this;
	for (int j = 0; j < 4; j++) //y
		for (int i = 0; i < 4; i++) //x
			for (int k = 0; k < 4; k++) //z
				this->setVoxel((-k + 3), j, i, copy.getVoxel(i, j, k));
}

void Part::rotZfaceP90()
{
	Part copy = *this;
	for (int k = 0; k < 4; k++) //z
		for (int i = 0; i < 4; i++) //x
			for (int j = 0; j < 4; j++) //y
				this->setVoxel((-j + 3), i, k, copy.getVoxel(i, j, k));
}

void Part::rotZfaceM90()
{
	Part copy = *this;
	for (int k = 0; k < 4; k++) //z
		for (int i = 0; i < 4; i++) //x
			for (int j = 0; j < 4; j++) //y
				this->setVoxel(j, (-i + 3), k, copy.getVoxel(i, j, k));
}

void Part::applyRotation(int orientationIndex)
{
	for (int i = 0; i < 4; i++)
	{
		if (possibleOrientations[orientationIndex][i] == nullptr)
			break;
		(this->*possibleOrientations[orientationIndex][i])();
	}
}
