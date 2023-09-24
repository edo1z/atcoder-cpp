#include <bits/stdc++.h>
using namespace std;

bool is_321_like(int n) {
    int prev_digit = -1;
    while (n > 0) {
        int current_digit = n % 10;
        if (current_digit <= prev_digit) {
            return false;
        }
        prev_digit = current_digit;
        n /= 10;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    if (is_321_like(N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
