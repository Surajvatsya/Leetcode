class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {

           	//aage wala piche wale k sath v bna skta h

            unordered_map<string, int> mp;
             unordered_map<string, int> rep;

            int ans = 0;
           	int f=1;
            for (auto &x: words)
            {

                string temp = x;

                reverse(temp.begin(), temp.end());
                if (x == temp)
                {
                    // ans += 2;
                    rep[x]++;
                  
                }
                else if (mp[temp] > 0)
                {

                    ans += 4;
                    mp[temp]--;
                }
                else
                    mp[x]++;
            }
            
            int mx= 0;
            for(auto &x : rep)
            {
                if(x.second==1)
                    f=0;
                else if(x.second%2==0){
                    ans+=(x.second*2);
                }
                else if(x.second%2!=0){
                    ans+=(x.second-1)*2;
                    f=0;
                }
            }
                if(f==0)
                    ans+=2;

            return ans;
        }
};