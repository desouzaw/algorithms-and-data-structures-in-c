#include <stdio.h>
#include <stdbool.h>

void b_sort(int *const, const size_t);
void printArr(const int *const, const size_t);
void swap(int *const, int *const);

int main(void) {
   int arr[] = {45, 6, 7, 9, -11, 23, 12, 87, 34, -2};
   const size_t length = sizeof(arr) / sizeof(int);

   printf("Antes da Ordenação: ");
   printArr(arr, length);
   b_sort(arr, length);
   printf("Depois da ordenação: ");
   printArr(arr, length);

   return 0;
}

void b_sort(int *const arr, const size_t length) {
   if (length < 2) return;

   for (size_t i = 0; i < length - 1; i++) {
      bool swapped = false;

      for (size_t j = 0; j < length - 1 - i; j++) {
         if (arr[j] > arr[j + 1]) {
            swap(&arr[j], &arr[j + 1]);
            swapped = true;
         }
      }

      if (!swapped)
         break;
   }
}

void printArr(const int *const arr, const size_t length) {
   for (size_t i = 0; i < length; i++)
      printf("%d ", arr[i]);
   putchar('\n');
}

void swap(int *const a, int *const b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}