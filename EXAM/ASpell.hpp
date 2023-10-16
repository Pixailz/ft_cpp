#pragma once

#include <iostream>

typedef const std::string & str;

class ATarget;

class ASpell
{
	private:
		std::string	_n;
		std::string _e;

	public:
		ASpell(str n, str e);
		virtual ~ASpell(void);

		str getName(void) const;
		str getEffects(void) const;

		virtual ASpell *clone(void) const = 0;
		void    launch(ATarget const &r) const;
};

#include "ATarget.hpp"
