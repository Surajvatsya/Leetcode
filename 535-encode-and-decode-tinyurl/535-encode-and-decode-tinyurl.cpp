class Solution {
public:

    int num = 0;
    map<string, string> mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        num++;
        string addon = to_string(num);
        string ans = longUrl;
        ans+=addon;
        mp[ans]=longUrl;
        return ans;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));