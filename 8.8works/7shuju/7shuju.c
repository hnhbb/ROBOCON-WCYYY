#include <stdio.h>
#include <stdint.h>

// 函数：判断当前系统是否是小端字节序
int is_little_endian() {
    uint16_t test = 0x0001;
    
    return *((uint8_t*)&test) == 0x01;
}

// 函数：32位整数大小端转换（返回转换后的值）
uint32_t swap_endian32(uint32_t val) {
    return ((val >> 24) & 0x000000FF) | 
           ((val >> 8)  & 0x0000FF00) |
           ((val << 8)  & 0x00FF0000) |
           ((val << 24) & 0xFF000000);
}

// 函数：以字节方式打印32位整数的内存布局
void print_bytes(uint32_t val) {
    uint8_t *bytes = (uint8_t*)&val;
    for (int i = 0; i < 4; ++i) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
}

int main() {
    uint32_t value = 0x12253647;

    printf("本机字节序：%s\n", is_little_endian() ? "小端（Little Endian）" : "大端（Big Endian）");

    printf("\n原始值：0x%08X\n", value);
    printf("本机内存布局（按字节从低地址到高地址）：\n");
    print_bytes(value);

    uint32_t swapped = swap_endian32(value);
    printf("\n大小端转换后的值：0x%08X\n", swapped);
    printf("转换后内存布局（按字节从低地址到高地址）：\n");
    print_bytes(swapped);

    return 0;
}
