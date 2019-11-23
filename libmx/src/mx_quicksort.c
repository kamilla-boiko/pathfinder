#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;
    if (arr == NULL || *arr == NULL) {
        return -1;
    }
    if (left < right) {
        int low = left;
        int high = right;
        int pivot = (high + low) / 2;
        while (low <= high) {
            while (mx_strlen(arr[low]) < mx_strlen(arr[pivot])) {
                low++;
            }
            while (mx_strlen(arr[high]) > mx_strlen(arr[pivot])) {
                high--;
            }
            if(low <= high) {
                if(mx_strlen(arr[low]) > mx_strlen(arr[high])) {
                    count++;
                    mx_swap_str(&arr[low], &arr[high]);
                }
                else if(mx_strlen(arr[low]) == mx_strlen(arr[high])) {
                    if (mx_strcmp(arr[low], arr[high]) > 0)  {
                        count++;
                        mx_swap_str(&arr[low], &arr[high]);
                    }
                }
                low++;
                high--;
            }
        }
        count += mx_quicksort(arr, left, high);
        count += mx_quicksort(arr, low, right);
    }
    return count;
}
