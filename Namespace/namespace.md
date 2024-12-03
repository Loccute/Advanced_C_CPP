# Bài 17: Namespace
## 1. Khái niệm
Namespace là một phương thức giúp nhóm các định danh như tên biến, hàm, class, ... vào 1 không gian riêng tách biệt.

Namespace được sử dụng để tránh xung đột tên khi có các định danh giống nhau được khai báo trong các phần của chương trình hoặc các thư viện khác nhau.

Cú pháp chung:
```
namespace <tên của namespace>{
    // khai báo và định nghĩa các thành phần
    // biến
    // hàm
    // class. struct
}
```

Ví dụ:
```
#include <iostream>
#include <string.h>
using namespace std;

namespace A{
    string name = "Trung 20";

    void display(){
        cout << "Name: " << name << endl;
    }
}

namespace B{
    string name = "Trung 21";

    void display(){
        cout << "Name: " << name << endl;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;    // dùng toán tử phạm vi "::" để truy cập vào các thành phần trong namespace.
    cout << "Name: " << B::name << endl;

    A::display();
    B::display();
    return 0;
}
```

## 2. Từ khóa using trong namespace
Từ khóa using cho phép bạn sử dụng các phần tử trong namespace mà không cần phải sử dụng toán tử '::' mỗi khi truy cập.
Chỉ sử dụng using namespace khi member muốn truy cập đến là duy nhất.

Ví dụ:
```
#include <iostream>
#include <string.h>
using namespace std;

namespace A{
     string name = "Trung 20";
}

namespace B{
     string name = "Trung 21";
}

using namespace A;

// using namespace B; // error: tham chiếu không rõ ràng

int main(int argc, char const *argv[])
{
    cout << "Name: " << name << endl;
    cout << "Name: " << B::name << endl;
    return 0;
}
```

## 3. Namespace lồng nhau
C++ cho phép tạo các namespace lồng nhau, nghĩa là một namespace có thể chứa một namespace khác bên trong nó.

Ví dụ:
```
#include <iostream>
#include <string.h>

using namespace std;

namespace A{
    string name = "Trung 20";

    namespace C{
        string str = "Nguyen Hoang";
    }
}

namespace B{
    string name = "Trung 21";
}

using namespace A::C;

int main(int argc, char const *argv[])
{
    cout << "Name: " << A::name << endl;
    cout << "Name: " << B::name << endl;
    cout << "Name: " << A::C::str << endl;

    str = "Hello World";
    cout << "Name: " << str << endl;
    return 0;
}
```

## 4. Namespace mở rộng
Namespace có thể được mở rộng bằng cách khai báo nhiều lần cùng một tên namespace trong các phần khác nhau của chương trình. Các khai báo này sẽ được ghép lại thành một namespace duy nhất.

Ví dụ: khi ta include 2 thư viện ở 2 file .hpp khác nhau để sử dụng, trong 2 thư viện đó sử dụng cùng 1 namespace thì khi include vào 1 file .cpp, namespace ở 2 file thư viện sẽ tự động được gộp lại và mở rộng trở thành 1 namespace chung duy nhất.

File lcd1.hpp
```
#ifndef _LCD1_HPP
#define _LCD1_HPP

namespace LCD{
    int temp;
    class lcd{
        public:
            lcd(/* args */);
            ~lcd();
    };

    lcd::lcd(){}
    lcd::~lcd(){}
}

#endif
```

File lcd2.hpp
```
#ifndef _LCD2_HPP
#define _LCD2_HPP

namespace LCD{
    char *text;
}

#endif
```

Khi gộp lại sẽ thành 1 namespace duy nhất:
```
namespace LCD{
    int temp;
    char *text;
    class lcd{
        public:
            lcd(/* args */);
            ~lcd();
    };

    lcd::lcd(){}
    lcd::~lcd(){}
}
```

## 5. Namespace tiêu chuẩn của C++ (std)
Một trong những namespace quan trọng và phổ biến nhất trong C++ là std. Tất cả các thành phần của thư viện chuẩn C++ (như cout, cin, vector, string) đều được định nghĩa bên trong namespace std.

Namespace std đã được tạo sẵn trong C++, nhưng chúng ta có thể mở rộng thêm namespace này thêm các kiểu dữ liệu và các hàm tự định nghĩa bằng cách khai báo namespace có cùng tên là std và tạo các kiểu dữ liệu và hàm tự định nghĩa. Cách mở rộng tương tự tương tự như cách mở rộng các namespace thông thường.

Ví dụ:
```
#include <iostream>

using namespace std;

namespace std{
    struct{
        int x;
        int y;
    } point;

    void display(){
        cout << "x = " << point.x << endl;
        cout << "y = " << point.y << endl;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << "Hello world!" << std::endl;

    cout << "Hello world!" << endl;
   
    std::point.x = 10;
    std::point.y = 20;
    std::display();

    return 0;
}
```

