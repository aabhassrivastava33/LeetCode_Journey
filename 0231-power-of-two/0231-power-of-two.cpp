class Solution {
    bool check(int n , int i)
    {
        if(pow(2,i)==n)
        return true;
        
        if(pow(2,i)>n)
        return false;

        return check(n,i+1);

    }
public:
    bool isPowerOfTwo(int n) {
    return check(n,0);
    }
};