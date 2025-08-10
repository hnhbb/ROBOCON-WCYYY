#include <stdio.h>
#include "../inc/queue.h"

 int main()
 {
    queue q;
    int value;

    QueueInit(&q);// 初始化队列

        printf("入队元素:\n");
    for (int i = 1; i <= 5; i++) {
        if (QueuePush(&q, i * 10)) {
            printf("入队 %d 成功\n", i * 10);
        }
    }

   printf("\n出队元素:\n");
    for (int i = 0; i < 3; i++) {
        if (QueuePop(&q, &value)) {
            printf("出队 %d\n", value);
        }
    }

    return 0;

 }