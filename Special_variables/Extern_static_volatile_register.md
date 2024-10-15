# Bài 4: Extern - Static - Volatile - Register
## 1. Extern
Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.

Ví dụ: 

File main.c
```
#include <stdio.h>

int value = 90;

extern void display();

int main()

{
	printf("hello\n");
	display();
}
```

File other.c
```
#include <stdio.h>

extern int value;
void display()
{
	printf("value: %d\n", value);
}
```

Ứng dụng:
+ Chia sẻ biến và hàm giữa các file nguồn: Extern cho phép bạn chia sẻ biến và hàm giữa nhiều file nguồn trong một chương trình.
Điều này hữu ích khi bạn muốn tách chương trình thành các phần nhỏ để quản lý dễ dàng hơn.

+ Chia sẻ biến và hàm giữa các module hoặc thư viện:
Extern có thể được sử dụng để kết nối các module hoặc thư viện trong một dự án lớn.

+ Khai báo hàm trong trường hợp định nghĩa sau:
Nếu bạn muốn sử dụng một hàm trước khi nó được định nghĩa trong mã nguồn, bạn có thể sử dụng extern để khai báo hàm.

+ Biến toàn cục giữa các tệp nguồn:
Khi có một biến toàn cục được sử dụng trong nhiều file nguồn, extern giúp các file nguồn biết về sự tồn tại của biến đó.

+ Chia sẻ hằng số giữa các file nguồn:
Nếu bạn có một hằng số được sử dụng ở nhiều nơi, bạn có thể sử dụng extern để chia sẻ giá trị của hằng số đó giữa các file nguồn.

## 2. Static
### 2.1 Static local variables
Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.

Ví dụ:
```
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}
```

Ứng dụng: Lưu trữ trạng thái giữa các lần gọi hàm: Sử dụng biến static để theo dõi trạng thái giữa các lần gọi hàm mà không cần sử dụng biến toàn cục.

### 2.2 Static global variables
Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.

Ví dụ:

File main.c
```
#include <stdio.h>

extern void display();
//extern int s_g_value;
extern int g_value;

int main()
{
	printf("hello\n");
	g_value = 40;
	
	display();

	return 0;
}
```

File other.c:
```
#include <stdio.h>

int g_value = 30;
static int s_g_value = 20;


void display()
{
	printf("static global value: %d\n", s_g_value);
	printf("global value: %d\n", g_value);
}
```

### 2.3 Static trong class

Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.

Ví dụ:
```
#include <iostream>

typedef enum
{
    red = 0,
    blue,
    green,
    purple,
    black,
    yellow
} Pen_Color;

void print_color_pen(Pen_Color color)
{
    switch (color)
    {
    case red:
        std::cout << "Red\n";
        break;
    case blue:
        std::cout << "Blue\n";
        break;
    case green:
        std::cout << "Green\n";
        break;
    
    default:
        break;
    }
}


class PEN
{
public:
    Pen_Color pen_color;
    static int pen_length;

    PEN(Pen_Color color);
    Pen_Color get_color()
    {
        return pen_color;
    }
    void set_length(int length)
    {
        pen_length = length;
    }
};

int PEN::pen_length;

PEN::PEN(Pen_Color color)
{
    pen_color = color;
    pen_length = 10;
}


int main(int argc, char const *argv[])
{
    PEN blue_pen(blue);
    PEN red_pen(red);
    PEN green_pen(green);

    blue_pen.set_length(9);

    std::cout << "Color: ";
    print_color_pen(blue_pen.get_color());
    std::cout << "Length: " << blue_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(red_pen.get_color());
    std::cout << "Length: " << red_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(green_pen.get_color());
    std::cout << "Length: " << green_pen.pen_length << '\n';

    return 0;
}
```
Trong ví dụ trên class PEN có 1 thành phần là "static int pen_length" được khai báo để lưu cố định giá trị pen_length cho tất cả các đổi tượng thuộc lớp PEN. Trong hàm khởi tạo, ta đã set pen_length = 10. Do đó khi ta khởi tạo ba đối tượng blue_pen, red_pen, green_pen, cả 3 đối tượng đều có pen_length = 10. Sau đó ta gọi hàm set_length() từ đối tượng blue_pen và set pen_length = 9. Do đó pen_length ở các đối tượng khác đều thay đổi thành 9 vì pen_length là 1 thành phần static trong class, luôn giữ nguyên 1 giá trị với mỗi đối tượng khác nhau.

Do đó kết quả output in ra pen_length của mỗi đối tượng đều là 9.

## 3. Volatile
Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

Ví dụ:
```
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
	
	while(1)
	{
		i = *((int*) 0x20000000);
		if (i > 0)
		{
			break;
		}
		
	}
	a = 200;
}
```
Ví dụ trên là chương trình để chạy vi điều khiển stm32. Biến i ta khai báo là kiểu volatile int để trình biên dịch hiểu rằng giá trị biến i có thể thay đổi bất ngờ và không báo trước từ bên ngoài chương trình, do điều kiện gì đó xảy ra ví dụ như cảm biến thay đổi giá trị, người dùng nhấn nút, ... khiến cho giá trị biến i thay đổi theo. Do đó trình biên dịch không được xóa biến i đi.

Trong ví dụ trên, biến i được cấp giá trị tại địa chỉ 0x20000000 có giá trị là 0. Nếu giá trị i thay đổi lớn hơn 0, vòng lặp sẽ kết thúc và a sẽ được gán giá trị là 200. 

## 4. Register
Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này có thể do nhiều nguyên nhân, trong đó có thể do hết tài nguyên (không còn thanh ghi để chứa giá trị).

Ví dụ:
```
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();
    register int i;

    // Đoạn mã của chương trình
    for (i = 0; i < 1000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}
```
Ta dùng từ khóa register để khai báo biến i, nên biến i được lưu trong bộ nhớ thanh ghi. Chương trình dùng để in ra thời gian thực thi vòng lặp 1000000, mỗi lần tăng i lên 1 để so sánh thời gian với biến i không khai báo register (lưu trong bộ nhớ ram) xem thử chương trình nào thực hiện thời gian ngắn nhất. 





