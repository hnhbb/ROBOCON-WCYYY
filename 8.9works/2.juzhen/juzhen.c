#include "juzhen.h"  // 引入头文件
#include <stdio.h>
#include <stdlib.h>  // malloc 和 free

// 初始化矩阵
void initMatrix(Matrix *matrix, uint8_t row, uint8_t column) {
    matrix->row = row;
    matrix->column = column;
    matrix->data = (float **)malloc(row * sizeof(float *));
    for (int i = 0; i < row; i++) {
        matrix->data[i] = malloc(column * sizeof(float));
    }
}

// 输入矩阵元素
void inputMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->column; j++) {
            scanf("%f", &(matrix->data[i][j]));
        }
    }
}

// 输出矩阵
void printMatrix(const Matrix *matrix) {
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->column; j++) {
            printf("%f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// 释放矩阵内存
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->row; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

// 计算与转置矩阵的乘积
void multiplyWithTranspose(const Matrix *matrix) {
    if (matrix->row != matrix->column) {
        printf("矩阵不是方阵，无法进行与转置矩阵的乘积运算。\n");
        return;
    }

    // 创建结果矩阵
    Matrix result = {matrix->row, matrix->column, malloc(matrix->row * sizeof(float *))};
    for (int i = 0; i < matrix->row; i++) {
        result.data[i] = malloc(matrix->column * sizeof(float));
    }

    // 计算矩阵与其转置矩阵的乘积
    for (int i = 0; i < matrix->row; i++) {
        for (int j = 0; j < matrix->column; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < matrix->column; k++) {
                result.data[i][j] += matrix->data[i][k] * matrix->data[k][j];
            }
        }
    }

    // 输出结果矩阵
    printMatrix(&result);

    // 释放结果矩阵内存
    for (int i = 0; i < result.row; i++) {
        free(result.data[i]);
    }
    free(result.data);
}
