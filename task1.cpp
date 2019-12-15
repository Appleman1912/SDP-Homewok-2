using namespace std;
#include <iostream>

struct ListNode
{
	int data;
	ListNode* next;

	ListNode(int data)
	{
		this->data = data;
		this->next = nullptr;
	}


};



bool containsCycle(ListNode* start)
{
	ListNode* PtrBy1 = start->next;
	if (PtrBy1 == nullptr)
	{
		return false;
	}
	if (start == PtrBy1)
	{
		return true;
	}


	ListNode* PtrBy2 = start->next->next;

	if (PtrBy2 == start || PtrBy2 == PtrBy1)
	{
		return true;
	}
	if (PtrBy2 == nullptr)
	{
		return false;
	}

	while (true) 
	{
		if (PtrBy1->next == nullptr || PtrBy1 == nullptr) 
		{
			return false;
		}

		if (PtrBy1 == PtrBy2)
		{
			return true;
		}
		PtrBy1 = PtrBy1->next;
		ListNode* ptrCpy = PtrBy2->next;
		if (ptrCpy == nullptr || ptrCpy->next == nullptr)
		{
			return false;
		}

		PtrBy2 = ptrCpy->next;
		if(PtrBy2 == nullptr || PtrBy2->next == nullptr) 
		{
			return false;
		}

	}
}



int main()
{
	ListNode* hasCycle = new ListNode(4);
	hasCycle->next = new ListNode(5);
	hasCycle->next->next = new ListNode(7);
	hasCycle->next->next->next = new ListNode(8);
	hasCycle->next->next->next->next = hasCycle;

	cout << containsCycle(hasCycle) << endl;

	ListNode* hasNoCycle = new ListNode(3);
	hasNoCycle->next = new ListNode(4);
	hasNoCycle->next->next = new ListNode(5);
	hasNoCycle->next->next->next = new ListNode(6);
	cout << containsCycle(hasNoCycle) << endl;
	return 0;
}