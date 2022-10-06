//greedly choose
//means heavy chamce of priority queue
#define debug(x) cout << #x << " = " << x << endl;
class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
           	//freq store
            unordered_map<char, int> mp;
            for (auto &x: tasks)
            {
                mp[x]++;
            }

            priority_queue<pair<int, char>> pq;
            for (auto &x: mp)
                pq.push({ x.second,
                    x.first });

            int t = 0;
            vector<pair<int, char>> v;
            while (!pq.empty())
            {

                ++t;
                pair<int, char> p = pq.top();
                pq.pop();
                // debug(p.second);
                p.first--;
                if (p.first > 0)
                    v.push_back(p);
                int limit = n;
                while (limit)
                {

                    if (!pq.empty())
                    {
                        ++t;
                        pair<int, char> p = pq.top();
                        pq.pop();
                        p.first--;
                        if (p.first > 0)
                            v.push_back(p);
                        // debug(p.second);
                    }
                    else
                    {
                        if (!pq.empty() or v.size() > 0)
                        {
                             t += limit;
                            debug(t);
                        }
                        break;
                    }
                    limit--;
                }

                if (v.size() > 0)
                {
                    for (auto &x: v)
                        pq.push(x);
                }
                v.clear();
            }
            return t;
        }
};