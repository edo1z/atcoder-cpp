#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int result = pow(A, B) + pow(B, A);
    cout << result << endl;

    return 0;
}
