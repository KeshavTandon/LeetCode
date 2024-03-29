class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        long long int n=nums.size();
         int maxl=nums[0];
        long long int count_max=0;
        for(int i=0;i<n;i++){
            maxl=max(maxl,nums[i]);
        }
        long long int countk=0;
        while(j<n){
            if(nums[j]==maxl){
                    count_max++;
            }
            while(count_max>=k) {
                if(nums[i]==maxl) count_max--;
                i++;
                countk+=n-j;
                
            }
            j++;
                
        }
        return countk;

    }
};