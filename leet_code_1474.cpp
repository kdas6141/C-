// Delete N Nodes After M Nodes of a Linked List
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
 	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
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

	if (num==0)
		cout << "List Node: " << endl;
	else
		cout << "list Node " << num << " :" <<endl;

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

/* skip m nodes then delete n nodes */
ListNode* deleteNodes(ListNode* head, int m, int n) {
	ListNode *h = head, *l=head, *p=NULL, *p2=NULL;
    int i =0;
    while (l) {
        for(i=0; l && i<m; p=l, l=l->next, i++);
            
       	if (!l)
            return h;
            
        for(i=0, l = l->next; l && i<n-1; l=l->next, i++);

        p->next = l;
            
    }
    return h;
}

int main() {
	ListNode *h = createListNodes(15, 1, NULL);
	printListNodes(h, 0);
	deleteNodes(NULL, 2, 3);
	printListNodes(h, 0);
	deleteListNodes(h);
}