//Find the Divisibility Array of a String

**pre-requisite:

1)Subarray Sums Divisible by K
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

solution:
 int subarraysDivByK(vector<int>& nums, int k) {        
    unordered_map<int, int> m;
    int cnt = 0, currSum = 0;
    for (int i : nums)
    {
        currSum += i;
        int rem = currSum % k;
        if(rem<0)
            rem += k;
        if(rem==0)
            cnt++;
        
        if (m.find(rem)!= m.end())   //saare previous element ke saath a sakta h 
            cnt += m[rem];
        
        m[rem]++;
    }
    return cnt;
}


2)Make Sum Divisible by P
Given an array of positive integers nums, 
remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p.

solution:
int minSubarray(vector<int>& nums, int p) {
        long long int sum=0,rem;
        for(auto it:nums){
           sum=(sum+it)%p;
        }
        rem=sum%p;
        if(rem==0)
        return 0;

        unordered_map<int,int> mp;
        int rev=nums.size();
        long long int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            int need=curr%p;
            if(need==rem){
               rev=min(rev,(i+1));
            }
            if(mp.find(need-rem)!=mp.end()){
               rev=min(rev,i-mp[need-rem]);
            }
            if(mp.find(p+need-rem)!=mp.end()){
                rev=min(rev,i-mp[p+need-rem]);
            }
            mp[need]=i;
        }
        if(rev==nums.size()){
            return -1;
        }
    
        return rev;
    }