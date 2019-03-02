#include "Node.h"

#include<iostream>
using namespace std;

template<class T>
Node<T>::Node()
{
    Data=0;
    Next=0;
}

template<class T>
Node<T>::Node(T Data)
{
    this->Data=Data;
    Next=0;
}

template<class T>
Node<T>::Node(const Node<T> &RHS)
{
    this->Data=RHS.Data;
    this->Next=new Node<T>;
    this->Next=RHS.Next;
}

template<class T>
Node<T>::Node(T Data,Node<T> *Next)
{
    this->Data=Data;
    this->Next=new Node<T>;
    this->Next=Next;
}

template<class T>
Node<T>& Node<T>::operator =(const Node<T> &RHS)
{
    if(this!=&RHS)
    {
        delete this->Next;
        this->Next=new Node<T>;
        this->Next=RHS.Next;
        this->Data=RHS.Data;
    }
    return (*this);
}

template<class T>
void Node<T>::SetData(T Data)
{
    this->Data=Data;
}

template<class T>
void Node<T>::SetNext(Node<T> *Next)
{
    this->Next=Next;
}

template<class T>
Node<T>* Node<T>::GetNode()
{
    return (*this);
}

template<class T>
T Node<T>::GetData()
{
    return Data;
}

template<class T>
Node<T>* Node<T>::GetNext()
{
    return Next;
}

template<class T>
Node<T>::~Node()
{
    if(Next!=0)
    {
        delete Next;
    }
    Next=0;
}

