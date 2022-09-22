/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeZeroSumSublists(ListNode *head)
        {
            unordered_map<int, ListNode*> mp;

            int s = 0;

            ListNode *temp = head;
            while (temp)
            {
                

                s += temp->val;
                if (s == 0)
                {
                    head = temp->next;
                    temp = head;
                    mp.clear();
                    continue;
                }
                if (mp.find(s) != mp.end())
                {
                    ListNode *x = mp[s];
                    x->next = temp->next;
                    temp = head;
                    mp.clear();
                    s = 0;
                    continue;
                }
                else
                {
                    mp[s] = temp;
                }
                temp = temp->next;
            }

            return head;
        }
};