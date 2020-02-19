#include "List.h"
#pragma once

// typename = "could be" int, string, char ect. ect. of T
template<typename T>

class UnorderedList : List<T>
{

public:

	bool search(const T&);
	void insertFirst(const T&);
	void insertLast(const T&);
	void deleteNode(const T&);

};

template<typename T>
bool UnorderedList<T>::search(const T & searchNode)
{
	for (auto i = this->begin(); i != this->end(); i++)
	{
		if (*i == searchNode)
		{
			return true;
		}
	}

}

template<typename T>
void UnorderedList<T>::deleteNode(const T& infoToDelete)
{
	Node<T>* iter = &(*this->m_first);

	if (this->m_first->info == infoToDelete)
	{
		this->m_first = iter->nextNode;
		delete iter;
		this->mCount--;
		return;
	}
	if (this->m_last->info == infoToDelete)
	{
		iter = &(*this->m_last);
		this->m_last = iter->previousNode;
		delete iter;
		this->mCount--;
		return;
	}

	int spotInList = 1;
	for (auto i = this->begin(); i != this->end(); i++)
	{
		if (&(*i) == &infoToDelete && spotInList != 0 && spotInList != this->Length())
		{
			iter->nextNode->previousNode = iter->previousNode;
			iter->previousNode->nextNode = iter->nextNode;
			delete iter;
			this->mCount--;
			break;
		}
		else
		{
			spotInList++;
			iter = &(*iter->nextNode);
		}
	}
}

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

	newNode->nextNode = this->m_first;
	this->m_first->previousNode = newNode;
	this->m_first = newNode;
	newNode->previousNode = nullptr;
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

	this->m_last->nextNode = this->m_last;
	newNode->previousNode = this->m_last;
	this->m_last = newNode;
	newNode->nextNode = nullptr;
	this->mCount++;

}
