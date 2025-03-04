#include<bits/stdc++.h>
using namespace std;
        int dfs(int u, int v, int track, vector<vector<char>> a,
                string word) { // a == board
            for (int i = 0; i < u; i++) {
                for (int j = 0; j < v; j++) {
                    if (a[i][j] == word[track]) {
                        track++;
                        if (a[i - 1][j] == word[track]) {
                            dfs(i - 1, j, track, a, word);
                        } else if (a[i][j + 1] == word[track]) {
                            dfs(i, j + 1, track, a, word);
                        } else if (a[i + 1][j] == word[track]) {
                            dfs(i + 1, j, track, a, word);
                        } else if (a[i][j - 1] == word[track]) {
                            dfs(i, j - 1, track, a, word);
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
        exist( [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED")
    }