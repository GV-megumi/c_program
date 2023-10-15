#include <iostream>

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = arr[left];
        int i = left;
        int j = right;

        while (i < j)
        {
            while (i < right && arr[i] <= pivot)
            {
                i++;
            }
            while (j > left && arr[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[left], arr[j]);

        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}

int main()
{
    int arr[] = {19, 4, 5, 6, 7, 3, 2, 25, 8, 10,13};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    std::cout << "快速排序：";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> n;

    return 0;
}
