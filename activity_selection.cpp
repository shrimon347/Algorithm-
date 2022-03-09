#include <iostream>
#include <bits\stdc++.h>

using namespace std;

struct Activity
{
    int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activity_compare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}

void max_activities(Activity arr[], int n)
{

    // sort accrodng to their finish time
    sort(arr, arr + n, activity_compare);

    cout << "Following activites are selected : ";

    // first activity always selected
    int i = 0;
    cout << "(" << arr[i].start << " , " << arr[i].finish << " ), ";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << " , " << arr[j].finish << " ), ";
            i = j;
        }
    }
    cout << endl
         << i + 1 << endl; // somw error result showing later you find the problem
}

int main()
{

    int s;
    cout << "Enter the size of struct activity : ";
    cin >> s;
    struct Activity arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i].start >> arr[i].finish;
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    max_activities(arr, n);

    return 0;
}
