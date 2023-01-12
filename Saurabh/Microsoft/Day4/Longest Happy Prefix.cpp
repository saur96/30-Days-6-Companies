class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        int i = 0;
        int j = 1;
        // string s1 = "";
         vector<int>s1(n, 0);
        while(j<n)
        {
            if(s[i]==s[j])
            {
               s1[j] = i+1;
               j++;
               i++;
            }
            else{
                if(i==0){
                j++;
                }
                else{
                    i = s1[i-1];
                }
            }
        }
        // return s1;
         return s.substr(0,i);
    }
};
