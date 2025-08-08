#include <stdio.h>
#include <string.h>
#include <math.h>

// 用于比较浮点数是否相等的容差
#define FLOAT_TOLERANCE 1e-6

// 比较两个浮点数是否相近
int float_equal(float a, float b) {
    return fabsf(a - b) < FLOAT_TOLERANCE;
}

// 方法一：使用 union 联合体
void method_union(float f1, float f2, char buf[8], float* out1, float* out2) {
    // 定义一个联合体，将 float 转换为 char 数组
    union {
        float f;
        char c[4];
    } u;

    // 将 f1 和 f2 的二进制存入 buf 中
    for (int i = 0; i < 4; ++i) {
        u.f = (i == 0) ? f1 : f2;  // 根据索引选择 f1 或 f2
        for (int j = 0; j < 4; ++j) {
            buf[i * 4 + j] = u.c[j]; // 将每个字节存入 buffer
        }
    }

    // 还原 f1 和 f2 到 out1 和 out2
    for (int i = 0; i < 4; ++i) u.c[i] = buf[i]; 
    *out1 = u.f;

    for (int i = 0; i < 4; ++i) u.c[i] = buf[i + 4];
    *out2 = u.f;
}

// 方法二：使用类型转换
void method_cast(float f1, float f2, char buf[8], float* out1, float* out2) {
    // 将 f1 和 f2 转换为字节流存入 buf
    *((float*)(buf)) = f1;
    *((float*)(buf + 4)) = f2;

    // 从 buf 还原为 float 类型
    *out1 = *((float*)(buf));
    *out2 = *((float*)(buf + 4));
}

// 方法三：使用 memcpy
void method_memcpy(float f1, float f2, char buf[8], float* out1, float* out2) {
    // 使用 memcpy 将 f1 和 f2 拷贝到 buf 中
    memcpy(buf, &f1, 4);
    memcpy(buf + 4, &f2, 4);

    // 从 buf 中恢复 f1 和 f2
    memcpy(out1, buf, 4);
    memcpy(out2, buf + 4, 4);
}

int main() {
    float f1 = 3.3546812f;  // 测试的第一个浮点数
    float f2 = -5.2656155f; // 测试的第二个浮点数

    char buffer[8]; // 用来存储浮点数的字节数组

    float o1, o2; // 存储还原后的浮点数

    printf("原始数值: f1 = %.7f, f2 = %.7f\n\n", f1, f2);

    // 方法1：使用 union
    method_union(f1, f2, buffer, &o1, &o2);
    printf("[方法1: union]      结果: f1 = %.7f, f2 = %.7f\n", o1, o2);

    // 方法2：类型转换
    method_cast(f1, f2, buffer, &o1, &o2);
    printf("[方法2: cast]       结果: f1 = %.7f, f2 = %.7f\n", o1, o2);

    // 方法3：memcpy
    method_memcpy(f1, f2, buffer, &o1, &o2);
    printf("[方法3: memcpy]     结果: f1 = %.7f, f2 = %.7f\n", o1, o2);

    return 0;
}
