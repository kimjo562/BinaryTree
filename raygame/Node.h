#pragma once

// typename = "could be" int, string, char ect. ect. of T
template<typename T>

class Node
{

public:
	T info;
	Node<T>* nextNode;
	Node<T>* previousNode;

protected:

private:
};