#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(void)
{
	std::cout << "\e[47mSerializer::\e[0m Default constructor called" << std::endl;  
}

Serializer::Serializer(const Serializer &source)
{
	(void)source;
	std::cout << "\e[47mSerializer::\e[0m Copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &source)
{
	(void)source;
	std::cout << "\e[47mSerializer::\e[0m Assignment operator used" << std::endl;
	  
	return (*this);
}

Serializer::~Serializer(void)
{
	std::cout << "\e[47mSerializer::\e[0m Destructor called" << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}