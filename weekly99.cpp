//Count Total Number of Colored Cells
There exists an infinitely large two-dimensional grid of uncolored unit cells. 
You are given a positive integer n, indicating that you must do the following routine for n minutes:
for 1=1,2=5,3=13,4=25,.........

solution:
use AGP

//Count Ways to Group Overlapping Ranges

You are given a 2D integer array ranges where ranges[i] = [starti, endi] 
denotes that all integers between starti and endi (both inclusive) are contained in the ith range.

You are to split ranges into two (possibly empty) groups such that:

i)Each range belongs to exactly one group.
ii)Any two overlapping ranges must belong to the same group.

solution:
we have to find non-overlapping intervals count:so,using merge intervals(leetcode)
class Solution {
public:
int merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int j=0;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]>ans[j][1]){
                ans.push_back(intervals[i]);    
                j++;
            }else if(intervals[i][0]<=ans[j][1]){
               ans[j][0]=min(intervals[i][0],ans[j][0]);
               ans[j][1]=max(intervals[i][1],ans[j][1]);
            }
        }
        return ans.size();
    }
    int countWays(vector<vector<int>>& ranges) {
        int cnt=merge(ranges);
        long long ans=1;
        while(cnt--){
            ans=(ans*2)%1000000007;
        }
        return ans;
    }
}; 