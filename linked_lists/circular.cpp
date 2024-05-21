#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* findCircularStart(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* slow = head->next;
    ListNode* fast = head->next->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    ListNode* node1 = new ListNode{1};
    ListNode* node2 = new ListNode{2};
    ListNode* node3 = new ListNode{3};
    ListNode* node4 = new ListNode{4};
    ListNode* node5 = new ListNode{5};
    ListNode* node6 = new ListNode{6};
    ListNode* node7 = new ListNode{7};
    ListNode* node8 = new ListNode{8};
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node4; /* Node 4 is start node */
    std::cout << "Testing...\n";
    std::cout << "Circular loop start node:\n";
    ListNode* startNode = findCircularStart(node1);
    std::cout << startNode->val << std::endl;
    assert(startNode->val == 4);
}
