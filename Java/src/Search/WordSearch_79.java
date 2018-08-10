package Search;

import java.awt.*;
import java.util.*;

public class WordSearch_79 {
    static int[][] dir = new int[][] { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static int width = 0;
    static int height = 0;
    public boolean dfs(char[][] board, String word, boolean[][] visited, int x, int y, int wordIndex) {
        if (x < 0 || x >=width || y < 0 || y >= height || wordIndex >= word.length()) {
            return false;
        }
        if (visited[x][y]) {
            return false;
        }
        if (board[x][y] != word.charAt(wordIndex)) {
            return false;
        }
        if (wordIndex == word.length() - 1) {
            return true;
        }
        visited[x][y] = true;
        boolean v =  dfs(board, word, visited, x +1, y, wordIndex + 1) ||
                dfs(board, word, visited, x , y + 1, wordIndex + 1) ||
                dfs(board, word, visited, x - 1, y, wordIndex + 1) ||
                dfs(board, word, visited, x , y - 1, wordIndex + 1);
        visited[x][y] = false;
        return v;
    }
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length <= 0 || board[0].length <= 0) {
            return false;
        }
        if (word.length() <= 0) {
            return true;
        }
        width = board.length;
        height = board[0].length;
        boolean[][] visited = new boolean[width][height];
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (board[i][j] == word.charAt(0)) {
                    if (dfs(board, word, visited, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
