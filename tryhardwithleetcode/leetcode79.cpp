#include<bits/stdc++.h>
using namespace std;
    int check[10000][10000];
    int track = 0;
        int dfs(int u, int v, vector<vector<char>> board, string word) { // board == board
            check[u][v] = true;
            int m = board.size(), n = board[0].size();
            for (int i = u; i <board.size(); i++) {
                for (int j = v; j < board[1].size(); j++) {
                    if (board[i][j] == word[track]) {
                        track++;
                        if (i>0 && board[i - 1][j] == word[track] && check[i][j] == true) {
                            dfs(u - 1, v, board, word);
                        } else if (j<n-1 && board[i][j + 1] == word[track] && check[i][j] == true) {
                            dfs(u, v + 1, board, word);
                        } else if (i<m-1 && board[i + 1][j] == word[track] && check[i][j] == true) {
                            dfs(u + 1, v, board, word);
                        } else if (j>0 && board[i][j - 1] == word[track] && check[i][j] == true) {
                            dfs(u, v - 1, board, word);
                        }
                        if (track == word.size()) {
                            return 1;
                        }
                        else {
                            check[u][v] = false;
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
            return dfs(0, 0, board, word);
        }
    int main(){
        vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
        };
        cout<<exist(board, "ABCCED");
    }