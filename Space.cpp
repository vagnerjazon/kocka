#include "Space.h"

Space::Space()
{
	for (int i = 0; i < voxelNum; i++)
	{
		this->voxels[i] = 0;
	}
}

int Space::getVoxel(int x, int y, int z) const
{
	return voxels[(z * spacesize * spacesize) + (y * spacesize) + x];
}

void Space::setVoxel(int x, int y, int z, int value)
{
	voxels[(z * spacesize * spacesize) + (y * spacesize) + x] = value;
}

void Space::addToVoxel(int x, int y, int z, int valueToAdd)
{
	setVoxel(x, y, z, getVoxel(x, y, z) + valueToAdd);
}

bool Space::ContainsOverlap() const
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				if (getVoxel(i, j, k) > 1)
					return true;
	return false;
}

Space Space::operator+(Space const& theOther)
{
	Space ret = *this;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				ret.addToVoxel(i, j, k, theOther.getVoxel(i, j, k));
	return ret;
}