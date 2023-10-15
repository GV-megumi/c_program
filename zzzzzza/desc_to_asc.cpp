#include <iostream>

void desc_to_asc(int a[], int length)
{
    int i, j, t, min;
    for (i = 0; i < length; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
        {
            if (a[j] < a[min])
                min = j;
            std::swap(a[i], a[min]);
        }
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int length = sizeof(a)/sizeof(a[0]);

    for (int k = 0; k < 5; k++)
        std::cout << a[k];
    std::cout << std::endl;
    desc_to_asc(a, length);
    for (int k = 0; k < 5; k++)
        std::cout << a[k];
    std::cout << std::endl;
    std::cin >> length;
    return 0;
}