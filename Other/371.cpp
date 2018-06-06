class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry;
        do {
            sum = a ^ b ;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        } while (b);
        return a;
    }
};
int main(int argc, char *argv[])
{
    return 0;
}
