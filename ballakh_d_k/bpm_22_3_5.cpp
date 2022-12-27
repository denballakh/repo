#include <iostream>
#include <inttypes.h>
#include <vector>

#include <cassert>

int32_t pow10(int n) {
    assert(n >= 0);
    int32_t res = 1;
    for (int i = 0; i < n; i += 1)
        res *= 10;
    return res;
}

int digit_length(int32_t n) {
    int res = 0;
    while (n) {
        res += 1;
        n /= 10;
    }
    return res;
}

int32_t digit_reverse(int32_t n) {
    int32_t res = 0;
    int len = digit_length(n);
    for (int i = 0; i < len; i += 1) {
        res += (n / pow10(i)) % 10 * pow10(len - i - 1);
    }
    return res;
}

int main() {
    std::vector<int32_t> arr;

    // arr.reserve(1);
    // while (std::cin >> arr[arr.size()]) {
    //     arr.push_back(arr[arr.size()]);
    //     arr.reserve(arr.size() + 1);
    // }

    while (std::cin.good()) {
        int32_t x;
        std::cin >> x;
        arr.push_back(x);
    }
    arr.pop_back();

    for (int i = 0; i < arr.size(); i += 2) {
        std::cout << digit_reverse(arr[arr.size() - i - 1]) << " ";
    }

    // for (int i = 0; i < arr.size(); i += 1) {
    //     std::cout << digit_reverse(arr[i]) << " ";
    // }

    std::cout << std::endl;
}
