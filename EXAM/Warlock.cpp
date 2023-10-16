#include "Warlock.hpp"

Warlock::Warlock(str n, str t): _n(n), _t(t)
{
	std::cout << n << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << this->getName() << ": My job here is done!" << std::endl;
}

void Warlock::setTitle(str t)
{
	this->_t = t;
}

str Warlock::getName(void) const
{
	return (this->_n);
}

str Warlock::getTitle(void) const
{
	return (this->_t);
}

void	Warlock::introduce(void) const
{
	str n = this->getName();
	std::cout << n << ": I am " << n << ", " << this->getTitle() << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *r)
{ this->_b.learnSpell(r); }

void	Warlock::forgetSpell(std::string n)
{ this->_b.forgetSpell(n); }

void	Warlock::launchSpell(std::string n, ATarget const &r)
{
	ASpell *t = this->_b.createSpell(n);
	if (t)
		t->launch(r);
}

