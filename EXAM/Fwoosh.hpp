#pragma once

#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	private:

	public:
		Fwoosh();
		~Fwoosh(void);

		ASpell *clone(void) const;
};
