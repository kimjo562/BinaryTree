// Iterators provide a way to access the elements of a collection without exposing its underlying representation.
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
	// Increment iterator position
	if (currentNode->nextNode != nullptr) currentNode = currentNode->nextNode;
	return this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--()
{
	// Decrease iterator position
	if (currentNode->previousNode != nullptr) currentNode = currentNode->previousNode;
	return this;
}

template<typename T>
T Iterator<T>::operator*()
{
	// Dereference iterator
	T = currentNode->info;
	return T();
}

template<typename T>
Iterator<T>::Iterator()
{
	currentNode = nullptr;
}

template<typename T>
Iterator<T>::Iterator(Node<T>* ptr)
{
	currentNode = ptr;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& currentIterator) const
{
	if (currentNode.info == currentIterator.currentNode->info)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& currentIterator) const
{
	if (currentNode.info != currentIterator)
	{
		return true;
	}
	else
	{
		return false;
	}

}
