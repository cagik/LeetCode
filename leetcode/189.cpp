class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int step = k%n;
        int count = gcd(n, step);
        for(int start = 0; start < count; ++start)
        {
            int cur = start;
            int pre = nums[cur];
            do{
                int next = (cur + step)%n;
                swap(pre, nums[next]);
                cur = next;
            }while(start != cur);
        }
    }
};