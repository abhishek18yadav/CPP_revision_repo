
#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> answer;
        for (int i = 0; i < numRows; i++)
        {
            answer.push_back(vector<int>(i + 1, 1));
        }
        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j < i; j++)
            {
                int temp = answer[i - 1][j] + answer[i - 1][j - 1];
                answer[i][j] = temp;
            }
        }
        return answer;
    }

    int main()
    {
        int numRows;
        cin >> numRows;
        vector<vector<int>> result = generate(numRows);
        for (const auto &row : result)
        {
            for (const auto &val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
        return 0;
    }