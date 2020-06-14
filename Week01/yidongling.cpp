class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int t=nums.size(),p=0;
        for(int i = 0;i < t;i++){
            if(nums[i] != 0){
                int temp=nums[i];
                nums[p]=temp;
                p++;
            }
        }
        while(p<t)
        nums[p++]=0;
    }