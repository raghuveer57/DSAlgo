#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> createMatrix(size_t rows, size_t columns)
{
    vector<vector<int>> mat;
    for (auto i = 0; i < rows; i++)
    {
        mat.push_back(vector<int>(columns, i + 1));
    }
    return mat;
}

void printMatrixAuto(const vector<vector<int>> &mat)
{
    for (auto row : mat)
    {
        for (auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}

void printMatrixIndex(const vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    auto mat = createMatrix(3, 3);
    printMatrixAuto(mat);
    printMatrixIndex(mat);
    return 0;
}