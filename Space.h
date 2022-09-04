#pragma once

#include "Coord3D.h"

#define spacesize 4
#define voxelNum (spacesize*spacesize*spacesize)

class Space
{
private:
	int voxels[voxelNum];

public:
	Space();

	int getVoxel(int x, int y, int z) const;
	void setVoxel(int x, int y, int z, int value);
	void addToVoxel(int x, int y, int z, int valueToAdd);
	bool ContainsOverlap() const;

	Space operator+(Space const &theOther);
};