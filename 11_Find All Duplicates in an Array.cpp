#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int next=(nums[i]&((1<<17)-1))-1;
            if (nums[next]>>17) 
                ans.push_back(next+1);
            nums[next]|=(1<<17);
        }
        return ans;
    }
};