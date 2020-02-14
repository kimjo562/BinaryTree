#include "Node.h"
#pragma once

template <typename T>

class Iterator
{
public:

	Iterator operator++();
	Iterator operator--();

	T operator*();

 	Iterator();
	Iterator(Node<T>* ptr);

	bool operator == (const Iterator<T>&)const;
	bool operator != (const Iterator<T>&)const;

private:

	Node* currentNode;

};

template<typename T>
Iterator<T> Iterator<T>::operator++()
{
	return Iterator();
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	return Iterator();
}

template<typename T>
T Iterator<T>::operator*()
{
	return T();
}

template<typename T>
Iterator<T>::Iterator()
{

}

template<typename T>
Iterator<T>::Iterator(Node<T> * ptr)
{
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>&) const
{
	return false;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>&) const
{
	return false;
}
