#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main() {
    // 使用uint32_t类型存储结果，初始为0
    uint32_t result = 0;

    // 设置随机种子，确保每次运行结果不同
    srand((unsigned int)time(NULL));

    printf("生成的32个随机数如下：\n");

    for (int i = 0; i < 32; ++i) {
        // 生成0~100之间的随机数
        int num = rand() % 101;

        // 打印生成的随机数
        printf("%3d ", num);

        // 如果大于50，将对应的第i位设为1
        if (num > 50) {
            result |= (1U << i);  // 使用位或运算设置第i位
        }
    }

    printf("\n最终生成的uint32_t整数为：%u\n", result);
    printf("其二进制表示为：");

    // 打印二进制形式
    for (int i = 31; i >= 0; --i) {
        printf("%d", (result >> i) & 1);
    }

    return 0;
}
