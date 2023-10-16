#pragma once

#include "ASpell.hpp"

#include <map>

typedef std::map<std::string, ASpell *> spell;
typedef spell::iterator spell_it;

class SpellBook
{
	private:
		spell		_s;

	public:
		SpellBook(void);
		~SpellBook(void);

		void	learnSpell(ASpell *r);
		void	forgetSpell(std::string n);
		ASpell	*createSpell(std::string n);
};
