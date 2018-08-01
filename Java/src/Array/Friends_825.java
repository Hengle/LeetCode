package Array;

public class Friends_825 {
    public int numFriendRequests(int[] ages) {
        int[] buckets = new int[121];
        int lowerThan14 = 0;
        int len = ages.length;
        for (int i = 0; i < len; ++i) {
            int age = ages[i];
            if (age < 15) {
                ++lowerThan14;
                continue;
            }
            for (int j = age / 2 + 8; j <= age; ++j) {
                buckets[j] ++;
            }
        }
        int count = 0;
        for (int i = 0; i < len; ++i) {
            int age = ages[i];
            count += buckets[age];
        }
        return count - (len - lowerThan14);
    }
}
