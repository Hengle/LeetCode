package Array;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Transpose_Matrix_867Test {

    @Test
    void transposeTest() {
        var t = new Transpose_Matrix_867();
        var a = new int[][]{
                {1,2,3,},
                {4,5,6},
        };
        var ans = t.transpose(a);
        int w = ans.length;
        int h = ans[0].length;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                System.out.printf("%d ", ans[i][j]);
            }
            System.out.println();
        }
    }
    @Test
    void transposeTest2() {
        var t = new Transpose_Matrix_867();
        var a = new int[][]{
                {1,2,3,},
                {4,5,6},
                {7,8,9}
        };
        var ans = t.transpose(a);
        int w = ans.length;
        int h = ans[0].length;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                System.out.printf("%d ", ans[i][j]);
            }
            System.out.println();
        }
    }
}