// int this question there will be a matrix given containing 0 and 1's now you have to set the the entire row or column of the matrix as 0 which contains matrix[i][j]=0;
// eg[1,1,1],[1,0,1],[1,1,1];
// output [[1,0,1],[0,0,0],[1,0,1]]

// frist approoach int this approach we are taking extra space + n^2 time complexity
// where we are keeping a track of 0 using two vectors inr for row another for column
// jisme ki jis row m 0hoga row vector k uss indexko mark kr denge
// jis column m 0 hoga uske column vector ko mark kr denge
int m = matrix.size();
int n = matrix[0].size();
vector<int> row(m, 0);
vector<int> col(n, 0);
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (matrix[i][j] == 0)
        {
            // here we are marking the row and  column vector
            row[i] = 1;
            col[j] = 1;
        }
    }
}
//   this loop is for traversing again to set the matrix as 0
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        if (row[i] == 1 || col[j] == 1)
        {
            matrix[i][j] = 0;
        }
    }
}
// second approach
// here we are keeping the track of column and row that which row or column is having a 0 int the matrix itself
// but ek catch hai yha pr humm matric[0],[0] dono row aur column k liye aaega
// uske liye hum 2 extra variable rakhenge taaki 0th inddex row aur 0th index column ko track kr sake

void setZeroes(vector<vector<int>> &matrix)
{
    // r and c are here to track the matrix[0][0]
    int r = false, c = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                // both if condition is for tracking the 0th row and column
                if (i == 0)
                    r = true;
                if (j == 0)
                    c = true;
                // these two things are for keeping track of 0 from row index and column index
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    // this is for setting the matrix 0 from first index to n-1 tk
    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // this for the matrix[0][0]=0 we set the entire row as 0
    if (r)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[0][i] = 0;
        }
    }
    // this for the matrix[0][0]=0 we set the entire column as 0
    if (c)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][0] = 0;
        }
    }
