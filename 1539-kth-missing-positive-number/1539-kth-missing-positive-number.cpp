class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=k)k++;
            else break;
        }
        return k;
    }
};
        
         // /*Explanation->
//          Case 1->[4,6,7,8,10] k=3 If first element is greater than k,it means the missing number is present before it so we will simply have k as a missing number
         
//          Case2->[2,3,4,7,11] k=5 now in this case since 2 is present so it will push my k as k=5 cant be my answer because 2 is present so k=6 now when we will move to i=1 that is 6 it is still smaller to k so it will again push my k to 7. Now for i=2 i.e 7 it will again push as it is smaller than k so k=8 similarly for i=3 k will get increased to k=9.Now for i=4 arr[i]>k hence k is my answer.
            
 