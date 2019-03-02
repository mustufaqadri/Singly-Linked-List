#include "SinglyLinkedList.h"

#include<iostream>
#include <algorithm>
#include <iterator>
using namespace std;

template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    Head=Tail=0;
    Size=0;
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(T Data)
{
    Node<T> *NewNode=new Node<T>(Data);
    NewNode->SetNext(0);
    Head=NewNode;
    Tail=NewNode;
    Head->SetNext(Tail);
    Tail->SetNext(0);
    Size=1;
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &RHS)
{
    Head=0;
    Tail=0;
    DeepCopy(RHS);
}

template<class T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator = (const SinglyLinkedList<T> &RHS)
{
    if(this!=&RHS)
    {
        if(Head!=NULL)
        {
            DeleteAllNodes();
            delete Head;
        }
        if(Tail!=NULL)
        {
            delete Tail;
        }
        Head=Tail=0;
        DeepCopy(RHS);
    }
    else
    {
        return (*this);
    }
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    if(Head!=NULL)
    {
        DeleteAllNodes();
        delete Head;
    }
    if(Tail!=NULL)
    {
        delete Tail;
    }
    Head=Tail=0;
    Size=0;
}

//Special Functions

template<class T>
Node<T>* SinglyLinkedList<T>::GetHead()
{
    return Head;
}

template<class T>
Node<T>* SinglyLinkedList<T>::GetTail()
{
    return Tail;
}

template<class T>
int SinglyLinkedList<T>::GetSize()
{
    return Size;
}

template <class T>
void SinglyLinkedList<T>::DeepCopy(const SinglyLinkedList<T> &RHS)
{
    Node<T>* Temp=RHS.Head;
    Node<T>* Pre=RHS.Head;
    while(Temp!=0)
    {
        Node<T> *NewNode=new Node<T>(Temp->GetData());
        if(Head==0)
        {
            Head=NewNode;
            Tail=NewNode;
            Head->SetNext(Tail);
            Pre=NewNode;
        }
        else
        {
            Pre->SetNext(NewNode);
            Pre=NewNode;
            Tail=NewNode;
            Tail->SetNext(0);
        }
        Size++;
        Temp=Temp->GetNext();
    }
}

template<class T>
void SinglyLinkedList<T>::InsertAtStart(T Data)
{
    Node<T> *NewNode=new Node<T>(Data);
    if(Head==0)
    {
        Head=NewNode;
        Tail=NewNode;
        Head->SetNext(Tail);
        Tail->SetNext(0);
    }
    else
    {
        NewNode->SetNext(Head);
        Head=NewNode;
        Node<T> *Temp=Head;
    }
    Size++;
}

template<class T>
void SinglyLinkedList<T>::InsertAtEnd(T Data)
{
    Node<T> *NewNode=new Node<T>(Data);
    if(Head==0)
    {
        Head=NewNode;
        Tail=NewNode;
        Head->SetNext(Tail);
        Tail->SetNext(0);
    }
    else
    {
        Tail->SetNext(NewNode);
        Tail=NewNode;
    }
    Size++;
}

template<class T>
void SinglyLinkedList<T>::InsertAtPosition(T Data,int Index)
{
    Node<T> *NewNode=new Node<T>(Data);
    if(Index==1)
    {
        InsertAtStart(Data);
    }
    else if(Index>0 && Index <=Size+1)
    {
        Node<T> *Pre=0;
        Node<T> *Cur=0;
        Cur=Head;
        for(int i=1;i<Index;i++)
        {
            Pre=Cur;
            Cur=Cur->GetNext();
        }
        Pre->SetNext(NewNode);
        NewNode->SetNext(Cur);
        Size++;
    }
    else
    {
        cout<<"\nIndex out of bound...\n";
    }
}

template<class T>
void SinglyLinkedList<T>::DeleteAtFirst()
{
    if(Head==0)
    {
        cout<<"\nList is empty...\n";
    }
    else
    {
        Node<T> *Temp;
        Temp=Head;
        Head=Head->GetNext();
        Temp=0;
        Size--;
    }
}

template<class T>
void SinglyLinkedList<T>::DeleteAtLast()
{
    if(Head==0)
    {
        cout<<"\nList is empty...\n";
    }
    else
    {
        Node<T> *Cur=Head;
        Node<T> *Pre=0;
        Pre=Head;
        while(Cur->GetNext()!=0)
        {
            Pre=Cur;
            Cur=Cur->GetNext();
        }
        Tail=Pre;
        Pre->SetNext(0);
        delete Cur;
        Cur=0;
        Size--;
    }
}

