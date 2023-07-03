/*#BEGIN#_________________________>#_|INFO|_#<______________________________##*/
/*#                                                        ______ _         ##*/
/*# DETAILS:                                               | ___ (_)        ##*/
/*#- FILENAME		Serializer.cpp                               | |_/ /___  __   ##*/
/*#- PROJECT_NAME	None                                   |  __/| \ \/ /   ##*/
/*#- AUTHOR			Pixailz                                | |   | |>  <    ##*/
/*#- CREATED		2023−01−29T23:02:00+0100               \_|   |_/_/\_\   ##*/
/*#                                                                         ##*/
/*# DESCRIPTION:                                                            ##*/
/*## None                                                                   ##*/
/*#                                                                         ##*/
/*# VERSION:[ALPHA|BETA]_MAJOR.MINOR.PATCH                                  ##*/
/*#END#___________________________<#_|INFO|_#>______________________________##*/

# include <Serializer.hpp>
/**
 * <object>		object
 * <function>	function()
 */

// Constructor (void)
Serializer::Serializer(void)
{
	debug("Serializer class created");
}

// Destructor
Serializer::~Serializer(void)
{
	debug("Serializer class destructed");
}

// Copy Constructor
Serializer::Serializer(const Serializer &copy)
{
	debug("Serializer class created (by copy)");
	*this = copy;
}

// '=' operator
Serializer	&Serializer::operator=(const Serializer &src)
{
	(void)src;
	debug("Serializer operator '=' called");
	return (*this);
}

// Other

uintptr_t	Serializer::serialize(Data* to_serialize)
{
	return (reinterpret_cast<uintptr_t>(to_serialize));
}

Data	*Serializer::deserialize(uintptr_t to_deserialize)
{
	return (reinterpret_cast<Data *>(to_deserialize));
}
