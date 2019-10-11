class Solution
{
public:
    int uniquePaths(int n, int m) 
    {
        int DP[n][m]; 
        //Filling the values for the top row (base cases)
        for(int i=0;i<m;i++)
            DP[0][i]=1;
        //Filling the values for the most left column (base cases)
        for(int i=1;i<n;i++)
            DP[i][0]=1;
        //Filling the rest of the DP matrix
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                DP[i][j]=DP[i][j-1]+DP[i-1][j];
        ///Return the solution from bottom-right corner of DP matrix
        return DP[n-1][m-1];
    }
};
