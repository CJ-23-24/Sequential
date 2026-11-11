///CJ Shay
///COSC-2436-001
///A00601182 



#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int sequentialSearch(int arr[], int size, int target, int& count)
{
    count = 0;

    for (int i = 0; i < size; i++)
    {
        count++;

        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int size, int target, int& count)
{
    int first = 0;
    int last = size - 1;

    count = 0;

    while (first <= last)
    {
        int middle = (first + last) / 2;

        count++;

        if (arr[middle] == target)
        {
            return middle;
        }
        else if (arr[middle] < target)
        {
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }

    return -1;
}

int main()
{
    const int SIZE = 26;
    int numbers[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        numbers[i] = i * 2;
    }

    srand(time(0));

    int sequentialTotal = 0;
    int binaryTotal = 0;

    for (int i = 0; i < 5; i++)
    {
        int randomIndex = rand() % SIZE;
        int target = numbers[randomIndex];

        int sequentialCount = 0;
        int binaryCount = 0;

        sequentialSearch(numbers, SIZE, target, sequentialCount);
        binarySearch(numbers, SIZE, target, binaryCount);

        sequentialTotal += sequentialCount;
        binaryTotal += binaryCount;

        cout << "Target: " << target << endl;
        cout << "Sequential Search Comparisons: "
            << sequentialCount << endl;
        cout << "Binary Search Comparisons: "
            << binaryCount << endl;
        cout << endl;
    }

    cout << "Total Sequential Comparisons: "
        << sequentialTotal << endl;

    cout << "Total Binary Comparisons: "
        << binaryTotal << endl;

    cout << "Average Sequential Comparisons: "
        << sequentialTotal / 5.0 << endl;

    cout << "Average Binary Comparisons: "
        << binaryTotal / 5.0 << endl;

    return 0;
}
