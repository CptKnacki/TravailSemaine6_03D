#include "Object.h"
#include <typeinfo>

#pragma region methods
std::string Object::ToString() const
{
	std::string _className = typeid(*this).name();
	return _className.substr(_className.find(' ') + 1);
}
#pragma endregion methods