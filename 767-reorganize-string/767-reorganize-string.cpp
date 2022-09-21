typedef pair<int, char> pr;
class Solution
{
    public:
        string reorganizeString(string s)
        {
            if (s.size() < 2)
                return s;

            int n = s.size();

            unordered_map<char, int> mp;

            for (int i = 0; i < n; i++)
            {
                mp[s[i]]++;
            }
            priority_queue<pr>pq;
            
            for(auto &x : mp){
                pq.push({x.second, x.first});
            }

            // char prev2 = '@';
            char prev = '@';

            string ans = "";
            while(!pq.empty()){
                
                pr p = pq.top();
                pq.pop();
                
                char ele = p.second;
                int freq = p.first;
                
                if(prev==ele){
                    if(pq.size()==0)
                        break;
                    
                     pr q = pq.top();
                pq.pop();
                
                char s_ele = q.second;
                int s_freq = q.first;
                    
                    ans+=s_ele;
                    s_freq--;
                    prev = s_ele;
                    if(s_freq>0)
                        pq.push({s_freq, s_ele});
                    
                    pq.push({freq,ele});
                    
                }
                else{
                    ans+=ele;
                    freq--;
                    prev=ele;
                    if(freq>0)
                        pq.push({freq, ele});
                    
                }
            }
            
            return s.size()==ans.size() ? ans : ""; 
        }
};