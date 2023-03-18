// Minimum Operations to Reduce an Integer to 0
You are given a positive integer n, you can do the following operation any number of times:
Add or subtract a power of 2 from n.
Return the minimum number of operations to make n equal to 0.
 54=0110110  ans=3

solution:
power of 2 ki baat ho rhi ...to kch bit se related ho sakta h
use bitset to store number...
aur consecutve 1 ko 1 se replace karke aage likh do
class Solution {
public:
    int minOperations(int n) {
        bitset<32> v(n);
        int cnt=0;
        for(int i=0;i<=31;i++){
            if(v[i]==1){
                int c=0;
                while(i<=31 && v[i]==1){
                    i++;
                    c++;
                }
                cnt++;
                if(c>1)
                v[i]=1;
                i--;
            }else{
                continue;
            }
        }
        return cnt;
    }
};

// Distinct Prime Factors of Product of Array
Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
Input: nums = [2,4,3,7,10,6]
Output: 4
Explanation:
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.

solution:
prime factors ki baat horhi to sieve of eratosthensis ho sakta h aur range 10000,so prime factors ko precompute karke rakh lenge
 aur prime factors ke liye hi check karenge only 
//sieve of eratosthenes
    vector<int> preCalc(int n){
        vector<int> prime(n+1, 0);
        int pr = 2;
        while(pr * pr<= n){
            if(prime[pr]== 0){
                for (int i=2*pr; i<n+1; i=i+pr)
                        prime[i]= 1;
            }
            pr++;
          }


        vector<int> ans;
        for (int i=2; i<n; i++) 
            if (prime[i]==0) 
                ans.push_back(i);
        
        return ans;
    }

    
