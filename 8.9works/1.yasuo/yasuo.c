#include<stdio.h>
#include<stdint.h>

int main()
{
 float f1 = 32.4352f;
 float f2 = 45.2235f;
//16bit 2的16次方 分成65535份
 uint16_t u1=(uint16_t)(f1/100*65535.0f);
 uint16_t u2=(uint16_t)(f2/100*65535.0f);

 char arr[4];
 *(uint16_t*)(arr) = u1;
 *(uint16_t*)(arr+2) = u2;

// 从char数组提取uint16_t
uint16_t r1 = *(uint16_t*)(arr);
uint16_t r2 = *(uint16_t*)(arr + 2);

// 还原float
float rf1 = ((float)r1 / 65535.0f) * 100.0f;
float rf2 = ((float)r2 / 65535.0f) * 100.0f;

// 打印还原结果及误差
printf("还原的f1 = %.5f, 误差 = %.5f\n", rf1, rf1 - f1);
printf("还原的f2 = %.5f, 误差 = %.5f\n", rf2, rf2 - f2);
return 0;
}