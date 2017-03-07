#ifndef __STATE_CALLBACK_H__
#define __STATE_CALLBACK_H__

template <typename T>
class StateCallback
{
public:
	StateCallback(const T& val);
	~StateCallback();

public://StateWelcomeCallback
	const T& getState() const { return _state; }
	void setState(const T& val) { _state = val; }
	bool insertCallback(const T& state, const std::function<void()>& callback = nullptr, const std::function<bool(float)>& check = nullptr);
	bool eraseCallback(const T& state);
	bool doCallbackByCurrentState(float delta);
	void clearDic();
private:
	T _state;
	std::map<T, std::function<void()>> _dicStateCallback;
	std::map<T, std::function<bool(float)>> _dicStateCheck;

};


template <typename T>
StateCallback<T>::StateCallback(const T& val) :
	_state(val),
	_dicStateCallback(),
	_dicStateCheck()
{
	/*cocos2d::Map<int, double> dic;
	dic.at(0);
	dic.erase(0);*/
}

template <typename T>
StateCallback<T>::~StateCallback()
{
	clearDic();
}

template <typename T>
bool StateCallback<T>::insertCallback(const T& state, const std::function<void()>& callback /*= nullptr*/, const std::function<bool(float)>& check /*= nullptr*/)
{
	auto iter = _dicStateCallback.find(state);
	if (iter != _dicStateCallback.end())
	{
		return false;
	}
	_dicStateCallback.insert(std::make_pair(state, callback));

	_dicStateCheck.insert(std::make_pair(state, check));
	return true;
}
template <typename T>
bool StateCallback<T>::eraseCallback(const T& state)
{
	auto iterCallback = _dicStateCallback.find(state);
	if (iterCallback == _dicStateCallback.end())
	{
		return false;
	}
	_dicStateCallback.erase(iterCallback);

	auto iterCheck = _dicStateCheck.find(state);
	if (iterCheck == _dicStateCheck.end())
	{
		return false;
	}
	_dicStateCheck.erase(iterCheck);
	return true;

}

template <typename T>
bool StateCallback<T>::doCallbackByCurrentState(float delta)
{
	auto iterCallback = _dicStateCallback.find(_state);
	if (iterCallback == _dicStateCallback.end())//ÈôÎ´ÕÒµ½×´Ì¬
	{
		return false;
	}
	auto callback = iterCallback->second;
	if (callback == nullptr)//ÈôÎÞÐèÖ´ÐÐ²Ù×÷
	{
		return true;
	}

	auto iterCheck = _dicStateCheck.find(_state);
	if (iterCheck != _dicStateCheck.end() && iterCheck->second != nullptr)//ÈôÐèÒª×´Ì¬¼ì²é
	{
		auto check = iterCheck->second;
		auto result = check(delta);
		if (!result)//Èô¼ì²éÊ§°Ü
		{
			return false;
		}
	}

	callback();//Ö´ÐÐ×´Ì¬
	return true;
}

template <typename T>
void StateCallback<T>::clearDic()
{
	_dicStateCallback.clear();
	_dicStateCheck.clear();
}

#endif