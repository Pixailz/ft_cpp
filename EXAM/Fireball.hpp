#pragma once

#include "ASpell.hpp"

class Fireball: public ASpell
{
	private:

	public:
		Fireball();
		~Fireball(void);

		ASpell *clone(void) const;
};
