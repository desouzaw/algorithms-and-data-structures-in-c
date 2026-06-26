#include <stdio.h>

void i_sort(int *const, const size_t);
void printArr(const int *const, const size_t);
void swap(int *const, int *const);

int main(void) {
   int arr[] = {6, 8, 65, -9, 0, 1, 0, 32, 12, 11, 43};
   const size_t length = sizeof(arr) / sizeof(int);

   printf("Antes da ordenação: ");
   printArr(arr, length);
   i_sort(arr, length);
   printf("Depois da ordenação: ");
   printArr(arr, length);

   return 0;
}

void i_sort(int *const arr, const size_t length) {
   if (length < 2) return;

   for (size_t i = 1; i < length; i++) {
      int key = arr[i];
      long j = i - 1;

      while ((j >= 0) && arr[j] > key) {
         arr[j + 1] = arr[j];
         j--;
      }

      arr[j + 1] = key;
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