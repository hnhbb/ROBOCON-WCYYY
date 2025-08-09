#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于 qsort 排序
int cmp_float(const void *a, const void *b) {
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

int main() {
    float *arr = NULL;  // 动态分配数组
    int size = 0;
    int capacity = 10;  // 初始分配的空间，10个元素
    arr = (float *)malloc(capacity * sizeof(float));  // 分配内存

    if (arr == NULL) {
        printf("内存分配失败!\n");
        return 1;  // 内存分配失败，退出程序
    }

    printf("请输入若干个浮点数，每行一个，:\n");

    while (scanf("%f", &arr[size]) == 1) {
        size++;
        // 如果超出当前分配的空间，使用 realloc 扩展空间
        if (size >= capacity) {
            capacity *= 2;  // 每次扩展两倍
            arr = (float *)realloc(arr, capacity * sizeof(float));  // 重新分配内存
            if (arr == NULL) {
                printf("内存扩展失败!\n");
                return 1;  // 如果扩展内存失败，退出程序
            }
        }
    }

    // 排序
    qsort(arr, size, sizeof(float), cmp_float);

    // 输出排序结果
    printf("排序结果:\n");
    for (int i = 0; i < size; i++) {
        printf("%.6f\n", arr[i]);
    }

    // 释放动态分配的内存
    free(arr);

    return 0;
}
