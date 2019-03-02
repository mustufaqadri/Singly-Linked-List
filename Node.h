#pragma once
#include<iostream>
using namespace std;
template<class T>
class Node
{
	private:

        T Data;
        Node<T> *Next;

	public:

	    //Basic Functions
	    Node();
	    Node(T Data);
	    Node(const Node<T> &RHS);
	    Node<T>& operator =(const Node<T> &RHS);
	    Node(T Data,Node<T> *Next);
        ~Node();

	    //Special Functions
        void SetData(T Data);
        void SetNext(Node<T> *Next);
        Node<T>* GetNode();
        T GetData();
        Node* GetNext();

};
