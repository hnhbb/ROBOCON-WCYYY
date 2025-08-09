#ifndef JUZHEN_H
#define JUZHEN_H

#include <stdint.h>  // 引入 uint8_t 类型
#include <stdio.h>   // 引入 printf 和 scanf 函数
#include <stdlib.h>  // 引入 malloc 和 free 函数

// 定义矩阵结构体
typedef struct {
    uint8_t row, column;
    float **data;
} Matrix;

// 函数声明
void initMatrix(Matrix *matrix, uint8_t row, uint8_t column);
void inputMatrix(Matrix *matrix);
void printMatrix(const Matrix *matrix);
void freeMatrix(Matrix *matrix);
void multiplyWithTranspose(const Matrix *matrix);  // 移除 inline

#endif // JUZHEN_H
