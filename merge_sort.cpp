#include <iostream>

using namespace std;

void arrayInput(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void marge(int arr[], int l, int mid, int r)
{

    int te[r - l + 1];
    int i = l;
    int k = 0;
    int j = mid + 1;
    while (i <= mid and j <= r)
    {
        if (arr[i] < arr[j])
        {
            te[k++] = arr[i++];
            continue;
        }
        else
            te[k++] = arr[j++];
    }
    while (i <= mid)
        te[k++] = arr[i++];

    while (j <= r)
        te[k++] = arr[j++];
    for (int i = 0; i < k; i++)
    {
        arr[l + i] = te[i];
    }
}

void margeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;

    margeSort(arr, l, mid);
    margeSort(arr, mid + 1, r);
    marge(arr, l, mid, r);
}

int main()
{
    cout << "Enter Size of Array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Elements of the array: " << endl;
    arrayInput(arr, n);
    margeSort(arr, 0, n - 1);
    cout << "Sorted Array" << endl;
    print(arr, n);
    return 0;
}