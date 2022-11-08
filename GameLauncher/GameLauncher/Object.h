#pragma once
#include <string>

class Object
{
#pragma region constructor/destructor
public:
	Object() = default;
	Object(const Object& _copy) = default;
	virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	virtual std::string ToString() const;
#pragma endregion methods
};

