#include <iostream>
using namespace std;
struct SNode
{
	int data;
	SNode* next;
};
struct SList
{
	SNode* head;
};
SNode* createNode(int data)
{
	SNode* temp = new SNode;
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void createList(SList& l)
{
	l.head = NULL;
}
SNode* reverseBetween(SNode* head, int left, int right)
{
    if (head == NULL || head->next == NULL) return head;
    SNode* dummy = new SNode;
    dummy->next = head;
    SNode* pre = dummy;
    for (int i = 1; i < left; i++)
    {
        pre = pre->next;
    }
    SNode* cur = pre->next;
    for (int i = 0; i < right - left; i++)
    {
        SNode* next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummy->next;
}