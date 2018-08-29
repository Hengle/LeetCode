package Array;

public class Transpose_Matrix_867 {
    public int[][] transpose(int[][] A) {
        int w = A.length;
        int h = A[0].length;
        int[][] ans = new int[h][w];
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }
}
