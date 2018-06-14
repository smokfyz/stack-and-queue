#include <stdio.h>
#include <string.h>

int universalMax(void* array, int n, int elem_size, int (*cmp)(void*, void*)) {
    int max = 0;
    for(int i = 0; i < n; i++)
        if(cmp(array+max*elem_size, array+i*elem_size) < 0) max = i;
    return max;
}

int str_compare(void* el1, void* el2) {
    return (int)(*(char*)el1 - *(char*)el2);
}

int int_compare(void* el1, void* el2) {
    return (int)(*(int*)el1 - *(int*)el2);
}

int double_compare(void* el1, void* el2) {
    if(*(double*)el1 == *(double*)el2) return 0;
    return *(double*)el1 > *(double*)el2 ? 1 : -1;
}

int main() {
    int elem_size;
    scanf("%d%*c", &elem_size);
    switch(elem_size) {
        case 1: {
            char arr[20];
            for(int i = 0; i < 20; i++)
              scanf("%c%*c", &arr[i]);
            printf("%d", universalMax(arr, 20, elem_size, str_compare));
            break;
        }
        case 4: {
            int arr[20];
            for(int i = 0; i < 20; i++)
              scanf("%d", &arr[i]);
            printf("%d", universalMax(arr, 20, elem_size, int_compare));
            break;
        }
        case 8:
        {
            double arr[20];
            for(int i = 0; i < 20; i++)
              scanf("%lf", &arr[i]);
            printf("%d", universalMax(arr, 20, elem_size, double_compare));
            break;
        }
    }
    
    return 0;
}
