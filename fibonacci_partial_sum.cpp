#include <iostream>
#include <vector>
using std::vector;

int get_fibonacci_last_digit_naive(int n) {
    int f[n];
    if (n <= 1)
        return n;

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n ; ++i) {
       f[i] = (f[i-1] + f[i-2])%10;  
    }

    return f[n];
}

int fibonacci_sum_naive(long long from, long long to) {

    long long current;
    long long sum = 0;

    for (long long i = from; i <= to; ++i) {
        current =  get_fibonacci_last_digit_naive(i);
        sum+=current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
