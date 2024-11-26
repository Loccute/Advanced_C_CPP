# Bài 13: Class
## 1. Khái niệm
Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 

## 2. Cú pháp:
```
class ClassName {
private:
    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
    // Dữ liệu thành viên, hàm thành viên, ...

protected:
    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa

public:
    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
    // Dữ liệu thành viên, hàm thành viên, ...
    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
    // ...

};
```

Các biến được khai báo trong class được gọi là các thuộc tính (property) của class, các hàm được khai báo trong class được gọi là các phương thức (method) của class.

Trong class có 3 phạm vi truy cập:
+ public: các thành phần công khai như các thuộc tính và phương thức của class được khai báo tại đây có thể truy cập cả từ nội bộ bên trong và bên ngoài của lớp.
+ private: các thuộc tính hoặc phương thức của class được khai báo ở đây chỉ có thể truy cập từ bên trong lớp. Phạm vi này giúp cho dữ liệu của lớp được bảo vệ và không bị sửa đổi từ bên ngoài lớp.
+ protected: các thuộc tính hay phương thức khai báo ở đây được bảo vệ tương tự như phạm vi private, nhưng khác phạm vi private, nó có thể truy cập được từ lớp kế thừa.

Để truy cập vào 1 thành phần trong class, ta dùng toán tử phạm vi: "::"
Ví dụ:
```
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
    void display();
};

void HinhChuNhat::display()
{
   std::cout << " Hello " << '\n';
}
int main()
{
    HinhChuNhat hinh1;
    hinh1.chieuDai = 10.0;
    hinh1.chieuRong = 5.0;

    hinh1.display();

    std::cout << "Dien tich: " << hinh1.tinhDienTich() << '\n';


    return 0;
}
```

## 3. Constructor và Destructor
Constructor trong C++ là một function sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class.

Có 5 cách khởi tạo constructor cho 1 class:

**Cách 1**: dùng constructor mặc định do trình biên dịch tự sinh ra khi biên dịch (không cần khởi tạo).

**Cách 2**: Khai báo constructor không tham số truyền vào, ta sẽ tự gán các thuộc tính với các giá trị mong muốn trực tiếp trong constructor.

VD:
```
class Hinhchunhat{
  public:
  int chieuDai;
  int chieuRong;
  Hinhchunhat(){
    chieuDai = 2;
    chieuRong = 3;
  }
};
```
**Cách 3**: Constructor với các tham số truyền vào tương ứng. Khi ta khởi tạo đối tượng ở hàm main, ta phải truyền các giá trị tham số vào tương ứng với hàm tạo.

VD:
```
class Hinhchunhat{
  public:
  int chieuDai;
  int chieuRong;
  Hinhchunhat(int dai, int rong){
    chieuDai = dai;
    chieuRong = rong;
  }
};

int main(){
  Hinhchunhat h1(5, 3); // khởi tạo đối tượng h1 với dai = 5, rong = 3
}
```

**Cách 4**: Ta cũng truyền danh sách tham số khởi tạo vào constructor như cách 3, nhưng ta khởi tạo giá trị mặc định cho các tham số ngay tại danh sách tham số cho hàm. Làm như vậy, nếu ở hàm main ta khởi tạo 1 đối tượng của class đó
, nếu ta truyền đủ tham số đầu vào thì đối tượng sẽ được khởi tạo theo như giá trị tham số truyền vào đó. Nếu không truyền tham số đầu vào hay truyền ít hơn tham số truyền vào, ta sẽ xét theo thứ tự các tham số từ đầu đến cuối,
nếu tham số nào đã được truyền giá trị vào thì ta dùng giá trị đó để khởi tạo, nếu tham số nào không có giá trị khởi tạo, ta dùng giá trị mặc định để khởi tạo.

VD:
```
class Hinhchunhat{
  public:
  int chieuDai;
  int chieuRong;
  Hinhchunhat(int dai = 5, int rong = 2){
    chieuDai = dai;
    chieuRong = rong;
  }
};

int main(){
  Hinhchunhat h1(20, 10); // TH1: truyền đủ tham số đầu vào nên hcn h1 có dai = 20, rong = 10
  Hinhchunhat h2(20);     // TH2: truyền thiếu 1 tham số đầu vào nên hcn h2 có dai = 20, rong = 2
  Hinhchunhat h3;         // TH3: không truyền tham số đầu vào nên ta dùng giá trị mặc định, hcn h3 có dai = 5, rong = 2
}
```

