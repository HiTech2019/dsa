/*
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
class TwoSum {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int, int> hash;
            vector<int> ins(2);
            for(int i = 0; i< nums.size(); i++) { 
                if(hash.find(target - nums[i]) != hash.end()) {
                    ins[0] = hash[target - nums[i]];
                    ins[1] = i;
                    break;
                }
                hash[nums[i]] = i;
            }
            return ins;
        }
};

