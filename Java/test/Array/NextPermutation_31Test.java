package Array;

import org.junit.jupiter.api.Test;

class NextPermutation_31Test {

    @Test
    void reverse() {
        var s = new NextPermutation_31();
        {
            var v = new int[]{1, 2};
            s.reverse(v, 0, v.length - 1);
            for (var i : v) {
                System.out.println(i);
            }
        }
        {
            var v = new int[]{1, 2, 3, 4, 5, 6, 7};
            s.reverse(v, 0, v.length - 1);
            for (var i : v) {
                System.out.println(i);
            }
        }
        {
            var v = new int[]{1, 2, 3, 4, 5, 6};
            s.reverse(v, 0, v.length - 1);
            for (var i : v) {
                System.out.println(i);
            }
        }
    }

    @Test
    void nextPermutation() {
        var s = new NextPermutation_31();
        var v = new int[]{1, 2, 3, 4};
        for (int t = 0; t < 30; t++)    {
            System.out.printf("test case %d\n", t);
            s.nextPermutation(v);
            for (var i : v) {
                System.out.printf("%d ", i);
            }
            System.out.println();
        }
    }
}