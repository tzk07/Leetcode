#include <utility>
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

// Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        int lenA = 0, lenB = 0;

        while (currA != nullptr){
            ++lenA;
            currA = currA->next;
        }
        while (currB != nullptr){
            ++lenB;
            currB = currB->next;
        }

        // 保持 链表A 是较长的一个
        if (lenA < lenB){
            std::swap(lenA, lenB);
            std::swap(headA, headB);
        }

        currA = headA;
        currB = headB;

        int gap = lenA - lenB;
        while (gap --){
            currA = currA->next;
        }
        while (currA != nullptr){
            if (currA == currB){
                return currA;
            }
            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};