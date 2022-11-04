class Solution
{
    public:

    
    bool vowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U';
    }
    
        string reverseVowels(string s)
        {
            int i = 0;
            int j = s.size()-1;

            while (i < j)
            {
                if (vowel(s[i]) and vowel(s[j]))
                {
                    swap(s[i], s[j]);
                    i++;
                    j--;
                }
                else if(vowel(s[i]))
                    j--;
                else if(vowel(s[j]))
                    i++;
                else{
                    i++;
                    j--;
                }
                
            }
            return s;
        }
};