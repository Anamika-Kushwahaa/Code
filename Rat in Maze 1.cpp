// GEEKS FOR GEEKS
// Rat in a Maze Problem - I

// Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists as the destination cell is blocked.
// Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
// Constraints:
// 2 ≤ mat.size() ≤ 5
// 0 ≤ mat[i][j] ≤ 1

// CODE:-
class Solution {
  private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 &&m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
        //base case
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }
        visited[x][y]=1;
        
        //4 choices -> UP, DOWN, RIGHT, LEFT
        //DOWN
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
         //LEFT
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
          //RIGHT
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
       
          //UP
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, n, visited, m)){
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        visited[x][y]=0;
        
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n=maze.size();
        vector<string> ans;
        if( maze[0][0]==0 ){
            return ans;
        }
        int srcx=0;
        int srcy=0;
        vector<vector<int>> visited=maze;
        //initialising visited matrix with'0'
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                visited[i][j]=0;
            }
        }
        string path = "";
        solve(maze, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
         
    }
};
