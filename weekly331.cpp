//Take Gifts From the Richest Pile
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:
Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.
Input: gifts = [25,64,9,4,100], k = 4
Output: 29

Solution:
1)after k second 
2)every time topmost element hi select karna h
To priority_queue will be best option


//Count Vowel Strings in Ranges
You are given a 0-indexed array of strings words and a 2D array of integers queries
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]

Solution:
Range queries ki baat ho ,to prefix sum ko consider karo
bool fun(vector<string>&  words,int i){
    
            char c1=words[i][0],c2=words[i][words[i].length()-1];
            if((c1=='a' || c1=='e' || c1=='i' || c1=='o' || c1=='u' ) && (c2=='a' || c2=='e' || c2=='i' || c2=='o' || c2=='u' ))
                return true;
            else
            return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        vector<int> ans(q.size(),0);
        vector<int> v(words.size()+1);
        v[0]=0;
        for(int i=1;i<=words.size();i++){
            if(fun(words,i-1))
                v[i]=v[i-1]+1;          //equation for prefix sum
            else
                v[i]=v[i-1];
        }
        for(int i=0;i<q.size();i++){
            int s=q[i][0],e=q[i][1];
            ans[i]=v[e+1]-v[s];
        }
        return ans;
    }

//House Robber IV 
There are several consecutive houses along a street, each of which has some money inside. 
There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
Input: nums = [2,3,5,9], k = 2
Output: 5


Solution:
minimum of the maximum,jb bhi bole to binary search
