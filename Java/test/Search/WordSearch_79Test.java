package Search;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WordSearch_79Test {

    @Test
    void exist() {
        var s = new WordSearch_79();
        var a = new char[][] {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'},
        };
        assertTrue(s.exist(a, "ABCCED"));
        assertTrue( s.exist(a, "SEE"));
        assertFalse( s.exist(a, "ABCB"));
    }
    @Test
    void exist2() {
        var s = new WordSearch_79();
        var a = new char[][] {
                {'A', 'A'}
        };
        assertTrue(s.exist(a, "AA"));
        assertFalse(s.exist(a, "AAA"));
    }
    @Test
    void exist3() {
        var s = new WordSearch_79();
        var a = new char[][] {
                {'A','B','C','E'},
                {'S','F','E','S'},
                {'A','D','E','E'}};
        assertTrue(s.exist(a,"ABCESEEEFS"));
    }
}