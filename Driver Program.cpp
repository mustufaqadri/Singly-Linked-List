#include "Node.cpp"
#include "SinglyLinkedList.cpp"

#define DataType int
#include<iostream>
using namespace std;

int Menu()
{
	cout<<"\n--- Singly Linked List ---\n\n";
	int Choice;
	cout<<"\n01)  Insert Node at first";
	cout<<"\n\n02)  Insert Node at end";
	cout<<"\n\n03)  Insert Node at particular position";
	cout<<"\n\n04)  Delete Node from start";
	cout<<"\n\n05)  Delete Node from last";
	cout<<"\n\n06)  Delete Node from particular position";
	cout<<"\n\n07)  Reverse List (with nodes)";
	cout<<"\n\n08)  Reverse Data (only data)";
	cout<<"\n\n09)  Reverse Data (only data STL)";
	cout<<"\n\n10)  Reverse List (recursive)";
	cout<<"\n\n11)  Print List Reverse";
	cout<<"\n\n12)  Print List Forward";
	cout<<"\n\n13)  Data Frequency";
    cout<<"\n\n14)  Get Nth Node Information";
    cout<<"\n\n15)  Find Information";
    cout<<"\n\n16)  Print Middle Node Information";
    cout<<"\n\n17)  Insert at Middle Node";
    cout<<"\n\n18)  Delete Middle Node";
    cout<<"\n\n19)  Delete Particular Information";
    cout<<"\n\n20)  Remove Duplicates";
    cout<<"\n\n21)  Sort List";
    cout<<"\n\n22)  Identical Lists";
    cout<<"\n\n23)  View List";
    cout<<"\n\n24)  Get List Size";
	cout<<"\n\n0)   To Exit";
	cout<<"\n\n\nEnter Choice : ";
	cin>>Choice;
	return Choice;
}

main()
{
	// Update Data Type in macro above as well...
	SinglyLinkedList<int> SLLOne;
	cout<<"\n--- Singly Linked List ---\n\n";
	cout<<endl<<endl;
	system("pause");
	while(1)
	{
		system("cls");
		switch(Menu())
		{
			case 1:
			{
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                SLLOne.InsertAtStart(Data);
                cout<<"\n\nData inserted successfully...\n\n";
				break;
			}
			case 2:
			{
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                SLLOne.InsertAtEnd(Data);
                cout<<"\n\nData inserted successfully...\n\n";
				break;
			}
			case 3:
			{
                int Pos=0;
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                cout<<"\n\nEnter Position : ";
                cin>>Pos;
                SLLOne.InsertAtPosition(Data,Pos);
                cout<<"\n\nData inserted successfully...\n\n";
				break;
			}
			case 4:
			{
                SLLOne.DeleteAtFirst();
                cout<<"\n\nData deleted successfully...\n\n";
				break;
			}
			case 5:
			{
                SLLOne.DeleteAtLast();
                cout<<"\n\nData deleted successfully...\n\n";
				break;
			}
			case 6:
			{
                int Pos=0;
                cout<<"\n\nEnter Position : ";
                cin>>Pos;
                SLLOne.DeleteAtPosition(Pos);
                cout<<"\n\nData inserted successfully...\n\n";
				break;
			}
			case 7:
			{
                SLLOne.ReverseList();
                cout<<"\n\nList is reversed successfully...\n\n";
				break;
			}
			case 8:
			{
                SLLOne.ReverseData();
                cout<<"\n\nData is reversed successfully...\n\n";
				break;
			}
			case 9:
			{
                SLLOne.ReverseDataSTL();
                cout<<"\n\nData is reversed successfully...\n\n";
				break;
			}
			case 10:
			{
                SLLOne.ReverseList(SLLOne.GetHead());
                cout<<"\n\nList is reversed successfully...\n\n";
				break;
			}
			case 11:
			{
                SLLOne.PrintListReverse(SLLOne.GetHead());
				break;
			}
			case 12:
			{
                SLLOne.PrintListForward(SLLOne.GetHead());
				break;
			}
			case 13:
			{
                DataType Data;
                cout<<"\n\nEnter value : ";
                cin>>Data;
                int Count=0;
                Count=SLLOne.DataFrequency(Data);
                cout<<"\n\nData Frequency : "<<Count<<"\n\n";
				break;
			}
			case 14:
			{
                DataType Data;
                cout<<"\n\nEnter Position : ";
                cin>>Data;
                int Count=0;
                Count=SLLOne.DataFrequency(Data);
				break;
			}
			case 15:
			{
                DataType Data;
                cout<<"\n\nEnter Value : ";
                cin>>Data;
                SLLOne.FindData(Data);
				break;
			}
			case 16:
			{
                SLLOne.PrintMiddleValue();
				break;
			}
			case 17:
			{
                DataType Data;
                cout<<"\n\nEnter Value : ";
                cin>>Data;
                SLLOne.InsertAtMiddle(Data);
				break;
			}
			case 18:
			{
                SLLOne.DeleteMiddleValue();
				break;
			}
			case 19:
			{
                DataType Data;
                cout<<"\n\nEnter Value : ";
                cin>>Data;
                SLLOne.DeleteData(Data);
				break;
			}
			case 20:
			{
                SLLOne.RemoveDuplicates();
                cout<<"\n\nDuplicates Removed successfully\n\n";
				break;
			}
			case 21:
			{
                SLLOne.SortList();
                cout<<"\n\nList Sorted successfully\n\n";
				break;
			}
			case 22:
			{
                //Create the other linked list first then check
                //SinglyLinkedList<int> SLLTwo;
                //SLLOne.IdenticalLinkedList(SLLTwo);
                cout<<"\n\nCreate other list first..."<<endl<<endl;
				break;
			}
			case 23:
			{
                SLLOne.ViewList();
				break;
			}
			case 24:
			{
                cout<<"\n\nList Size : "<<SLLOne.GetSize()<<endl<<endl;
				break;
			}
			case 0:
			{
				cout<<endl<<endl<<"*** GOOD BYE ***\n\n";
				exit(0);
				break;
			}
			default:
			{
				cout<<"\nInvalid Input\n";
			}
		}
		cout<<endl;
		system("pause");
	}
}
