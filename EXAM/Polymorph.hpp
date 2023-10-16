#pragma once

#include "ASpell.hpp"

class Polymorph: public ASpell
{
	private:

	public:
		Polymorph();
		~Polymorph(void);

		ASpell *clone(void) const;
};
