#include "ASpell.hpp"

ASpell::ASpell(str n, str e): _n(n), _e(e)
{ }

ASpell::~ASpell(void)
{ }

str ASpell::getName(void) const
{
	return (this->_n);
}

str ASpell::getEffects(void) const
{
	return (this->_e);
}

void	ASpell::launch(ATarget const &r) const
{
	r.getHitBySpell((*this));
}
