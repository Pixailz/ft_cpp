#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{ }

TargetGenerator::~TargetGenerator(void)
{
	for (target_it it = this->_t.begin(); it != this->_t.end(); it++)
		delete it->second;
}

void TargetGenerator::learnTargetType(ATarget* t)
{
	if (t)
		this->_t[t->getType()] = t->clone();
}

void	TargetGenerator::forgetTargetType(str n)
{
	target_it it = this->_t.find(n);
	if (it != this->_t.end())
		delete it->second;
	this->_t.erase(n);
}

ATarget *TargetGenerator::createTarget(str n)
{
	target_it it = this->_t.find(n);
	if (it != this->_t.end())
		return (this->_t[n]);
	return (NULL);
}
