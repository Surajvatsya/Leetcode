```
class Solution {
public:
unordered_map<string, string>mp;
// Encodes a URL to a shortened URL.
string generate(){
string temp="";
for(int i=0; i<5; i++){
int  v1 = rand() % 125;
char ch = v1;
temp+=ch;
}
return temp;
}
string encode(string longUrl) {
string temp;
while(1){
temp = generate();
if(mp.find(temp)!=mp.end()){
mp[temp] = longUrl;
break;
}
}
return temp;
}
​
// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
return mp[shortUrl];
}
};
​
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```