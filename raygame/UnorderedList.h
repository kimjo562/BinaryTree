#include "List.h"
#pragma once

// typename = "could be" int, string, char ect. ect. of T
template<typename T>

class UnorderedList : List<T>
{

public:
	void insertFirst(const T&);
	void insertLast(const T&);

};

template<typename T>
void UnorderedList<T>::insertFirst(const T & tempInfo)
{
	Node<T>* newNode = new Node<T>;
	newNode->info = tempInfo;

	if (this->isEmptyList())
	{
		this->m_first = newNode;
		this->m_last = newNode;
		this->mCount++;

		return;
	}

	newNode->next = this->m_first;
	this->m_first = newNode;
	this->mCount++;
}

template<typename T>
void UnorderedList<T>::insertLast(const T & tempInfo)
{
	Node<T>* newNode = new Node<T>;
	newNode->info = tempInfo;

	if (this->m_last == nullptr)
	{
		this->m_last = newNode;
		this->m_first = newNode;
		this->mCount++;

		return;
	}

	newNode->next = this->m_last;
	this->m_last = newNode;
	this->mCount++;

}
