#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (left + right) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[5];
    cout << "Enter 5 integers: ";

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];

        if (cin.fail()) {
            cout << "Error: Invalid input. Please enter an integer." << endl;
            return 1;
        }
    }

    int temp[5];
    int inversionCount = mergeSortAndCount(arr, temp, 0, 4);

    cout << "Number of inversions: " << inversionCount << endl;

    return 0;
}
