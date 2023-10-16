#include "SpellBook.hpp"

SpellBook::SpellBook()
{ }

SpellBook::~SpellBook(void)
{
	for (spell_it it = this->_s.begin(); it != this->_s.end(); it++)
		delete it->second;
}

void	SpellBook::learnSpell(ASpell *r)
{
	if (r)
		this->_s[r->getName()] = r->clone();
}

void	SpellBook::forgetSpell(std::string n)
{
	spell_it it = this->_s.find(n);
	if (it != this->_s.end())
		delete it->second;
	this->_s.erase(n);
}

ASpell *SpellBook::createSpell(std::string n)
{
	spell_it it = this->_s.find(n);
	if (it != this->_s.end())
		return (this->_s[n]);
	return (NULL);
}

