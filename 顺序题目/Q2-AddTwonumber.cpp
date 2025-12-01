/* 
给定两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int x):val(x),next(nullptr){};
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class Solution {
public:
    // 法1：链表 -> 数字 -> 链表
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2){
        long long num1=0, num2=0, base = 1;
        while(l1){
            num1 += l1->val * base;
            base *= 10;
            l1 = l1->next;
        }

        base = 1;
        while(l2){
            num2 += l2->val * base;
            base *= 10;
            l2 = l2->next;
        }

        long long sum = num1 + num2;
        if(sum == 0) return new ListNode(0);
        ListNode* List = nullptr;
        ListNode* tail = nullptr;
        while(sum){
            // while(sum) 等价于 while(sum != 0)
            int digit = sum%10;
            sum /= 10;
            ListNode* newNode = new ListNode(digit);
            if(!List){
                List = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return List;
    }

    // 法2：逐位相加
    ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2){
        ListNode* List = nullptr;
        ListNode* tail = nullptr;
        int carry = 0; // 进位
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }

            if(!List){
                List = new ListNode(carry%10);
                tail = List;
            } else {
                tail->next = new ListNode(carry%10);
                tail = tail->next;
            }

            carry = carry / 10; // 更新进位
        }
        return List;
    }

};

int main(){
    Solution s;
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode* res1 = s.addTwoNumbers_1(l1, l2);
    cout << "法1：链表->数字->链表\n";
    while(res1){
        cout << res1->val << " ";
        res1 = res1->next;
    }

    cout << "\n";

    ListNode* res2 = s.addTwoNumbers_2(l1, l2);
    cout << "法2：逐位相加\n";
    while(res2){
        cout << res2->val << " ";
        res2 = res2->next;
    }
    return 0;
}