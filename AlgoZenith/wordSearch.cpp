#include<bits/stdc++.h>
using namespace std;
int m, n;
int dp[6][6][15];
vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool find(int r, int c, int idx, string &word, vector<vector<char>> &board)
{
    if (idx == word.length())
        return true;
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '$')
        return false;
    if (board[r][c] != word[idx])
        return false;
    char temp = board[r][c];
    board[r][c] = '$';
    // for(auto ele : dir){
    //     int new_r = r + ele[0];
    //     int new_c = c + ele[1];
    //     if( find(new_r, new_c, idx + 1, word, board))return true;
    // }
    bool ans = find(r - 1, c, idx + 1, word, board) ||
               find(r + 1, c, idx + 1, word, board) ||
               find(r, c - 1, idx + 1, word, board) ||
               find(r, c + 1, idx + 1, word, board);
    board[r][c] = temp;
    return ans;
}

bool exist(vector<vector<char>> &board, string word)
{
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0] and find(i, j, 0, word, board))
            {
                return true;
            }
        }
    }
    return false;
}
int main(){
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCB";
    bool result = exist(board, word);
    cout << (result ? "true" : "false") << endl;
    return 0;
}