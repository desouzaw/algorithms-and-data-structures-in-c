#include <stdio.h>

void s_sort(int *const, const size_t);
void printArr(const int *const, const size_t);
void swap(int *const, int *const);

int main(void) {
   int arr[] = {98, 56, 2, 3, -1, 32, 12, 76, 8, 34, 2, 9, 5};
   const size_t length = sizeof(arr) / sizeof(int);

   printf("Antes da ordenação: ");
   printArr(arr, length);
   s_sort(arr, length);
   printf("Depois da ordenação: ");
   printArr(arr, length);

   return 0;
}

void s_sort(int *const arr, const size_t length) {
   if (length < 2) return;

   for (size_t i = 0; i < length - 1; i++) {
      size_t min = i;

      for (size_t j = i + 1; j < length; j++)
         if (arr[j] < arr[min]) 
            min = j;

      if (min != i) 
         swap(&arr[min], &arr[i]);
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