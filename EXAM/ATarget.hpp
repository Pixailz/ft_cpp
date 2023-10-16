#pragma once

#include <iostream>

typedef const std::string & str;

class ASpell;

class ATarget
{
	private:
		std::string	_a;

	public:
		ATarget(str a);
		virtual ~ATarget(void);

		str getType(void) const;
		void	getHitBySpell(ASpell const &r) const;

		virtual ATarget *clone(void) const = 0;
};

#include "ASpell.hpp"
