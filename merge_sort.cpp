#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int temp[], int low, int mid, int high)
{
    int i = low;
    int k = low;
    int j = mid + 1;

    while ((i <= mid) && (j <= high))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= high)
    {
        temp[k++] = arr[j++];
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void marge_sort(int arr[], int temp[], int low, int high)
{
    if (low != high)
    {
        int mid;
        mid = (low + high) / 2;
        marge_sort(arr, temp, low, mid);
        marge_sort(arr, temp, mid + 1, high);
        merge(arr, temp, low, mid, high);
    }
}

int main()
{

    int size, n;

    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n], temp[n];

    cout << "Enter the array element : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "Array elements are : ";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << arr[i];
    }

    marge_sort(arr, temp, 0, n - 1);
    cout << endl
         << "Merge sort elements are : ";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << arr[i];
    }
    return 0;
}
