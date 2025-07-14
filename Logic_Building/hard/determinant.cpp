// Calculating the Determinant of a Matrix
#include<iostream>
#include<vector>
using namespace std;

// Function to find determinant recursively

int get_det(vector<vector<int>>& mat , int n)
{
    // Base Case: Dimension 1 by 1
    if(n == 1)
    {
        // Return itself
        return mat[0][0];
    }

    // Dimension Two by Two
    if(n == 2)
    {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    // Recursive Case
    int det = 0;
    for(int col = 0; col < n; col++)
    {
        // Create a submatrix removing the first row and current column
        vector<vector<int>> sub(n-1 , vector<int>(n-1));

        // Looping From the Second Row of the Matrix
        for(int i = 1; i < n ; i++)
        {
            int sub_col = 0;
            // Looping through the columns
            for(int j = 0; j < n ; j++)
            {
                // Skip the column if its the current column
                if(j == col) continue;

                // Else Append it to the sub Matrix
                // Essentially finding the co-factor matrix for this row cna column
                sub[i-1][sub_col++] = mat[i][j];
            }
        }

        // Sign based on if its even or odd position
        int sign = (col % 2 == 0)?1:-1;

        // Multiplying the value at the current row and column by the determinant of the co-factor recursively
        det += sign * mat[0][col] * get_det(sub, n-1);
    }
    return det;
}
