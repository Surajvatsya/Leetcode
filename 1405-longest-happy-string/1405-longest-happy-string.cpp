typedef pair<int, char> pr;

class Solution
{
    public:
        string longestDiverseString(int a, int b, int c)
        {
            priority_queue<pr> pq;
            if (c > 0)
                pq.push({ c,
                    'c' });
            if (b > 0)
                pq.push({ b,
                    'b' });

            if (a > 0)
                pq.push({ a,
                    'a' });

            string s = "";

            char prev1 = '@';
            char prev2 = '@';

            while (!pq.empty())
            {
                pr p = pq.top();
                pq.pop();
                char ch = p.second;
                int freq = p.first;

                if (ch == prev1 and ch == prev2)
                {
                   	//2nd top most nikalo
                    if (pq.size() == 0)
                        return s;
                    pr q = pq.top();
                    pq.pop();
                    char s_ch = q.second;
                    int s_freq = q.first;

                    s += s_ch;
                    s_freq--;
                    prev1 = prev2;
                    prev2 = s_ch;

                    if (s_freq > 0)
                        pq.push({
                            s_freq, s_ch });
                }
                else
                {

                    s += ch;
                    freq--;
                    prev1 = prev2;
                    prev2 = ch;
                }

                if (freq > 0)
                    pq.push({ freq,
                        ch });
            }

            return s;
        }
};