class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nd) {
        sort(nums.begin(),nums.end());
        sort(nd.begin(),nd.end());
        int count=0;
        int cd = nd[0];
        for(int i=1;i<nd.size();i++)
        {
            cd = __gcd(cd,nd[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(cd%nums[i]==0)
            {
                return count;
            }
            count++;
        }
        return -1;
    }
};
