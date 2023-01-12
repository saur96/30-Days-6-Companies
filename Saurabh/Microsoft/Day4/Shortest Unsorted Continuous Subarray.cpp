class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        if(v==nums)
        {
            return 0;
        }
        int  ans1 = 0;
        int ans2 =0;
        for(int i=0;i<n;i++)
        {
            if(v[i]!=nums[i])
            {
                ans1 = (i+1);
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]!=nums[i])
            {
                ans2 = (i+1);
                break;
            }
        }
        return (ans2 - ans1)+1;
    }
};
