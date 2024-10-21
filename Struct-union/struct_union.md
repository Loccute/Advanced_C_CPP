# Bài 7: Struct - Union
## 1. Struct
### a. Định nghĩa:
Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.
Cú pháp:
```
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```

Ví dụ:
```
struct Point {
    int x;
    int y;
};
```

Thành Viên (Member): Mỗi biến trong struct được gọi là một thành viên hoặc trường. Trong ví dụ struct Point, x và y là các thành viên của Point.
Khởi Tạo và Truy Cập Thành Viên: Để khởi tạo một biến thuộc kiểu struct, bạn sử dụng cú pháp như sau:
```
struct Point p1 = {10, 20};
```

Để truy cập các thành viên, bạn cần sử dụng toán tử ( . ):
```
printf("X coordinate: %d\n", p1.x);
```

Sử Dụng Tham Số Trong Hàm: Bạn có thể truyền một biến thuộc kiểu struct như một tham số cho một hàm.
```
void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}
```

Truyền Con Trỏ đến Struct:
Bạn có thể truyền con trỏ đến struct như một tham số cho một hàm, cho phép thay đổi giá trị của struct bên trong hàm.
```
void updatePoint(struct Point* p, int newX, int newY) {
    p->x = newX;
    p->y = newY;
}
```

Sử Dụng typedef để Tạo Bí Danh:
Bạn có thể sử dụng typedef để tạo bí danh cho struct, giúp rút ngắn cú pháp khi khai báo biến.
```
typedef struct Point {
    int x;
    int y;
} Point;
```

Sau đó, bạn có thể khai báo biến như sau:
```
Point p1 = {10, 20};
```

struct giúp tổ chức dữ liệu một cách hiệu quả và làm cho mã nguồn trở nên dễ đọc và bảo trì hơn.

### b. Kích thước của một struct:
Trước tiên ta có những khái niệm sau:
+ Data aligment: là quá trình sắp xếp các thành phần của một struct để căn chỉnh dữ liệu sao cho số byte (kiểu dữ liệu) của từng thành phần trong struct phù hợp yêu cầu của bộ nhớ lưu trữ.
+ Padding: là những byte trống được thêm vào để phù hợp với yêu cầu căn chỉnh dữ liệu. Nhờ đó các thành phần trong struct có địa chỉ phù hợp với kiểu dữ liệu của nó.
+ Số byte dữ liệu được cấp phát cho struct theo số byte được cấp phát cho phần tử có kiểu dữ liệu lớn nhất trong struct đó.

Ta có ví dụ sau:
```
typedef struct{
    uint8_t var1;
    uint32_t var2;
    uint16_t var3;
}frame;
```
Với struct frame phía trên, kiểu dữ liệu lớn nhất là uint32_t chiếm 4 byte, nên hệ điều hành sẽ cấp phát 4 byte bộ nhớ một lần. Các thành phần của struct được lưu trữ theo thứ tự được khai báo.
Ta biểu diễn dữ liệu của struct trên theo hình sau đây:

