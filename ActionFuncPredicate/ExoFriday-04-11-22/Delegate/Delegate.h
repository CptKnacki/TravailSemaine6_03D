#pragma once
#include "../Object/Object.h"
#include <string>



template<typename Res, typename... Args>
class Delegate : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	Function function = nullptr;
public:
	Delegate() = default;
	Delegate(nullptr_t);
	template<typename Class>
	Delegate(Res(Class::* ptr)(Args...));
	~Delegate() override;
public:
	Res Invoke(object _instance, Args... _args);
	void* GetAddress();
public:
	void operator=(nullptr_t);	
	template<typename Class>
	void operator=(Res(Class::* ptr)(Args...));

};

template<typename Res, typename ...Args>
inline Delegate<Res, Args...>::Delegate(nullptr_t)
{
	function = nullptr;
}

template<typename Res, typename ...Args>
template<typename Class>
inline Delegate<Res, Args...>::Delegate(Res(Class::* ptr)(Args...))
{
	function = reinterpret_cast<Function>(ptr);
}

template<typename Res, typename ...Args>
inline Delegate<Res, Args...>::~Delegate()
{
	function = nullptr;
}

template<typename Res, typename ...Args>
inline Res Delegate<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	return (_instance->*function)(_args...);
}

template<typename Res, typename ...Args>
inline void* Delegate<Res, Args...>::GetAddress()
{
	return (void*&)function;
}

template<typename Res, typename ...Args>
inline void Delegate<Res, Args...>::operator=(nullptr_t)
{
	function = nullptr;
}

template<typename Res, typename ...Args>
template<typename Class>
inline void Delegate<Res, Args...>::operator=(Res(Class::* ptr)(Args...))
{
	function = reinterpret_cast<Function>(ptr);
}
