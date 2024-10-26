#include <iostream>
#include <cmath>
using namespace std;

int toplam(long long arr[], int n, long long sum[]) {
    for (int i{}; i < (1 << n); i++) {
        long long int i_sum = 0;
        for (int j{}; j < n; j++) {
            if (i & (1 << j)) {
                i_sum += arr[j];
            }
        }
        sum[i] = i_sum;
    }
    return 0;
}

void bubbleSort(long long arr[], int n) {
    for (int i{}; i < n - 1; ++i) {
        for (int i = 0; i < n - i - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}

long long binFind(long long arr[], int n, long long res) {
    int l = 0, r = n - 1;
    long long closest = arr[0];
    while (r >= l) {
        int m = (r + l) / 2;
        if (abs(arr[m] - res) < abs(closest - res)) {
            closest = arr[m];
        }
        if (arr[m] < res) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return closest;
}

long long l_sum[1 << 16];
long long r_sum[1 << 16];

int main(){
    cout << "na meste" << endl;


    int n;
    cin >> n;
    int half = n / 2;
    long long grams[32];
    for (int i = 0; i < n; i++) {
        cin >> grams[i];
    }
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += grams[i];
    }
    toplam(grams, half, l_sum);
    toplam(grams + half, n - half, r_sum);
    int l_n = 1 << half;
    int r_n = 1 << n - half;
    bubbleSort(r_sum, r_n);
    long long minn = total_sum;
    for (int i{}; i < l_n; i++) {
        long long l_s = l_sum[i];
        long long res = total_sum / 2 - l_s;
        long long closest_r_s = binFind(r_sum, r_n, res);
        long long diff = abs(total_sum - 2 * (l_s + closest_r_s));
        if (diff < minn) {
            minn = diff;
        }
    }
    cout << minn << endl;
    return 0;
}