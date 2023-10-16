#include "ATarget.hpp"

ATarget::ATarget(str a): _a(a)
{ }

ATarget::~ATarget(void)
{ }

str ATarget::getType(void) const
{
	return (this->_a);
}

void	ATarget::getHitBySpell(ASpell const &r) const
{
	std::cout << this->getType() << " has been " << r.getEffects() << "!" << std::endl;
}
