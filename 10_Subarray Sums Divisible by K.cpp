class Solution {
public:
    static int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod_k(k, 0);//2 <= k <= 10^4 array is good
        int prefix=0;
        mod_k[0]=1;// consider prefix sums that are directly divisible by k

        for(int x: nums){
            prefix=(prefix+x)%k;
            prefix+=((prefix<0)?k:0);
            mod_k[prefix]++;
        }
        return accumulate(mod_k.begin(), mod_k.end(), 0, [](int sum, int x){
            return sum+x*(x-1)/2;
        });
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();