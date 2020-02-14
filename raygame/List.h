#pragma once
#include "Node.h"

// typename = "could be" int, string, char ect. ect. of T
template<typename T>

class List
{

public:
	T front();
	T back();
	virtual void insertFirst(const T&) = 0;
	virtual void insertLast(const T&) = 0;
	bool isEmptyList();

protected:
	int mCount;
	Node<T>* m_first;
	Node<T>* m_last;

private:

};

template<typename T>
T List<T>::front()
{
	return m_first;
}

template<typename T>
T List<T>::back()
{
	return m_last;
}


template<typename T>
bool List<T>::isEmptyList()
{
	if (m_first == nullptr) return true;
	else return false;
}
