class Solution {
public:
    long long countVowels(string word) {
        
       long long n = word.size();
        
        long long s=0;
        
        for(long long i=0; i<n; i++){
        
            if( word[i]=='a' or word[i]=='e' or word[i]=='i' or word[i]=='o' or word[i]=='u'){
                s+=i+(n-i);
                s+=i * (n-i-1);
                // cout<<s<<endl;
            }
            
        }
            
        return s;
        
    }
};