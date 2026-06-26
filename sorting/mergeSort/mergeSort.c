#include <stdio.h>

void m_sort(int *const, const size_t);
void merge_sort(int *const, const size_t, const size_t);
void merge(int *const, const size_t, const size_t, const size_t);
void printArr(const int *const, const size_t);
void swap(int *const, int *const);

int main(void) {
   int arr[] = {5, 9, 87, -2, 11, 0, 6};
   const size_t length = sizeof(arr) / sizeof(int);

   printf("Antes da ordenação: ");
   printArr(arr, length);
   m_sort(arr, length);
   printf("Depois da ordenação: ");
   printArr(arr, length);

   return 0;
}

void m_sort(int *const arr, const size_t length) {
   if (length < 2) return;

   merge_sort(arr, 0, length - 1);
}

void merge_sort(int *const arr, const size_t start, const size_t end) {
   if (start < end) {
      size_t middle = start + (end - start ) / 2;

      merge_sort(arr, start, middle);
      merge_sort(arr, middle + 1, end);
      merge(arr, start, middle, end);
   }
}

void merge(int *const arr, const size_t start, const size_t middle, const size_t end) {
   int arr_temp[end + 1];
   size_t ptr_left = start;
   size_t ptr_right = middle + 1;
   size_t i = start;

   while (ptr_left <= middle && ptr_right <= end) {
      if (arr[ptr_left] <= arr[ptr_right]) {
         arr_temp[i] = arr[ptr_left];
         ptr_left++;
      } else {
         arr_temp[i] = arr[ptr_right];
         ptr_right++;
      }

      i++;
   }

   while (ptr_right <= end) {
      arr_temp[i] = arr[ptr_right];
      i++;
      ptr_right++;
   }

   while (ptr_left <= middle) {
      arr_temp[i] = arr[ptr_left];
      i++;
      ptr_left++;
   }

   for (size_t i = start; i <= end; i++)
      arr[i] = arr_temp[i];
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