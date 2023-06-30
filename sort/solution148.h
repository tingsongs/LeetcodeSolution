#include "..\tool.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* bubleSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode dump(0, head);
        ListNode* pre = &dump;

        int len = 0;
        while(head != nullptr)
        {
            len++;
            head = head->next;
        }
        
        for(;len > 1; len--)
        {
            pre = &dump;
            head = pre->next;
            for(int n = len; n > 1; n--)
            {
                if(head->val > head->next->val)
                {
                    pre->next = head->next;
                    head->next = head->next->next;
                    pre->next->next = head;
                }
                pre = pre->next;
                head = pre->next;
            }
        }

        return dump.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
            return head;

        int len = 1;
        ListNode* end = head;
        while(end->next != nullptr)
        {
            len++;
            end = end->next;
        }
        return subMergeListSort(head, end, len);
    }

    ListNode* subMergeListSort(ListNode* start, ListNode* end, int len)
    {
        if(len == 1)
        {
            start->next = nullptr;
            return start;
        }
            
        
        ListNode* mid = start;
        for(int i=1; i<len/2; i++)
            mid = mid->next;
        ListNode* midnext = mid->next;

        ListNode* start1 = subMergeListSort(start, mid, len/2);
        ListNode* start2 = subMergeListSort(midnext, end, len-len/2);

        ListNode dump;
        ListNode* cur = &dump;
        while(start1 != nullptr && start2 != nullptr)
        {
            if(start1->val <= start2->val)
            {
                cur->next = start1;
                cur = cur->next;
                while(cur->next != nullptr && cur->next->val <= start2->val)
                    cur = cur->next;
                start1 = cur->next;
            }else
            {
                cur->next = start2;
                cur = cur->next;
                while(cur->next != nullptr && cur->next->val < start1->val)
                    cur = cur->next;
                start2 = cur->next;
            }
        }
        cur->next = start1 ? start1 : start2;
        return dump.next;
    }

    void test()
    {
        ListNode node5(0, nullptr);
        ListNode node4(4, &node5);
        ListNode node3(3, &node4);
        ListNode node2(5, &node3);
        ListNode node1(-1, &node2);
        ListNode* res = sortList(&node1);
        while (res != nullptr)
        {
            cout << res->val << " ";
            res = res->next;
        }
        
    }
};