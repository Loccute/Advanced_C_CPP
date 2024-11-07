# Bài 3: Pointer
## 1. Khái niệm và các loại Pointer
### 1.1 Khái niệm: 
Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số khái niệm cơ bản về con trỏ trong C:
Cách khai báo:
```
int *ptr;  // con trỏ đến kiểu int
char *ptr_char;  // con trỏ đến kiểu char
float *ptr_float;  // con trỏ đến kiểu float
```

Lấy địa chỉ của một biến:
```
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
```

Sử dụng con trỏ để truy cập giá trị:
```
int y = *ptr_x;  // y sẽ bằng giá trị của x
```

Kích thước của con trỏ sẽ phụ thuộc kiến trúc máy tính và trình biên dịch. Ta có thể dùng sizeof() để kiểm tra kích thước của con trỏ:
```
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %lu bytes\n", sizeof(ptr));
    return 0;
}
```


### 1.2 Các loại pointer:
#### a. Void pointer: 
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
```
void *ptr_void;
```

Ví dụ:


```
#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));
   
    return 0;
}
```


#### b. Pointer to Constant:
Định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

Tác dụng: Dùng con trỏ hằng để chỉ đọc giá trị tại địa chi mà nó trỏ tới mà không thay đổi giá trị tại đó. Ngoài ra, để đọc giá trị của dữ liệu bất kì mà muốn tiết kiệm bộ nhớ, thay vì khai báo 1 biến thông thường để đọc thì ta dùng 1 biến con trỏ (có kích thước cố định là 8 bytes ở kiến trúc 64 bit) trỏ tới địa chỉ chứa dữ liệu cần đọc và truy xuất thông qua biến con trỏ đó.
	
Ví dụ:

```
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int value = 5;
    int const *ptr_const = &value;

    //*ptr_const = 7; // wrong
    //ptr_const++; // right
    
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);

    return 0;
}
```

#### c. Constant Pointer:
Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.

Tác dụng: Ta tạo ra được một con trỏ đại diện cho 1 địa chỉ bất kì nào đó. Con trỏ đó sẽ trỏ tới địa chỉ cố định không thay đổi trong suốt quá trình thực thi chương trình. Ta có thể sử dụng trong các chương trình nhúng khi muốn setup các thanh ghi, nên cần các con trỏ cố định duy nhất để trỏ tới địa chỉ của các thanh ghi đó, thuận tiện để thao tác với các thanh ghi trên vi điều khiển.
```
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    //const_ptr = &test; // wrong
    
    return 0;
}
```

#### d. Function pointer:
Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.

Ví dụ:
```
#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}
```
Trong ví dụ này, ptrToGreet là một con trỏ hàm có thể trỏ đến các hàm greetEnglish và greetFrench. Việc này giúp linh hoạt trong việc chọn và sử dụng hàm tương ứng tại thời điểm chạy.

#### e. Pointer to pointer:
Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
Ví dụ:
```
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    printf("Value: %d\n", **ptr2);

    return 0;
}
```
Trong ví dụ này:
ptr1 là một con trỏ thường trỏ đến biến value.
ptr2 là một con trỏ đến con trỏ, trỏ đến địa chỉ của ptr1.
Khi sử dụng **ptr2, chúng ta có thể truy cập giá trị của biến value.

Ứng dụng phổ biến trong cấp phát động mảng hai chiều:
```
#include <stdio.h>
#include <stdlib.h>

void allocate2DArray(int ***arr, int rows, int columns) {
    // Cấp phát bộ nhớ cho mảng con trỏ
    *arr = (int**)malloc(rows * sizeof(int*));

    // Cấp phát bộ nhớ cho mỗi hàng
    for (int i = 0; i < rows; ++i) {
        (*arr)[i] = (int*)malloc(columns * sizeof(int));
    }
}

void initialize2DArray(int ***arr, int rows, int columns) {
    // Gán giá trị cho mảng 2D
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            (*arr)[i][j] = i * columns + j + 1;
        }
    }
}

void print2DArray(int **arr, int rows, int columns) {
    // In ra giá trị của mảng 2D
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

void free2DArray(int ***arr, int rows) {
    // Giải phóng bộ nhớ của mảng 2D
    for (int i = 0; i < rows; ++i) {
        free((*arr)[i]);
    }
    free(*arr);
}

int main() {
    int rows = 3, columns = 4;
    int **matrix;

    // Cấp phát bộ nhớ cho mảng 2D
    allocate2DArray(&matrix, rows, columns);

    // Khởi tạo giá trị cho mảng 2D
    initialize2DArray(&matrix, rows, columns);

    // In ra giá trị của mảng 2D
    printf("2D Array:\n");
    print2DArray(matrix, rows, columns);

    // Giải phóng bộ nhớ của mảng 2D
    free2DArray(&matrix, rows);

    return 0;
}
```


#### f. NULL pointer:
Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
Ví dụ:
```
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    return 0;
}
```
Trong ví dụ này:

Con trỏ ptr được khai báo và được gán giá trị NULL.

Một điều kiện kiểm tra xem con trỏ có trỏ đến một đối tượng nào đó hay không.

Nếu con trỏ bằng NULL, chương trình in ra "Pointer is NULL", ngược lại nếu con trỏ không bằng NULL, chương trình in ra "Pointer is not NULL".

Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.

## 2. Cách sử dụng con trỏ hàm:
Ta có các hàm như sau:
```
void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
}
```
### Cách 1: 
Khai báo con trỏ hàm và gán giá trị như con trỏ thông thường:
```
int a = 10, b = 5;
void (*ptr)(int,int);
// Tính tổng
ptr= sum;
ptr(a,b);

//Tính hiệu
ptr= subtract;
(*ptr)(a,b);

//Tính tích
ptr= multiple;
ptr(a,b);

//Tính thương
ptr= divide;
(*ptr)(a,b);
```
### Cách 2:
Sử dụng con trỏ hàm như 1 đối số truyền vào của hàm khác:
Ví dụ dưới đây ta tạo hàm caculator có tham số truyền vào là con trỏ hàm kiểu void có 2 tham số giống như các hàm tính toán phía trên.

Có nghĩa là hàm caculator sẽ nhận tham số là 1 trong 4 hàm tính toán trên:
```
void calculator(void (*ptr)(int, int), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}
```
Ta gọi hàm để tính toán như sau:
```
calculator(sum,5,2);
calculator(subtract,5,2);
calculator(multiple,5,2);
calculator(divide,5,2);
```
### Cách 3:
Ta cũng có thể tạo ra 1 mảng con trỏ hàm để trỏ tới từng địa chỉ của các hàm và sử dụng chúng như sau:
```
int a = 10, b = 5;
void (*ptr[])(int, int) = {sum, subtract, divide, multiple};
ptr[0](a,b);  // Tính tổng
ptr[1](a,b);  // Tính hiệu
ptr[2](a,b);  // Tính tích
ptr[3](a,b);  // Tính thương
```
Ngoài ra ta cũng có thể sử dụng con trỏ hàm với varadic function và struct. Chi tiết xem thêm file func_pointer.
