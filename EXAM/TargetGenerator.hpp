#pragma once

#include "ATarget.hpp"

#include <map>

typedef std::map<std::string, ATarget *> target;
typedef target::iterator target_it;
//typedef const std::string  & str;

class TargetGenerator
{
	private:
		target		_t;

	public:
		TargetGenerator(void);
		~TargetGenerator(void);

		void learnTargetType(ATarget* t);
		void forgetTargetType(str t);
		ATarget* createTarget(str t);
};
