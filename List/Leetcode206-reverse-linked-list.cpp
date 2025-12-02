#include <cstddef>
#include <iostream>

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // 保存下一个节点
            curr->next = pre;            // 翻转指针
            pre = curr;                  // pre 后移
            curr = next;                 // curr 后移
        }

        return pre;  // pre 是新头结点
    }
};
