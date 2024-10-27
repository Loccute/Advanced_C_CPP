# Bài 9: JSON
## 1. Khái niệm

JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.

JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp khóa-giá trị, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.

Ví dụ:
```
{
  "name": "John Doe",
  "age": 30,
  "city": "New York",
  "isStudent": false,
  "grades": [85, 90, 78]
}
```

## 2. Định dạng của JSON
### a. Kiểu dữ liệu:
- Null (Giá trị rỗng): null

  ```null```

- Boolean (Luận lý): true hoặc false.
  ```
  true
  false
  ```
- Number (Số): Có thể là số nguyên hoặc số thập phân. Số không được bao bọc bởi dấu ngoặc.
  ```
  42
  3.14
  ```
- String (Chuỗi): Chuỗi ký tự, được bao bọc bởi dấu nháy đơn ('') hoặc dấu nháy kép ("").

  ```"Hello, World!"```

- Array (Mảng): Một danh sách các giá trị, giữa mỗi giá trị sử dụng dấu phẩy. Mảng được bao bọc bởi dấu ngoặc vuông ([]).

  ```[1, 2, 3, 4, 5]```

- Object (Đối tượng): Một tập hợp các cặp key - value, giữa mỗi cặp sử dụng dấu hai chấm (:). Đối tượng được bao bọc bởi dấu ngoặc nhọn ({}).
  ```
  {
    "name": "John",
    "age": 30,
    "city": "New York"
  }
  ```

### b. Key - Value
- Mỗi cặp key - value được phân tách bằng dấu hai chấm (:).
- Các cặp khóa-giá trị trong đối tượng được phân tách bằng dấu phẩy
  ```{ "key1": "value1", "key2": "value2" }```
### c. Dấu ngoặc
- Dấu ngoặc nhọn ({}) được sử dụng để bao bọc đối tượng.
- Dấu ngoặc vuông ([]) được sử dụng để bao bọc mảng.
### d.Dấu phẩy
- Dấu phẩy được sử dụng để phân tách giữa các thành phần trong mảng hoặc các cặp khóa-giá trị trong đối tượng.
### e. Khoảng trắng
Khoảng trắng, dấu xuống dòng và tab không ảnh hưởng đến tính chính xác của JSON và thường được sử dụng để làm cho JSON dễ đọc hơn.

***Nhận xét***: JSON không hỗ trợ cú pháp nhận xét nội dung. Bất kỳ văn bản nào sau dấu nhận xét (// hoặc /* */) không được hiểu là hợp lệ trong JSON.
