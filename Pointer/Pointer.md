#Bài 3: Pointer
1. Khái niệm Pointer:
  Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số   khái niệm cơ bản về con trỏ trong C:
	Cách khai báo:

    int *ptr  // con trỏ đến kiểu int
    
    char *ptr_char;  // con trỏ đến kiểu char
    
    float *ptr_float;  // con trỏ đến kiểu float


	Lấy địa chỉ của một biến:
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x


	Sử dụng con trỏ để truy cập giá trị:
int y = *ptr_x;  // y sẽ bằng giá trị của x

 
	Kích thước của con trỏ sẽ phụ thuộc kiến trúc máy tính và trình biên dịch. Ta có thể dùng sizeof() để kiểm tra kích thước của con trỏ:
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %lu bytes\n", sizeof(ptr));
    return 0;
}


