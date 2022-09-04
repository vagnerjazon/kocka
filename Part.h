#pragma once

#include "Space.h"
#include "Coord3D.h"

class Part : public Space
{
private:
	void(Part::*orientation_0[4])()  = { nullptr,				nullptr,				nullptr,				nullptr };
	void(Part::*orientation_1[4])()  = { &Part::rotZfaceP90,	nullptr,				nullptr,				nullptr };
	void(Part::*orientation_2[4])()  = { &Part::rotZfaceP90,	&Part::rotZfaceP90,		nullptr,				nullptr };
	void(Part::*orientation_3[4])()  = { &Part::rotZfaceM90,	nullptr,				nullptr,				nullptr };

	void(Part::*orientation_4[4])()  = { &Part::rotXfaceP90,	nullptr,				nullptr,				nullptr };
	void(Part::*orientation_5[4])()  = { &Part::rotXfaceP90,	&Part::rotYfaceP90,		nullptr,				nullptr };
	void(Part::*orientation_6[4])()  = { &Part::rotXfaceP90,	&Part::rotYfaceP90,		&Part::rotYfaceP90,		nullptr };
	void(Part::*orientation_7[4])()  = { &Part::rotXfaceP90,	&Part::rotYfaceM90,		nullptr,				nullptr };

	void(Part::*orientation_8[4])()  = { &Part::rotXfaceM90,	nullptr,				nullptr,				nullptr };
	void(Part::*orientation_9[4])()  = { &Part::rotXfaceP90,	&Part::rotYfaceP90,		nullptr,				nullptr };
	void(Part::*orientation_10[4])() = { &Part::rotXfaceP90,	&Part::rotYfaceP90,		&Part::rotYfaceP90,		nullptr };
	void(Part::*orientation_11[4])() = { &Part::rotXfaceP90,	&Part::rotYfaceM90,		nullptr,				nullptr };

	void(Part::*orientation_12[4])() = { &Part::rotYfaceP90,	nullptr,				nullptr,				nullptr };
	void(Part::*orientation_13[4])() = { &Part::rotYfaceP90,	&Part::rotXfaceP90,		nullptr,				nullptr };
	void(Part::*orientation_14[4])() = { &Part::rotYfaceP90,	&Part::rotXfaceP90,		&Part::rotXfaceP90,		nullptr };
	void(Part::*orientation_15[4])() = { &Part::rotYfaceP90,	&Part::rotXfaceM90,		nullptr,				nullptr };

	void(Part::*orientation_16[4])() = { &Part::rotYfaceM90,	nullptr,				nullptr,				nullptr };
	void(Part::*orientation_17[4])() = { &Part::rotYfaceM90,	&Part::rotXfaceP90,		nullptr,				nullptr };
	void(Part::*orientation_18[4])() = { &Part::rotYfaceM90,	&Part::rotXfaceP90,		&Part::rotXfaceP90,		nullptr };
	void(Part::*orientation_19[4])() = { &Part::rotYfaceM90,	&Part::rotXfaceM90,		nullptr,				nullptr };

	void(Part::*orientation_20[4])() = { &Part::rotYfaceP90,	&Part::rotYfaceP90,		nullptr,				nullptr };
	void(Part::*orientation_21[4])() = { &Part::rotYfaceP90,	&Part::rotYfaceP90,		&Part::rotZfaceP90,		nullptr };
	void(Part::*orientation_22[4])() = { &Part::rotYfaceP90,	&Part::rotYfaceP90,		&Part::rotZfaceP90,		&Part::rotZfaceP90 };
	void(Part::*orientation_23[4])() = { &Part::rotYfaceP90,	&Part::rotYfaceP90,		&Part::rotZfaceM90,		nullptr };

	void(Part::**possibleOrientations[24])() = {
		orientation_0,
		orientation_1,
		orientation_2,
		orientation_3,
		orientation_4,
		orientation_5,
		orientation_6,
		orientation_7,
		orientation_8,
		orientation_9,
		orientation_10,
		orientation_11,
		orientation_12,
		orientation_13,
		orientation_14,
		orientation_15,
		orientation_16,
		orientation_17,
		orientation_18,
		orientation_19,
		orientation_20,
		orientation_21,
		orientation_22,
		orientation_23
	};

public:
	Part();

	int isTranslatableAlongX(int steps = 1) const;
	int isTranslatableAlongY(int steps = 1) const;

	void translateAlongX(int steps);
	void translateAlongY(int steps);

	void applyRotation(int orientationIndex);

	void rotXfaceP90();
	void rotXfaceM90();

	void rotYfaceP90();
	void rotYfaceM90();

	void rotZfaceP90();
	void rotZfaceM90();
};

