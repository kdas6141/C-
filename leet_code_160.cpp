//Intersection of Two Linked Lists
#include <iostream>
#include <stack>
#include <limits>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Create a linked list of n nodes staring value v; then return head */
ListNode *createListNodes(int n, int v, ListNode *h) {
	ListNode *l = NULL;

	for(int i=0; i<n; i++) {
		if (h) {
			l->next = new ListNode(v+i);
			l = l->next;
		}
		else {
			l = new ListNode(v+i);
			h = l;
		}
	}
	l->next = NULL;

	return h;
}

/* Print Linked List */
void printListNodes(ListNode *head, int num) {

	cout << "List Node " << num << " :";
	for(ListNode *l=head; l; l=l->next) {
		cout<<" " << l->val;
	}
	cout << endl;
}

/* Delete Linked List */
void deleteListNodes(ListNode *head) {
	ListNode *l=head, *t;
	while (l) {
		t = l;
		l = l->next;
		delete t; 
	}
}

/* Find the intersection */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	    stack<ListNode *> st1;
        stack<ListNode *> st2;

        for(auto la=headA; la; la=la->next)
            st1.push(la);
        
        for(auto lb=headB; lb; lb=lb->next)
            st2.push(lb);

        ListNode *r = NULL;
        while (!st1.empty() && !st2.empty() && st1.top() == st2.top()) {
            r = st1.top();
    	    st1.pop();
    	    st2.pop();
        }

        return r;
}

/* Create Y shaped linked list */
void createYListNode(ListNode *h1, ListNode *h2) {
	int i, n = 0;
	ListNode *p=h1, *l = NULL;

	if (!h1 || !h2)
		return;

	for(l=h1, n=0, p; l; n++, p=l, l=l->next);

	for (l=h2, i=0; l && i<n; i++, l=l->next);

	p->next = l;
}

/* Seprate Y shaped linked list */
void seprateYListNode(ListNode *h, ListNode *m) {
	int i, n = 0;
	ListNode *p=h, *l = NULL;

	if (!h || !m)
		return;

	for(l=h; l!=m; p=l, l=l->next);

	p->next = NULL;
}

int main() {

	ListNode *h1 = createListNodes(5, 1, NULL);
	ListNode *h2 = createListNodes(15, 6, NULL);

	printListNodes(h1, 1);
	printListNodes(h2, 2);
	ListNode * m = getIntersectionNode(h1, h2);
	cout << "Without Y, Intersection Value: " << (m ? m->val : numeric_limits<int>::max()) << endl;
	createYListNode(h1, h2);
	m = getIntersectionNode(h1, h2);
	cout << "With Y, Intersection Value: " << (m ? m->val : numeric_limits<int>::max()) << endl;
	seprateYListNode(h1, m);
	deleteListNodes(h1);
	deleteListNodes(h2);
}