template<class T>
void SinglyLinkedList<T>::DeleteAtPosition(int Index)
{
    if(Head==0)
    {
        cout<<"\nList is empty...\n";
    }
    else if(Index==1 && Head!=0)
    {
        DeleteAtFirst();
    }
    else if(Index==Size)
    {
        DeleteAtLast();
    }
    else if(Index>1 && Index<Size)
    {
        Node<T>* Cur=Head;
        Node<T>* Pre=0;
        for(int i=1;i<Index;i++)
        {
            Pre=Cur;
            Cur=Cur->GetNext();
        }
        Pre->SetNext(Cur->GetNext());
        Cur=0;
        Size--;
    }
    else
    {
        cout<<"\nIndex is out of bound...\n";
    }

}

template<class T>
void SinglyLinkedList<T>::ReverseList()
{
    Node<T>* Cur=Head;
    Node<T>* Pre=0;
    Node<T>* Next=0;
    while(Cur!=0)
    {
        Next=Cur->GetNext();
        Cur->SetNext(Pre);
        Pre=Cur;
        Cur=Next;
    }
    Head=Pre;
}

template<class T>
void SinglyLinkedList<T>::ReverseData()
{
    T Array[Size];
    T Holder;
    Node<T> *Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Array[i]=Temp->GetData();
        Temp=Temp->GetNext();
    }
    for(int i=0,j=Size-1;i<Size/2;i++,j--)
    {
        Holder=Array[i];
        Array[i]=Array[j];
        Array[j]=Holder;
    }
    Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Temp->SetData(Array[i]);
        Temp=Temp->GetNext();
    }
}

template<class T>
void SinglyLinkedList<T>::ReverseDataSTL()
{
    Node<T> *Temp=Head;
    vector<T> V;
    for(int i=0;i<Size;i++)
    {
        V.push_back(Temp->GetData());
        Temp=Temp->GetNext();
    }
    reverse(V.begin(),V.end());
    Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Temp->SetData(V.at(i));
        Temp=Temp->GetNext();
    }
}

template<class T>
void SinglyLinkedList<T>::ReverseList(Node<T> *N)
{
    if(N->GetNext()==0)
    {
        Head=N;
        return;
    }
    ReverseList(N->GetNext());
    Node<T> *Temp=N->GetNext();
    Temp->SetNext(N);
    N->SetNext(0);
}

template<class T>
void SinglyLinkedList<T>::PrintListReverse(Node<T> *N)
{
    if(N==0)
    {
        return;
    }
    else
    {
        PrintListReverse(N->GetNext());
        T Info=N->GetData();
        cout<<Info<<endl;
    }
}

template<class T>
void SinglyLinkedList<T>::PrintListForward(Node<T> *N)
{
    if(N!=0)
    {
        T Info=N->GetData();
        cout<<Info<<endl;
        PrintListForward(N->GetNext());
    }
}

template<class T>
void SinglyLinkedList<T>::DeleteAllNodes()
{
    if(Head!=0)
    {
        cout<<"\n\nDESTROYING NODES...\n";
        Node<T> *Current=Head;
        Node<T> *Pre;
        while(Current!=0)
        {
            Pre=Current;
            cout<<"\nDeleting "<<Pre->GetData();
            Current=Current->GetNext();
            Pre=0;
            delete Pre;
        }
    }
    Size=0;
    cout<<"\n\nALL NODES DESTROYED SUCCESSFULLY...\n";
}
template<class T>
void SinglyLinkedList<T>::ViewList()
{
    Node<T> *Temp;
    if(Head==NULL)
    {
        cout<<"\nList is Empty..."<<endl;
    }
    else
    {
        Temp=Head;
        cout<<"\n\n     LIST \n\n";
        int i=1;
        while(Temp!=NULL)
        {
            cout<<"--- Node "<<i<<" ---\n";
            cout<<"   "<<Temp<<"\n";
            cout<<"      "<<Temp->GetData()<<"\n";
            if(Temp->GetNext()==0)
            {
                cout<<"      0\n";
                cout<<"--------------\n";
            }
            else
            {
                cout<<"   "<<Temp->GetNext()<<"\n";
                cout<<"--------------\n";
            }
            i++;
            Temp=Temp->GetNext();
            cout<<endl;
        }
    }
}
template<class T>
int SinglyLinkedList<T>::DataFrequency(T Data)
{
    if(Head==NULL)
    {
        cout<<"\nList is Empty..."<<endl;
    }
    else
    {
        Node<T> *Temp=Head;
        int Count=0;
        Temp=Head;
        while(Temp!=NULL)
        {
            if(Temp->GetData()==Data)
            {
                Count++;
            }
            Temp=Temp->GetNext();
        }
            return Count;
    }
}

