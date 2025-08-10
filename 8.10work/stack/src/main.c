#include <stdio.h>
#include <stdbool.h>
#include "../inc/stack.h"

int main()
{
    stack s;
    int stack_size = 100;  // 设定栈大小为100字节
    int val;
    bool ret;

    // 初始化栈
    StackInit(&s, stack_size);
    if (s.base == NULL) {
        return -1;  // 内存分配失败，退出
    }

    // 入栈几个整数
    printf("入栈:\n");
    for (int i = 1; i <= 5; i++) {
        val = i * 10;
        ret = StackPush(&s, &val, sizeof(int));
        if (ret) {
            printf("成功入栈 %d\n", val);
        } else {
            printf("入栈失败 %d\n", val);
        }
    }

    // 出栈并打印
    printf("\n出栈:\n");
    while (!StackEmpty(&s)) {
        ret = StackPop(&s, &val, sizeof(int));
        if (ret) {
            printf("出栈 %d\n", val);
        } else {
            printf("出栈失败\n");
            break;
        }
    }

    // 释放栈内存
    StackFree(&s);

    return 0;
}
