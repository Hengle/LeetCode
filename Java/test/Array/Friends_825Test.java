package Array;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class Friends_825Test {

    @Test
    void numFriendRequests1() {
        var f = new Friends_825();
        var args = new int[]{16, 16};
        var ans = f.numFriendRequests(args);
        assertEquals(2, ans);
    }

    @Test
    void numFriendRequests2() {
        var f = new Friends_825();
        var args = new int[]{16, 17, 18};
        var ans = f.numFriendRequests(args);
        assertEquals(2, ans);
    }

    @Test
    void numFriendRequests3() {
        var f = new Friends_825();
        var args = new int[]{20, 30, 100, 110, 120};
        var ans = f.numFriendRequests(args);
        assertEquals(3, ans);
    }
}