template<class T>
void SinglyLinkedList<T>::GetNth(int Index)
{
	Node<T> *Temp=Head;
	if(Temp==NULL)
	{
		cout<<"\nList is Empty..."<<endl;
	}
	else if(Index>0 && Index<=Size)
	{
		for(int i=1;i<Index;i++)
		{
			Temp=Temp->GetNext();
		}
		cout<<"\n\nData at index "<<Index<<" : "<<Temp->GetData();
	}
	else
    {
        cout<<"\n\nIndex is out of bound...\n\n";
    }

}

template<class T>
void SinglyLinkedList<T>::FindData(T Data)
{
    Node<T> *Temp=Head;
    int i=1;
    int flag=0;
    while(Temp!=0)
    {
        if(Data==Temp->GetData())
        {
            cout<<"\n\nData found at index "<<i<<endl<<endl;
            flag=1;
        }
        i++;
        Temp=Temp->GetNext();
    }
    if(flag==0)
    {
        cout<<"\n\nData not found...\n\n";
    }
}

template<class T>
void SinglyLinkedList<T>::PrintMiddleValue()
{
    int Mid=Size/2;
    int i=1;
    Node<T> *Temp=Head;
    for(i=1;i<Mid+1;i++)
    {
        Temp=Temp->GetNext();
    }
    cout<<"\n\nMiddle value at index "<<i<<" is "<<Temp->GetData();
}

template<class T>
void SinglyLinkedList<T>::SortList()
{
    T Array[Size];
    Node<T>* Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Array[i]=Temp->GetData();
        Temp=Temp->GetNext();
    }
    sort(Array,Array+Size);
    Temp=Head;
    for(int i=0;i<Size;i++)
    {
        Temp->SetData(Array[i]);
        Temp=Temp->GetNext();
    }

}

template<class T>
void SinglyLinkedList<T>::RemoveDuplicates()
{
    Node<T> *Ptr1=Head,*Ptr2,*Temp;
    while(Ptr1!=0)
    {
        Ptr2=Ptr1;
        while(Ptr2->GetNext()!=0)
        {
            if (Ptr1->GetData() == Ptr2->GetNext()->GetData())
            {
                Temp=Ptr2->GetNext();
                Ptr2->SetNext(Temp->GetNext());
                delete Temp;
                Temp=0;
                Size--;
            }
            else
            {
                Ptr2=Ptr2->GetNext();
            }
        }
        Ptr1=Ptr1->GetNext();
    }
}

template<class T>
void SinglyLinkedList<T>::DeleteData(T Data)
{
    Node<T> *Cur=Head;
    Node<T> *Pre=0;
    int flag=0;
    int Index=1;
    while(Cur!=0)
    {
        if(Cur->GetData()==Data)
        {
            flag=1;
            break;
        }
        Cur=Cur->GetNext();
        Index++;
    }
    if(flag==0)
    {
        cout<<"\n\nData not found...\n\n";
    }
    else
    {
        DeleteAtPosition(Index);
        cout<<"\n\nData deleted successfully...\n\n";
    }
}

template<class T>
void SinglyLinkedList<T>::DeleteMiddleValue()
{
    if(Head==0)
    {
        cout<<"\n\nList is empty...\n\n";
    }
    else
    {
        Node<T> *Cur=Head;
        Node<T> *Pre;
        int Mid=Size/2;
        for(int i=1;i<Mid+1;i++)
        {
            Pre=Cur;
            Cur=Cur->GetNext();
        }
        Pre->SetNext(Cur->GetNext());
        Cur=0;
        cout<<"\n\nMiddle value deleted successfully...\n\n";
        Size--;
    }
}

template<class T>
void SinglyLinkedList<T>::InsertAtMiddle(T Data)
{
    if(Head==0)
    {
        cout<<"\n\nList is empty...\n\n";
    }
    else
    {
        Node<T> *NewNode=new Node<T>(Data);
        Node<T> *Cur=Head;
        Node<T> *Pre;
        int Mid=Size/2;
        for(int i=1;i<Mid+1;i++)
        {
            Pre=Cur;
            Cur=Cur->GetNext();
        }
        NewNode->SetNext(Pre->GetNext());
        Pre->SetNext(NewNode);
        cout<<"\n\nInserted at middle successfully...\n\n";
        Size++;
    }
}

template<class T>
void SinglyLinkedList<T>::IdenticalLinkedList(const SinglyLinkedList<T> &RHS)
{
    Node<T> *List1=Head;
    Node<T> *List2=RHS.Head;
    int flag=0;
    while (List1!=0 && List2!=0)
    {
        if(List1->GetData() != List2->GetData())
        {
            cout<<"\n\nList are not identical...\n\n";
            flag=1;
            break;
        }
        List1=List1->GetNext();
        List2=List2->GetNext();
    }
    if(flag==0)
    {
        cout<<"\n\nList are identical...\n\n";
    }
}
