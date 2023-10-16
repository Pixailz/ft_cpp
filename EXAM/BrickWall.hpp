#pragma once

#include "ATarget.hpp"

class BrickWall: public ATarget
{
	private:

	public:
		BrickWall();
		~BrickWall(void);

		virtual ATarget *clone(void) const;
};
