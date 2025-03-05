#include<bits/stdc++.h>
using namespace std;
        int dfs(int u, int v, int track, vector<vector<char>> board, string word) { // board == board
            if (track == word.size()) {
                return 1;
            }
            int m = board.size(), n = board[0].size();
            for (int i = u; i <board.size(); i++) {
                for (int j = v; j < board[0].size(); j++) {
                    if (board[i][j] == word[track]) {
                        track++;
                        if (i>0 && board[i - 1][j] == word[track]) {
                            dfs(u - 1, v, track, board, word);
                        } else if (j<n-1 && board[i][j + 1] == word[track]) {
                            dfs(u, v + 1, track, board, word);
                        } else if (i<m-1 && board[i + 2][j] == word[track]) {
                            dfs(u + 1, v, track, board, word);
                        } else if (j>0 && board[i][j - 1] == word[track]) {
                            dfs(u, v - 1, track, board, word);
                        } else {
                            track--;
                            return 0;
                        }
                    }
                }
            }
            if (track == word.size()) {
                return 1;
            }
            return 0;
        }
        bool exist(vector<vector<char>>& board, string word) {
            return dfs(0, 0, 0, board, word);
        }
    int main(){
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        cout<<exist(board, "ABCCED");
    }