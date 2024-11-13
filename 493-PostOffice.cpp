#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, x[10001] = {0}, y[10001] = {0};
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    sort(x, x+n);
    sort(y, y+n);

    int post_x = x[n / 2];
    int post_y = y[n / 2];
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += abs(x[i] - post_x) + abs(y[i] - post_y);
    }

    cout << sum << '\n';
    return 0;
}