**Cách 5**: Ta truyền vào danh sách tham số (có thể khởi tạo giá trị hoặc không), ta không gán giá trị cho các thuộc tính trong hàm mà ta gán thông qua dấu ":". Nếu không truyền vào tham số, ta có thể gán trực tiếp giá trị cho các thuộc tính. Để dễ hình dung ta có ví dụ sau:

VD1: truyền vào danh sách tham số
```
class Hinhchunhat{
  public:
  int chieuDai;
  int chieuRong;
  Hinhchunhat(int dai = 5, int rong = 2): chieuDai(dai), chieuRong(rong){}
};
```

VD2: truyền giá trị trực tiếp
```
class Hinhchunhat{
  public:
  int chieuDai;
  int chieuRong;
  Hinhchunhat(): chieuDai(100), chieuRong(200){}
};
```


Destructor trong C++ là một function sẽ được tự động gọi khi object được giải phóng. Destructor sẽ có tên trùng với tên của class và thêm ký tự ~ ở phía trước tên. Nếu có nhiều object được khởi tạo, các object được lưu trong stack nên khi được giải phóng, object được khởi tạo sau cùng sẽ giải phóng trước vì được lưu ở đỉnh stack. 

Ví dụ:
```
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    string hinh;

    HinhChuNhat(string hinhanh){
        chieuDai = 10;
        chieuRong = 9;
        hinh = hinhanh;
    }
    ~HinhChuNhat(){
        std::cout << "Destructor: " << hinh << '\n';
    }


    // Hàm tính diện tích
    double tinhDienTich() {
        return chieuDai * chieuRong;
    }
   
};

int main()
{
    HinhChuNhat hinh1(hinh1);
    HinhChuNhat hinh2(hinh2);


    return 0;
}
// output là
// Destructor: hinh2
// Destructor: hinh1
// vì object hinh2 được khởi tạo sau nên lưu ở đỉnh stack nên được giải phóng trước, còn hinh1 được giải phóng sau
```

## 4. Biến và hàm static trong class (hay thuộc tính và phương thức static)
Khi một biến trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của biến này. Thuộc tính static của class phải được khai báo toàn cục bên ngoài class, biến này được cung cấp 1 địa chỉ cố định mà các object trong class đều dùng chung địa chỉ khi truy cập đến biến (thuộc tính) này. Nếu biến được khởi tạo thì nó lưu ở phân vùng .data, nếu biến chưa khởi tạo thì được lưu ở phân vùng .bss.

Ví dụ:
```
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    
    static int var;
};


int HinhChuNhat::var; // biến var phải được khai báo toàn cục bên ngoài class để cấp phát địa chỉ lưu biến này, biến này chưa khởi tạo nên nằm ở vùng .bss

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    cout << "address of chieu dai: " << &hinh1.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh2.chieuDai << '\n'; 
    cout << "address of chieu dai: " << &hinh3.chieuDai << '\n'; 

    cout << "address of var: " << &hinh1.var << '\n'; 
    cout << "address of var: " << &hinh2.var << '\n'; 
    cout << "address of var: " << &hinh3.var << '\n'; 


    return 0;
}
```

Static method: các phương thức trong class được khai báo static có thể được truy cập trực tiếp từ class mà không cần qua đối tượng cụ thể của class đó. Static method chỉ có thể truy cập tới static property mà không thể truy cập đến các property khác của class.

Ví dụ:
```
class HinhChuNhat {

public:
    double chieuDai;
    double chieuRong;
    
    static int var;
    static void Display(){
        cout << "This is the static method" << endl;
        var = 20;
    }
};


int HinhChuNhat::var;

int main()
{
    HinhChuNhat hinh1;
    HinhChuNhat hinh2;
    HinhChuNhat hinh3;

    Hinhchunhat::Display();


    return 0;
}
```



