#include <iostream>
using namespace std;

int maxDifference(int arr[], int n) {
    int maxDiff = arr[1] - arr[0];
    int minElement = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - minElement > maxDiff) {
            maxDiff = arr[i] - minElement;
        }

        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    return maxDiff;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum difference is " << maxDifference(arr, n) << endl;
    return 0;
}