![image](https://github.com/user-attachments/assets/034fd6ea-aa20-40f9-bac4-1200b1812acd)

Biến var1 kiểu uint8_t có kích thước 1 byte nên được lưu ở byte đầu tiên dòng đầu trong 4 byte được cấp phát. Còn dư 3 byte ta thêm vào 3 padding.

Biến var2 kiểu uint32_t có kích thước 4 byte nên được lưu ở là 4 byte dòng tiếp theo vì 3 byte dòng đầu còn dư sau khi lưu biến var1 không đủ chỗ.

Biến var3 kiểu uint16_t có kích thước 2 byte nên được lưu ở 2 byte dòng tiếp theo. Còn dư 2 byte ta thêm vào 2 padding.

Do đó struct ở trên chiếm tổng cộng: 1 + 3 + 4 + 2 + 2 = 12 byte.

Nếu ta thay đổi struct trên 1 chút bằng cách đảo biến var3 lên khai báo trước biến var2 như sau:
```
typedef struct{
    uint8_t var1;
    uint16_t var3;
    uint32_t var2;
}frame;
```
Thì dữ liệu của struct được lưu như sau:

![image](https://github.com/user-attachments/assets/3e749657-77fa-4c78-b2b4-cfbab5b4357b)

Như ta thấy, biến var1 vẫn được lưu ở byte nhớ đầu tiên. Nhưng tiếp theo bến var3 được lưu theo thứ tự khai báo trong struct. Vì biến var3 là kiểu uint16_t nên chỉ chiếm 2 byte và sau khi lưu var1 thì vẫn còn 3 chỗ trống nên ta lưu biến var3 ở 2 byte kế tiếp biến var1. Còn dư 1 byte ta thêm vào 1 padding.

Biến var2 kiểu uint32_t có kích thước 4 byte nên được lưu ở là 4 byte dòng tiếp theo vì 1 byte dòng đầu còn dư sau khi lưu biến var1 và var3 không đủ chỗ.

Do đó struct ở trên chiếm tổng cộng: 1 + 2 + 1 + 4 = 8 byte.

Qua 2 ví dụ, ta thấy nên khai báo các phần tử có kiểu dữ liệu từ thấp đến cao theo thứ tự để tiết kiệm bộ nhớ.


## 2. Union
### a. Định nghĩa:
Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào một cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng.

Cú pháp định nghĩa union trong C như sau:
```
union TenUnion {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```

Ví dụ:
```
union Data {
    int i;
    float f;
    char str[20];
};
```

Trong đoạn mã trên, union Data định nghĩa một kiểu dữ liệu mới có ba thành viên là i (kiểu int), f (kiểu float), và str (mảng kiểu char).
Các khái niệm chính của union trong C bao gồm:
+ Tiết kiệm bộ nhớ: union tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên. Kích thước của union là kích thước của thành viên lớn nhất.
+ Truy cập thành viên: Bạn truy cập các thành viên của union bằng cách sử dụng toán tử . như struct.
```
union Data data;
data.i = 10;
printf("Value of i: %d\n", data.i);
```

+ Sử dụng trong các tình huống đặc biệt: union thường được sử dụng khi bạn có một biến có thể chứa một trong các kiểu dữ liệu khác nhau và bạn chỉ cần sử dụng một kiểu dữ liệu tại một thời điểm.
```
union Value {
    int intValue;
    float floatValue;
    char stringValue[20];
};
```

+ Biểu diễn dữ liệu tương đồng: Khi bạn có các dữ liệu có ý nghĩa tương đồng nhưng có kiểu dữ liệu khác nhau, union giúp bạn biểu diễn chúng một cách hiệu quả.
```
union Measurement {
    int height;
    float depth;
    double distance;
};
```

+ Lưu trữ dữ liệu tạm thời: union có thể được sử dụng để lưu trữ dữ liệu tạm thời khi bạn cần một biến có thể chứa một trong các kiểu dữ liệu khác nhau tùy thuộc vào tình huống.
```
union TemporaryData {
    int intValue;
    float floatValue;
    char stringValue[20];
};
```
### b. Kích thước của 1 Union:
Vì union dùng chung vùng nhớ giữa các phần tử được khai báo bên trong nó nên kích thước của Union là kích thước của (kiểu dữ liệu lớn nhất + padding).

Dữ liệu được cấp phát (frame dữ liệu) vẫn dựa trên frame của kiểu dữ liệu lớn nhất được khai báo trong union.

Ta có ví dụ minh họa như sau:
```
typedef union{
    uint8_t var1;    // 1 byte + 3 padding
    uint32_t var2;   // 4 byte
    uint16_t var3;   // 2 byte + 2 padding
}frame;
```
Do đó kích thước của struct này là 4 byte

Ta có ví dụ thứ 2:
```
typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;
```
Trong ví dụ này, struct data trong union Data_Frame này chiếm 8 byte vừa hay cũng bằng với thành phần mảng frame còn lại nên kích thước union này là 8 byte.

Đây là ví dụ ứng dụng cho việc thành lập 1 data frame để truyền dữ liệu. Đó là 1 mảng frame 8 byte bao gồm 2 byte đầu là id, 4 byte tiếp theo là data và 2 byte cuối là check_sum dùng đề kiểm tra xem gói tin có nhận đúng không.

Cái này thường ứng dụng để thiết kế gói tin cho truyền thông mạng hay truyền thông giữa 2 con MCU khác nhau. Ta có hình minh họa:

![image](https://github.com/user-attachments/assets/a2399352-9b7f-4635-9274-7f530d306eee)

Khi thay đổi 1 phần tử trong union thì các phần tử khác cũng sẽ thay đổi theo vì chúng dùng chung vùng nhớ:

```
typedef union{
    uint8_t var1;
    uint32_t var2;
    uint16_t var3;
}frame;

int main(){
    frame data;
    data.var1 = 5;
    data.var2 = 6;
    data.var3 = 50;
    printf("var1 = %d\n", data.var1);
    printf("var2 = %d\n", data.var2);
    printf("var3 = %d\n", data.var3);
}
```

Output:
var1 = 50
var2 = 50
var3 = 50

Giải thích: đầu tiên ta gán data.var1 = 5 thì vùng địa chỉ chung của 3 biến sẽ lưu giá trị 5. Sau đó ta gán data.var2 = 6, ghi đè lên giá trị 5. Sau đó ta gán data.var3 = 50, ghi đè lên giá trị 6. Do đó var1, var2, var3 có chung giá trị là 50.
