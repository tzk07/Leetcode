// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针法：fast 先走 n+1 步，之后 fast 和 slow 一起移动直到 fast 到最后
        // 此处 fast 多走了一步，slow 指向倒数 n+1 个节点，删除 slow->next，然后修改 slow 的 next 指针
        // 虚拟头结点：使用 dummyHead 能够避免边界处理的代码，主要情景为 删除头结点
        ListNode dummyHead;
        dummyHead.next = head;
        ListNode* fast = &dummyHead;
        ListNode* slow = &dummyHead;

        while (n-- && fast != nullptr){
            fast = fast->next;
        }
        fast = fast->next; // 在这里多走一步

        while (fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummyHead.next;
    }
};