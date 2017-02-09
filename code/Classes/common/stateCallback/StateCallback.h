#ifndef __STATE_CALLBACK_H__
#define __STATE_CALLBACK_H__

template <typename T>
class StateCallback
{
public:
	StateCallback();
	~StateCallback();

public://StateWelcomeCallback
	const T& getState() const { return _state; }
	void setState(const T& val) { _state = val; }
	bool insertCallback(const T& state, const std::function<void(float)>& callback);
	bool eraseCallback(const T& state);
	bool doCallbackByCurrentState(float delta);
	void clearDic();
private:
	T _state;
	std::map<T, std::function<void(float)>> _dicStateCallback;

};

template <typename T>
StateCallback<T>::StateCallback() : 
	_state(),
	_dicStateCallback()
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
bool StateCallback<T>::insertCallback(const T& state, const std::function<void(float)>& callback)
{
	auto iter = _dicStateCallback.find(state);
	if (iter != _dicStateCallback.end())
	{
		return false;
	}
	_dicStateCallback.insert(std::make_pair(state, callback));
	return true;
}

template <typename T>
bool StateCallback<T>::eraseCallback(const T& state)
{
	auto iter = _dicStateCallback.find(state);
	if (iter == _dicStateCallback.end())
	{
		return false;
	}
	_dicStateCallback.erase(iter);
	return true;

}

template <typename T>
bool StateCallback<T>::doCallbackByCurrentState(float delta)
{
	auto iter = _dicStateCallback.find(_state);
	if (iter == _dicStateCallback.end())
	{
		return false;
	}
	auto callback = iter->second;
	if (callback == nullptr)//无需执行操作
	{
		return true;
	}
	callback(delta);
	return true;
}

template <typename T>
void StateCallback<T>::clearDic()
{
	_dicStateCallback.clear();
}

#endif