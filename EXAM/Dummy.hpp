#pragma once

#include "ATarget.hpp"

class Dummy: public ATarget
{
	private:

	public:
		Dummy();
		~Dummy(void);

		virtual ATarget *clone(void) const;
};
