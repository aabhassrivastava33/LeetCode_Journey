class Solution {
public:
    bool ispossible(vector<int>& position, int m , int mid)
    {
        int ball = 1;
        int pos=position[0];
        for(int i=0;i<position.size();i++)
        {
            if(position[i]-pos>=mid)
            {
            ball++;
            pos=position[i];
            }
            if(ball==m)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int start = 1;
        int end = position[n-1]-position[0];
        int ans = -1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if (ispossible(position,m,mid))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    return ans;
    }
};