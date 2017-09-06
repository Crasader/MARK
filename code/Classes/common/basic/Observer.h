#ifndef __COMMON_OBSERVER_OBSERVER_H__
#define __COMMON_OBSERVER_OBSERVER_H__

#include <map>

using namespace std;

class Observer
{
public:
	~Observer();
	int idObserverGet() const { return _idObserver; }
	void idObserverSet(int val) { _idObserver = val; }
	virtual void updateBySubject(va_list values);

protected:
	Observer();

private:
	int _idObserver;
	
};

class Subject
{
public:
	~Subject();
	virtual void attach(Observer *observer);
	virtual void detach(Observer *observer);
	virtual void notify(int idObserver, ...);

protected:
	Subject();
	
private:
	map<int, Observer *> _map;

};

#endif