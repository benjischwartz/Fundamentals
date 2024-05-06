 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* cur = reverseList(head, nullptr);
        ListNode* temp = cur;
        while (temp != nullptr) {
            temp = temp->next;
        }
        int max_so_far = cur->val;
        ListNode* dummy = new ListNode{};
        ListNode* res = dummy;

        while (cur != nullptr) {
            // Valid node
            if (cur->val >= max_so_far) {
                max_so_far = cur->val;
                res->next = cur;
                res = res->next;
            }
            cur = cur->next;
        }
        res->next = nullptr;
        return reverseList(dummy->next, nullptr);
    }
private:

    ListNode* reverseList(ListNode* node, ListNode* prev) {
        if (node == nullptr) {
            return prev;
        }
        ListNode* temp = node->next;
        node->next = prev;
        return reverseList(temp, node);
    }
    
};
