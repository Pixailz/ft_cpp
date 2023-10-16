#pragma once

#include <iostream>

typedef const std::string & str;

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:
		std::string	_n;
		std::string _t;
		SpellBook	_b;
	public:
		Warlock(str n, str t);
		~Warlock(void);

		void	setTitle(str);

		str getName(void) const;
		str getTitle(void) const;
		void	introduce(void) const;

		void	learnSpell(ASpell *r);
		void	forgetSpell(std::string n);
		void	launchSpell(std::string n, ATarget const &r);
};
