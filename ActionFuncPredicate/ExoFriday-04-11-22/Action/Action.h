#pragma once
#include "../Delegate/Delegate.h"
#include <vector>

template<typename T>
struct IsVoid
{
	static bool constexpr Value = std::is_same<T, void>::value;
};

template<typename Res, typename... Args>
class Delegates_Internal : public Object
{
private:
	typedef Res(Object::* Function)(Args...);
	std::vector<Delegate<Res, Args...>> functions = std::vector<Delegate<Res, Args...>>();
public:
	Delegates_Internal() = default;
	Delegates_Internal(nullptr_t);
	template<typename Class>
	Delegates_Internal(Res(Class::* ptr)(Args...));
	~Delegates_Internal() override;
private:
	size_t FindIndex(const Delegate<Res, Args...>& _function);
public:
	Res Invoke(object _instance, Args... _args);
public:
	template<typename Class>
	void operator+=(Res(Class::* ptr)(Args...));
	template<typename Class>
	void operator-=(Res(Class::* ptr)(Args...));
	template<typename Class>
	void operator=(Res(Class::* ptr)(Args...));
	void operator=(nullptr_t);
};

template<typename Res, typename ...Args>
inline Delegates_Internal<Res, Args...>::Delegates_Internal(nullptr_t)
{
	functions.clear();
}

template<typename Res, typename ...Args>
inline Delegates_Internal<Res, Args...>::~Delegates_Internal()
{
	functions.clear();
}

template<typename Res, typename ...Args>
inline size_t Delegates_Internal<Res, Args...>::FindIndex(const Delegate<Res, Args...>& _function)
{
	for (size_t i = 0; i < functions.size(); i++)
	{
		if (functions[i].GetAddress() == _function.GetAddress())
			return i;
	}
	return -1;
}

template<typename Res, typename ...Args>
inline Res Delegates_Internal<Res, Args...>::Invoke(object _instance, Args ..._args)
{
	if (IsVoid<Res>::Value)
	{
		for (Delegate<Res, Args...> _function : functions)
		{
			_function.Invoke(_instance, _args...);
		}
		return Res();
	}
	else
	{
		Res _result = Res();
		for (Delegate<Res, Args...> _function : functions)
		{
			_result = _function.Invoke(_instance, _args...);
		}
		return _result;
	}

}

template<typename Res, typename ...Args>
inline void Delegates_Internal<Res, Args...>::operator=(nullptr_t)
{
	functions.clear();
}

template<typename Res, typename ...Args>
template<typename Class>
inline Delegates_Internal<Res, Args...>::Delegates_Internal(Res(Class::* ptr)(Args...))
{
	Delegate<Res, Args...> _function = ptr;
	functions.push_back(_function);
}

template<typename Res, typename ...Args>
template<typename Class>
inline void Delegates_Internal<Res, Args...>::operator+=(Res(Class::* ptr)(Args...))
{
	Delegate<Res, Args...> _function = ptr;
	functions.push_back(_function);
}

template<typename Res, typename ...Args>
template<typename Class>
inline void Delegates_Internal<Res, Args...>::operator-=(Res(Class::* ptr)(Args...))
{
	Delegate<Res, Args...> _function = ptr;
	const size_t _index = FindIndex(_function);
	if (_index == -1) return;
	functions.erase(functions.begin() + _index);
}

template<typename Res, typename ...Args>
template<typename Class>
inline void Delegates_Internal<Res, Args...>::operator=(Res(Class::* ptr)(Args...))
{
	functions.clear();
	Delegate<Res, Args...> _function = ptr;
	functions.push_back(_function);
}



template<typename... Args>
using Action = Delegates_Internal<void, Args...>;
template<typename T, typename... Args>
using Func = Delegates_Internal<T, Args...>;
template<typename... Args>
using Predicate = Delegates_Internal<bool, Args...>;
