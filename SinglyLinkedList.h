#pragma once
#include "Node.h"
#include<iostream>
using namespace std;

template<class T>
class SinglyLinkedList
{
	private:

        Node<T> *Head;
        Node<T> *Tail;
        int Size;
        void DeleteAllNodes();

	public:

        //Basic Functions
        SinglyLinkedList();
        SinglyLinkedList(T Data);
        SinglyLinkedList(const SinglyLinkedList<T> &RHS);
        SinglyLinkedList& operator =(const SinglyLinkedList<T> &RHS);
        ~SinglyLinkedList();

        //Special Functions
        Node<T>* GetHead();
        Node<T>* GetTail();
        int GetSize();
        void DeepCopy(const SinglyLinkedList<T> &RHS);
        void InsertAtStart(T Data);
        void InsertAtEnd(T Data);
        void InsertAtPosition(T Data,int Index);
        void DeleteAtFirst();
        void DeleteAtLast();
        void DeleteAtPosition(int Index);
        void ReverseList();
        void ReverseData();
        void ReverseDataSTL();
        void ReverseList(Node<T> *N);
        void PrintListReverse(Node<T> *N);
        void PrintListForward(Node<T> *N);
        void ViewList();
        int DataFrequency(T Data);
        void GetNth(int Index);
        void FindData(T Data);
        void PrintMiddleValue();
        void SortList();
        void RemoveDuplicates();
        void DeleteData(T Data);
        void DeleteMiddleValue();
        void InsertAtMiddle(T Data);
        void IdenticalLinkedList(const SinglyLinkedList<T> &RHS);
};
