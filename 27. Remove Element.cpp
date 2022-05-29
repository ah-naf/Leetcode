class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0; vector<int> v; int len = nums.size();
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == val) {
                cnt++;
                v.push_back(-1);
            } else {
                v.push_back(nums[i]);
            }
        }
        // for(auto it: v) cout<<it<<" ";
        nums.clear();
        for(int i=0; i<v.size(); i++) {
            if(v[i] == -1) continue;
            nums.push_back(v[i]);
        }
        return len-cnt;
        
    }
};
