// Iterators provide a way to access the elements of a collection without exposing its underlying representation.
#pragma once
#include "Node.h"

template<typename T>
class Iterator {
private:
	Node<T>* currentNode;

public:
	Iterator<T> operator++(int);
	Iterator<T> operator--(int);

	T operator*();

	Iterator();
	~Iterator();
	Iterator(Node<T>* ptr);

	bool operator==(const Iterator<T>&)const;
	bool operator!=(const Iterator<T>&)const;
};

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	if (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		return *this;
	}
	return nullptr;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	if (currentNode->previous != nullptr)
	{
		currentNode = currentNode->previous;
		return *this;
	}
	return nullptr;
}

template<typename T>
T Iterator<T>::operator*()
{
	return currentNode->info;
}

template<typename T>
Iterator<T>::Iterator()
{
	currentNode = nullptr;
}

template<typename T>
inline Iterator<T>::~Iterator()
{

}

template<typename T>
Iterator<T>::Iterator(Node<T>* ptr)
{
	currentNode = ptr;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& currentIterator) const
{
	if (currentNode != nullptr && currentIterator.currentNode != nullptr && &currentNode->info == &currentIterator.currentNode->info) return true;
	else return false;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& currentIterator) const
{
	if (currentNode != nullptr && currentIterator.currentNode != nullptr && &currentNode->info != &currentIterator.currentNode->info) return true;
	else return false;
}
