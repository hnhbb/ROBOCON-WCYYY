#include "juzhen.h"  // 引入头文件
#include <stdio.h>

int main() {
    Matrix matrix;
    uint8_t row, column;

    // 输入矩阵的行列数
    scanf("%hhu %hhu", &row, &column);
    initMatrix(&matrix, row, column);

    // 输入矩阵元素
    inputMatrix(&matrix);

    // 输出矩阵并计算转置矩阵的乘积
    printMatrix(&matrix);
    multiplyWithTranspose(&matrix);

    // 释放矩阵内存
    freeMatrix(&matrix);
    return 0;
}
