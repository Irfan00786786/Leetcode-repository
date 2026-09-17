class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const long long MOD = 1000000007;

        unordered_map<int, long long> count;
        unordered_map<int, long long> sum;

        long long ans = 0;

        for (int x : nums) {
            long long cnt = 1;

            long long s = x;
            if (count.find(x - 1) != count.end()) {
                cnt = (cnt + count[x - 1]) % MOD;
                s = (s + sum[x - 1] + 
                     count[x - 1] * x) % MOD;
            }

            if (count.find(x + 1) != count.end()) {
                cnt = (cnt + count[x + 1]) % MOD;
                s = (s + sum[x + 1] + 
                     count[x + 1] * x) % MOD;
            }
            count[x] = (count[x] + cnt) % MOD;
            sum[x] = (sum[x] + s) % MOD;

            ans = (ans + s) % MOD;
        }

        return ans;
    }
};