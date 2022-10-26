#define debug(x) cout<<#x<<" = "<<x<<endl;
class Solution
{
    public:

        bool valid(string s)
        {
            vector<int> v(26, 0);
            for (auto &x: s)
                v[x - 'a']++;
            for (int i = 0; i < 26; i++)
            {
                if (v[i] > 1)
                    return false;
            }
            return true;
        }

    void solve(vector<string> &arr, string s, int ind, int &count)
    {
       	//bc
        if (ind >= arr.size())
        {
          
            if (s.length() > count)
                count = s.size();
            return;
        }

       	//take
        if(valid(s  + arr[ind] ))
        solve(arr, s + arr[ind], ind + 1, count);

       	//not take
        solve(arr, s, ind + 1, count);
    }

    int maxLength(vector<string> &arr)
    {
        string s = "";
        int count = 0;
        solve(arr, s, 0, count);
        return count;
    }
};