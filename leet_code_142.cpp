#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *haveCycle(ListNode *head) {
        ListNode *p1=head, *p2=head;
        while (p1 && p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1==p2)
                return p1;
        }
        return nullptr;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *p1=head, *p2;
        if ((p2=haveCycle(head)) == NULL)
            return nullptr;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1; 
    }
};

int main() {
	ListNode *l = NULL;
	Solution s;
	cout << s.detectCycle(l) ? "Yes" : "No";
}