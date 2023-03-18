//pass the pillow
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. 
Every second, the person holding the pillow passes it to the next person standing in the line. 
Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

solution:
circular arrangement
int passThePillow(int n, int time) {
        int round=time/(n-1);  //no of rounds
        int k=time%(n-1);   //remaining
        return (round%2==0)? k+1:n-k;

}

// Kth Largest Sum in a Binary Tree
You are given the root of a binary tree and a positive integer k.The level sum in the tree is the sum of the values of the nodes that are on the same level.
Return the kth largest level sum.

solution:
 sum of the values of same level,so, BFS
 kth largest,so, priority_queue

//Number of Ways to Earn Points
There is a test that has n types of questions.
You are given an integer target and a 0-indexed 2D integer array types where types[i] = [counti, marksi] indicates that there are counti questions of the ith type,
and each one of them is worth marksi points.
Return the number of ways you can earn exactly target points in the exam.

solution:
taken and not taken concept (3d dp)
 int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<vector<int>>> memo(1001, vector<vector<int>>(51, vector<int> (51, -1)));
        return dfs(target, types, 0, 0, memo);
    }
    int dfs(int target, vector<vector<int>>& types, int i, int j, vector<vector<vector<int>>>& memo) {
        if (target < 0 || i == types.size() || j > types[i][0]) return 0;
        if (target == 0) {
            return 1;
        }
        if (memo[target][i][j] != -1) return memo[target][i][j];

        int ways = 0;
        ways+= dfs(target - types[i][1], types, i, j + 1, memo);
        ways+= dfs(target, types, i + 1, 0, memo);
        ways %= (1000000000 + 7);
        memo[target][i][j] = ways;
        return ways;  
    }

    