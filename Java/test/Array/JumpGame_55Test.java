package Array;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class JumpGame_55Test {

    @Test
    void canJump1() {
        var jump = new JumpGame_55();
        var arr = new int[]{2, 3, 1, 1, 4};
        assertEquals(true, jump.canJump(arr));
    }

    @Test
    void canJump2() {
        var jump = new JumpGame_55();
        var arr = new int[]{3, 2, 1, 0, 4};
        assertEquals(false, jump.canJump(arr));
    }
}