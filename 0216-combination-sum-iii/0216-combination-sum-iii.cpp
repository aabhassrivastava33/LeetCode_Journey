class Solution {
    void solve(int i, int k , int target ,vector<vector<int>>&answer ,vector<int>&temp )
    { 
        //base case 1
        if(k==0)
        { if(target==0){
            answer.push_back(temp);
        } 
        return;
        }
        //base case 2
        if(target<0 or i>9)
         return;
        
        //revursive  case
        temp.push_back(i);
        solve(i+1 , k-1,target-i,answer,temp);
        temp.pop_back();//backtracking 

        solve(i+1,k,target,answer,temp);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>answer;
        vector<int> temp;
        solve( 1 , k , n , answer , temp);
        return answer;
    }
};