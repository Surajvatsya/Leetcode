class Solution {
public:
    struct comparator {
    bool operator()(string b, string a){
        if(a.length()>b.length())
            return true;
        else if(a.length() < b.length())
            return false;
        else{
            for(int i=0; i<a.length(); i++){
                if(a[i] - '0' < b[i] - '0')
                    return false;
                else if(a[i] - '0' > b[i] - '0')
                    return true;  
             }
            return true;
        }
    }
};
    
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>, comparator>p;
        for(auto &x : nums)
            p.push(x);
        for(int i=0; i<k-1; i++){
            p.pop();
        }
   
        return p.top();
    }
};