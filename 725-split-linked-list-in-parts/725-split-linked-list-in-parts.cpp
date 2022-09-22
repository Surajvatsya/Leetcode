/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        vector<ListNode*> splitListToParts(ListNode *head, int k)
        {
              vector<ListNode*> ans;
           
            
            ListNode *temp = head;
          
            int l = 0;
            while (temp)
            {
                l++;
                temp = temp->next;
            }

           	//l=3, k = 5;

            int extra = l % k;
            int n = l / k;

           	//n=0 extra = 3

            temp = head;
            
            // cout << temp->val<<endl;

            while (temp)
            {
                int len = n;
                ListNode *start = new ListNode(-1);
                ListNode *mid = start;

                while (len--and temp)
                {

                    mid->next = temp;
                    mid = temp;
                   	// cout<<mid->val<<" ";
                    temp = temp->next;
                }
                if (extra)
                {
                    mid->next = temp;
                    mid = temp;
                   	// cout<<mid->val<<" ";
                    if (temp)
                        temp = temp->next;
                    extra--;
                }
                mid->next = NULL;
                ans.push_back(start->next);

                
                // cout << endl;
            }

            int rest = k - ans.size();

            if (ans.size() < k)
                while (rest--)
                    ans.push_back(NULL);

            return ans;
        }
};