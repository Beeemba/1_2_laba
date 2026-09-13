#include <iostream>

void process(int*& arr, int& size)
{
    int negativeIndex = -1;
//3.1
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            negativeIndex = i;
            break;
        }
    }
    if (negativeIndex == -1)
    {
        std::cout << "Отрицательных элементов нет.";
        return;
    }
    std::cout << "Первый отрицательный элемент: " << arr[negativeIndex] << " (индекс "<< negativeIndex << ")\n";
//3.2
    int newSize = negativeIndex;
    int* newArr = nullptr;
    if (newSize > 0)
    {
        newArr = new int[newSize]{};
        for(int i = 0; i < newSize; i++)
        {
            newArr[i] = arr[i];
        }
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
}

void printArray(const int* arr, int size)
{
    if (arr == nullptr || size <= 0)
    {
        std::cout << "массив пуст.\n";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    int n;
    std::cout << "Введите размер массива N: ";
    std::cin >> n;
    if (n <= 0)
    {
        std::cout << "Размер должен быть положительным!\n";
        return 1;
    }
    int* arr = new int[n]{};
    std::cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << " arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    std::cout << "\nИсходный массив: ";
    printArray(arr, n);
    int size = n;
    process(arr, size);
    std::cout << "\nМассив после обработки (размер = " << size << "): ";
    printArray(arr, size);

    delete[] arr;
    arr = nullptr;

    std::cout << "\nПопытка обращения к массиву после освобождения памяти.";
    if (arr != nullptr)
    {
        std::cout << "FATAL ERROR!!!";
    }
    else
    {
        std::cout << "Указатель равен nullptr.\n";
    }
    return 0;
}