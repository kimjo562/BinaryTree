#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class List {
protected:
	int mCount;

	Node<T>* m_last;
	Node<T>* m_first;

public:
	void initializeList();
	bool isListEmpty();
	int Length();

	T front();
	T back();

	virtual bool search(const T&) = 0;
	virtual void insertFirst(const T&) = 0;
	virtual void insertLast(const T&) = 0;
	virtual void deleteNode(const T&) = 0;

	Iterator<T> begin();
	Iterator<T> end();

	List();
	~List();

private:
	void copyList(List<T>&);
};

template<typename T>
void List<T>::initializeList()
{
	m_first = nullptr;
	m_last = nullptr;
	mCount = 0;
}

template<typename T>
bool List<T>::isListEmpty()
{
	if (m_first == nullptr) return true;
	else return false;
}

template<typename T>
int List<T>::Length()
{
	return mCount;
}

template<typename T>
T List<T>::front()
{
	return m_first->info;
}

template<typename T>
T List<T>::back()
{
	return m_last->info;
}

template<typename T>
Iterator<T> List<T>::begin()
{
	return Iterator<T>(m_first);;
}

template<typename T>
Iterator<T> List<T>::end()
{
	return Iterator<T>(m_last);
}

template<typename T>
List<T>::List()
{
	initializeList();
}

template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::copyList(List<T>& listToCopy)
{
	this->m_first = &(*listToCopy->m_first);
	this->m_last = &(*listToCopy->m_last);
	mCount = listToCopy.Length();
	delete listToCopy;
}
