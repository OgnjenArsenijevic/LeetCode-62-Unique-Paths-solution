//
class Solution
{
public:
    int uniquePaths(int n, int m) 
    {
        //Base case (if we have only 1 row or 1 column than
        //there is only 1 unique path from start to finish)
        if(n==1 || m==1)
            return 1;
        if(n<=m)
        {
            int DP[n][2];
            //Filling the values for the most left column (base cases)
            for(int i=0;i<n;i++)
                DP[i][0]=1;
            //Filling DP values for the column that we
            //are currently looking, while constantly
            //keeping track of values in previous column
            //We do this until we reach last column
            for(int j=1;j<m;j++)
            {
                DP[0][1]=1; //Base case
                for(int i=1;i<n;i++)
                    DP[i][1]=DP[i][0]+DP[i-1][1];
                //Updating values in previous column
                for(int i=0;i<n;i++)
                    DP[i][0]=DP[i][1];
            }
            //Return the solution
            return DP[n-1][1];
        }
        else
        {
            int DP[2][m];
            //Filling the values for the top row (base cases)
            for(int i=0;i<m;i++)
                DP[0][i]=1;
            //Filling DP values for the row that we
            //are currently looking, while constantly
            //keeping track of values in previous row
            //We do this until we reach last row
            for(int i=1;i<n;i++)
            {
                DP[1][0]=1; //Base case
                for(int j=1;j<m;j++)
                    DP[1][j]=DP[1][j-1]+DP[0][j];
                //Updating values in previous row
                for(int j=0;j<m;j++)
                    DP[0][j]=DP[1][j];
            }
            //Return the solution
            return DP[1][m-1];
        }
    }
};
