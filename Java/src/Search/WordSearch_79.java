package Search;

import java.awt.*;
import java.util.*;

public class WordSearch_79 {
    static int[][] dir = new int[][] { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public boolean exist(char[][] board, String word) {
        if (board == null || board.length <= 0 || board[0].length <= 0) {
            return false;
        }
        if (word.length() <= 0) {
            return true;
        }
        int m = board.length;
        int n = board[0].length;
        Queue<Point> queue = new LinkedList<Point>();
        ArrayList<Point> entry = new ArrayList<Point>();
        int[][] d = new int[m][n];
        int index = 0;
        int tx, ty;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word.charAt(index)) {
                    entry.add(new Point(i, j));
                }
            }
        }
        for (Point e : entry) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    d[i][j] = -1;
                }
            }
            d[e.x][e.y] = 0;
            queue.clear();
            ((LinkedList<Point>) queue).push(e);
            while (!queue.isEmpty()) {
                Point front = ((LinkedList<Point>) queue).pollFirst();
                if (d[front.x][front.y] == word.length() - 1) {
                    return true;
                } else if (d[front.x][front.y] > word.length() - 1) {
                    continue;
                }
                for (int i = 0; i < 4; ++i) {
                    tx = front.x + dir[i][0];
                    ty = front.y + dir[i][1];
                    if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
                        if (d[tx][ty] == -1 && board[tx][ty] == word.charAt(d[front.x][front.y] + 1)) {
                            ((LinkedList<Point>) queue).push(new Point(tx, ty));
                            d[tx][ty] = d[front.x][front.y] + 1;
                        }
                    }
                }
            }
        }
        return false;
    }
}
