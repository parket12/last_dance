#include <iostream>
#include <thread>
#include <algorithm>

namespace std {
    class MergeSort {
    public:
        void Sort(int* arr, int size) {
            if (size <= 1) return;
            int m = size / 2;
            int* l = new int[m];
            int* r = new int[size - m];

            copy(arr, arr + m, l);
            copy(arr + m, arr + size, r);

            Sort(l, m);
            Sort(r, size - m);
            Merge(arr, l, m, r, size - m);

            delete[] l;
            delete[] r;
        }

    private:
        void Merge(int* arr, int* left, int levrazm, int* right, int pravrazm) {
            int i = 0, j = 0, k = 0;
            while (i < levrazm && j < pravrazm) {
                if (left[i] < right[j]) {
                    arr[k++] = left[i++];
                }
                else {
                    arr[k++] = right[j++];
                }
            }
            while (i < levrazm) {
                arr[k++] = left[i++];
            }
            while (j < pravrazm) {
                arr[k++] = right[j++];
            }
        }
    };
}

int main() {
    setlocale(LC_ALL, "Russian");
    int arr[10];
    std::cout << "Введите 10 целых чисел:\n";
    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    std::MergeSort sorter;
    auto sort_function = [&sorter](int* arr, int size) {
        sorter.Sort(arr, size);
        };

    std::thread sort_thread(sort_function, arr, 10);
    sort_thread.join();

    std::cout << "Отсортированный массив:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
