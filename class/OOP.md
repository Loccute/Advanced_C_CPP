# Bài 14: OOP
## 1. Tính đóng gói (Encapsulation):
Tính đóng gói (Encapsulation) là ẩn đi các property “mật” khỏi người dùng. Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private (tức là không thể truy cập trực tiếp tới các property này thông qua object). 

Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta sẽ truy cập gián tiếp thông qua các method ở quyền truy cập public.

Có 2 loại method dùng để truy cập đến các property ở phạm vi private:
+ method setter: dùng để thiết lập giá trị cho các property.
+ method getter: để đọc giá trị của các property.

Ví dụ:
```
class SinhVien{
    private:
        string name;
        int id;
   
    public:
        SinhVien(){
            static int ID = 1; // dùng method static để ID tự động tăng mỗi khi tạo 1 đối tượng mới.
            id = ID;
            ID++;
        }

        void setName(string newName){   // setter method
            // kiểm tra điều kiện
            name = newName;
        }

        string getName(){   // getter method
            return name;
        }

        int getID(){
            return id;
        }

        void display(){
            cout << "Ten: " << getName() << endl;
            cout << "ID: " << getID() << endl;
        }
};
```

## 2. Tính kế thừa (Inheritance):
Tính kế thừa (Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác. Ta chia chúng làm 2 loại là class cha và class con. Để kế thừa từ class khác, ta dùng ký tự ":".

Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.

Các method của lớp cha có thể được ghi đè (override) bằng các method của lớp con khi các method trùng tên. Khi 1 đối tượng thuộc lớp con gọi 1 method có trong lớp con nhưng trùng với method trong lớp cha, method trong lớp con sẽ được chạy.

### a. Kế thừa public:
Các member public của class cha vẫn sẽ là public trong class con.

Các member protected của class cha vẫn sẽ là protected trong class con.

Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha

Ví dụ:
```
class DoiTuong{
    // private:
    //    string ten;
    //    int id;

    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1; // dùng method static để ID tự động tăng mỗi khi tạo 1 đối tượng mới.
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};
```

### b. Kế thừa protected:
Các member public, protected của class cha sẽ là protected trong class con. (Những gì kế thừa được được chuyển sang phạm vi protected trong class con)

Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.

Ví dụ:
```
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : protected DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void setNameSV(string _ten){
            ten = _ten;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};
```

### c. Kế thừa private:
Các member public, protected của class cha sẽ trở thành private trong class con. (Những gì kế thừa được được chuyển sang phạm vi private trong class con)

Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha.

Ví dụ:
```
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : private DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void setNameSV(string _ten){
            ten = _ten;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};
```

## 3. Tính trừu tượng:
Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó bằng cách thiết lập phạm vi truy cập là **private**.

Ví dụ:
```
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class GiaiPhuongTrinh{
    private:	// a,b,c,x1,x2,delta: tính đóng gói
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;
        void tinhNghiem(){	// tính trừu tượng
            delta = b*b - 4*a*c;
            if (delta < 0){
                delta = -1;
            }
            else if (delta == 0){
                x1 = x2 = -b/ (2*a);
            }
            else if (delta > 0){
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);
            }
        }
       
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();

};

void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c){
    a = num_a;
    b = num_b;
    c = num_c;
}

void GiaiPhuongTrinh::printResult(){
    tinhNghiem();
    if (delta == -1){
        cout << "PT vo nghiem" << endl;
    }
    else if (delta == 0){
        cout << "PT co nghiem chung: " << x1 << endl;
    }
    else if (delta > 0){
        cout << "PT co 2 nghiem: \n";
        cout << "x1: " << x1 << endl;
        cout << "x2: " << x2 << endl;
    }
}
int main()
{
  GiaiPhuongTrinh phuongtrinh1;
  phuongtrinh1.enterNumber(1,5,4);
  phuongtrinh1.printResult();
  return 0;
}
```

## 4. Tính đa hình:
Tính đa hình ( Polymorphism) có nghĩa là "nhiều dạng" và nó xảy ra khi chúng ta có nhiều class có liên quan với nhau thông qua tính kế thừa.

Function overloading cung cấp nhiều định nghĩa cho 1 function bằng cách thay đổi số lượng input parameter, kiểu dữ liệu của input parameter.

Tính đa hình có thể được chia thành hai loại chính:
+ Đa hình tại thời điểm biên dịch (Compile-time Polymorphism).
+ Đa hình tại thời điểm chạy (Run-time Polymorphism).

### 4.1. Đa hình tại thời điểm biên dịch (Compile-time Polymorphism)
#### 4.1.1 Nạp chồng hàm (Function overloading)
Ta khai báo các hàm có tên giống nhau nhưng khác danh sách tham số (có thể là số lượng tham số hoặc kiểu dữ liệu của từng tham số trong danh sách).

Khi gọi 1 hàm có cùng tên với ít nhất 1 hàm khác, nớ sẽ so sánh danh sách tham số truyền vào để gọi hàm tương ứng theo thứ tự ưu tiên như sau: Số lượng tham số --> kiểu tham số từ trái qua.
Nếu kiểu tham số không tương thích, trình biên dịch sẽ tự động ép kiểu để tương thích.

Ví dụ khi ép kiểu từ double --> int thì sẽ bỏ đi phần thập phân; còn từ int --> double thì thêm phần thập phân bằng 0.

Ví dụ:
```
#include <iostream>
#include <string>

using namespace std;

// 1 method có thể có nhiều input parameter, return type khác nhau
class TinhToan{
    private:
        int a;
        int b;
    public:
        int tong(int a, int b){
            return a+b;
        }
        double tong(int a, int b, int c, double d){
            return (double)a+b+c+d;
        }
        double tong(int a, double b){
            return (double)a+b;
        }
};

int main(int argc, char const *argv[]){

    TinhToan th, th1, th2, th3;
    cout << th.tong(2, 5) << endl;            // gọi hàm tong(int a, int b) --> kq = 7
    cout << th1.tong(2, 5, 7, 6.7) << endl;   // gọi hàm tong(int a, int b, int c, double d) --> kq = 20.7
    cout << th2.tong(2, 3.5) << endl;         // gọi hàm (int a, double b) --> kq = 5.5
    cout << th3.tong(2.3, 3.5) << endl;       // gọi hàm tong(int a, double b) vì trong 2 hàm tổng 2 tham số thì hàm đó thích hợp nhất khi kiểu của tham số truyền vào thứ 2 là kiểu double, do đó tham số truyền vào đầu tiên sẽ bị ép kiểu thành kiểu int nên 2.3 --> 2. Do đó kq = 2 + 3.5 = 5.5.
    return 0;
}
```

#### 4.1.2 Nạp chồng toán tử (Operator overloading)
Vì ta chỉ có thể thực hiện các phép toán số học và logic trên các số có kiểu dữ liệu như int, long, short, float, double, ... nhưng kiểu tự định nghĩa class thì không thể thực hiện trực tiếp được. Do đó ta dùng nạp chồng toán tử để định nghĩa lại các phép toán đó để class có thể thực hiện được. 

Cú pháp chung:
```
<Kiểu trả về> Operator <Phép toán cần định nghĩa lại> (Tham số truyền vào) {
    // Nội dung hàm
    return <giá trị trả về>;
}
```

Ví dụ:
```
class Phanso{
    private:
        int tuso;
        int mauso;
    public:
        Phanso operator + (Phanso const &other);
};

Phanso Phanso::operator+(Phanso const &other)
{
    Phanso kq;
    kq.tuso = this->tuso * other.mauso + this->mauso * other.tuso;
    kq.mauso = this->mauso * other.mauso;
    return kq;
}
```

Lưu ý:
1. Có 4 toán tử không thể định nghĩa lại được: toán tử ".", toán tử phạm vi ":", toán tử 3 ngôi (Ví dụ: (x == 2) ? true:false) và toán tử lấy kích thước "sizeof".
2. Kiểu trả về của phương thức định nghĩa lại phép gán "=" có thể là kiểu void hoặc kiểu <class *>.
   Ví dụ:
   ```
   Phanso* Phanso::operator=(Phanso const &other)
   {
       this->tuso = other.tuso;
       this->mauso = other.mauso;
       cout << "Day la ham gan\n";
       return this;
   }

   void Phanso::operator=(Phanso const &other)
   {
       this->tuso = other.tuso;
       this->mauso = other.mauso;
       cout << "Day la ham gan\n";
   }
   ```
   
3. Để định nghĩa lại toán tử nhập xuất cho class, ta phải dùng hàm bạn (friend) và 2 luồng istream để nhập và ostream để xuất trong thư viện <iostream> với cú pháp như sau: friend <istream/ostream>& (>>/<<) (<istream& is/ostream& os>, <đối tượng cần nhập/xuất>)
   Ví dụ:
   ```
   friend ostream& operator << (ostream& os, Phanso const & T){
       os << "Tử số: "<< T.tuso << ", Mẫu số: " << T.mauso << "\n";
       return os;
   }

   friend istream& operator >> (istream& is, Phanso& T){
       is >> T.tuso >> T.mauso ;
       return is;
   }
   ```
4. Ta có thể định nghĩa nạp chồng toán tử 2 ngôi bằng hàm friend như ví dụ sau:
   ```
   friend Phanso operator + (Phanso const &a, Phanso const &b){
       Phanso kq; 
       kq.tuso = a.tuso * b.mauso + a.mauso * b.tuso;
       kq.mauso = a.mauso * b.mauso;
       cout << "Day la ham toan tu 2 ngoi\n";
       return kq;
   }
   ```
#### 4.1.3 Con trỏ this, tham chiếu và tham trị
##### a. Con trỏ this:
Là con trỏ có sẵn trong class dùng để trỏ đến đối tượng đang thao tác. Con trỏ this là hằng con trỏ, mỗi class có 1 con trỏ this khác nhau luôn trỏ về chính đối tượng của class đang thao tác, không thể thay đổi sang địa chỉ khác. Nhưng giá trị tại địa chỉ mà con trỏ trỏ tới có thể thay đổi.

Ví dụ: Đây là hàm nạp chồng toán tử * của class Phanso, trong đó ta truy xuất các thuộc tính như tuso và mauso ở trong class đó bằng con trỏ this
```
Phanso Phanso::operator*(Phanso const &other)
{
    Phanso kq;
    kq.tuso = this->tuso * other.tuso;
    kq.mauso = this->mauso * other.mauso;
    return kq;
}
```
##### b. Tham chiếu:
Tham chiếu là địa chỉ của tham số, nghĩa là ta truyền vào hàm địa chỉ nguyên gốc của tham số. Khác với tham trị, tham chiếu sử dụng địa chỉ nguyên gốc của tham số để thao tác trên hàm mà không cần cấp phát địa chỉ mới, giúp tiết kiệm bộ nhớ. Cách này tiện lợi hơn so với việc truyền vào con trỏ (cũng cần cấp phát địa chỉ trên Ram cho con trỏ).

Cách truyền tham số này có nhược điểm là khi giá trị của tham số trong hàm thay đổi, giá trị nguyên gốc cũng thay đổi theo nên có thể gây ra sai sót không mong muốn. Ta có thể khắc phục bằng cách thêm từ khóa const cho các tham số truyền vào để nó không thể bị thay đổi.

Ta cũng có thể ứng dụng vào class khi ta có thể thêm từ khóa const vào các method getter (đọc giá trị chứ không muốn thay đổi giá trị) để không thể thay đổi giá trị.

Ví dụ:
```
int tong(const int& a, const int& b){
    // Nội dung hàm
}

int main(){
    int a = 2, b = 3;
    int c = tong(&a, &b);
}
```

##### c. Tham trị:
Tham trị là giá trị của tham số, nghĩa là ta truyền vào hàm giá trị của tham số. Khi đó trong hàm, tham số này sẽ được cấp phát 1 địa chỉ ở trong Ram khác với địa chỉ nguyên gốc của tham số đó khi bắt đầu truyền vào hàm, ta copy giá trị của tham số này để lưu giá trị vào lại địa chỉ ta mới cấp phát trên Ram. Hàm sẽ thao tác với địa chỉ cấp phát trên Ram này nên nếu giá trị tham số thay đổi trong hàm cũng không ảnh hưởng đến giá trị gốc của nó.

Ví dụ:
```
int tong(int a, int b){
    // Nội dung hàm
}

int main(){
    int a = 2, b = 3;
    int c = tong(a, b);
}
```
### 4.2 Đa hình tại thời điểm chạy (Run-time Polymorphism)
#### 4.2.1 Hàm ảo
Hàm ảo là một hàm thành viên được khai báo trong class cha với từ khóa virtual.
Khi một hàm là virtual, nó có thể được ghi đè (override) trong class con để cung cấp cách triển khai riêng.

Khi gọi một hàm ảo thông qua một con trỏ hoặc tham chiếu đến lớp con, hàm sẽ được quyết định dựa trên đối tượng thực tế mà con trỏ hoặc tham chiếu đang trỏ tới chứ không dựa vào kiểu của con trỏ.

Ví dụ:
```
#include <iostream>
using namespace std;

class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        // Hàm ảo
        virtual void display(){
            // Nội dung hàm display ở class Doituong
        }
};

// class SinhVien kế thừa public class DoiTuong
class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        // ghi đè nội dung hàm display ở class cha bằng từ khóa override
        void display() override {
            // Nội dung hàm display ở class con SinhVien
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");

    DoiTuong *dt;    // con trỏ có kiểu Doituong*
    dt = &sv1;       // trỏ đến địa chỉ của đối tượng sv1 thuộc class SinhVien
    dt->display();   // Do đó sẽ gọi hàm display ở class con để ghi đè hàm display ở class cha.
}
```

#### 4.2.2 Override và tính đa hình Run-time
Override là việc ghi đè hàm ảo ở class con bằng cách định nghĩa lại nó. 
Khi một hàm ảo được ghi đè, hành vi của nó sẽ phụ thuộc vào kiểu của đối tượng thực tế, chứ không phải kiểu của con trỏ hay tham chiếu (đối tượng mà con trỏ trỏ tới hay tham chiếu tham chiếu tới).

Tính đa hình Run-time xảy ra khi quyết định gọi hàm nào (phiên bản của class cha hay class con) được đưa ra tại thời điểm chạy, không phải lúc biên dịch. Điều này giúp chương trình linh hoạt hơn, cho phép việc mở rộng chức năng mà không cần sửa đổi mã nguồn hiện tại.


#### 4.2.3 Hàm thuần ảo (Pure vitual function)
Hàm thuần ảo là một hàm ảo không có phần định nghĩa trong class cha, được khai báo với cú pháp = 0 và khiến class cha trở thành class trừu tượng, nghĩa là không thể tạo đối tượng từ class này.

Những class con kế thừa class trừu tượng bắt buộc phải định nghĩa lại hàm thuần ảo trong class trừu tượng đó.

Ví dụ:
```
class cha{
    public:
        virtual void display() = 0; // Hàm ảo thuần túy
};

class con : public cha{
    public:
        void display() override{   // Ghi đè hàm ảo thuần túy
            cout << "display from class con" << endl;
        }
};
```

#### 4.2.4 Đa kế thừa và kế thừa ảo
##### a. Đa kế thừa:
Đa kế thừa trong C++ cho phép một class kế thừa từ nhiều class khác. Đa kế thừa thường dùng để kết hợp các chức năng từ nhiều class.

Cần phải cẩn thận khi sử dụng đa kế thừa.
Khi nhiều lớp cha có các phương thức hoặc thuộc tính trùng tên, việc gọi chúng từ lớp con có thể gây ra sự nhầm lẫn.
Khi một lớp con kế thừa từ hai lớp cha, mà hai lớp cha này đều cùng kế thừa từ cùng một lớp khác. Tình huống này tạo ra cấu trúc hình thoi (diamond), do đó được gọi là vấn đề "Diamond".

Ví dụ: Class Bố và class Mẹ đều kế thừa từ class Ông. Mà class Ông có phương thức học_giỏi() --> có 1 bản sao phương thức học giỏi ở trong class Bố và 1 bản sao học giỏi ở trong class Mẹ. Khi class Con kế thừa cả 2 class Bố và Mẹ, khi muốn gọi phương thức học_giỏi() thì sẽ bị lỗi vì trình biên dịch không biết nên gọi phương thức đó kế thừa từ lớp Cha hay lớp Mẹ.
![image](https://github.com/user-attachments/assets/9ac3f5f2-0106-444f-9876-800090ba9b04)

Để khắc phục vấn đề này, ta dùng kế thừa ảo.

##### b. Kế thừa ảo:
Kế thừa ảo giúp tránh vấn đề diamond problem trong đa kế thừa.
Kế thừa ảo giúp một bản sao duy nhất của lớp cơ sở chung được kế thừa.

Nó giúp quản lý các lớp liên quan đến phần cứng và giao tiếp. Điều này giúp tránh trùng lặp tài nguyên và quản lý hiệu quả trong hệ thống nhúng.

Ví dụ 1:

```
#include <iostream>
using namespace std;

class A {
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : virtual public A{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : virtual public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;
    d.hienThiA();
    return 0;
}
```

Ngoài kế thừa ảo, ta có thể giải quyết vấn đề "Diamond" và tình huống class Con, Cha, Mẹ, Ông phía trên như sau:
Ta sử dụng lớp trừu tượng để định nghĩa interface giảm thiểu xung đột. Lúc này Ông chỉ "di chúc" lại interface của học_giỏi. Bố, Mẹ hay Con muốn học giỏi thì tự thân vận động.

Ví dụ 2:
```
class Ong {
public:
    virtual void hoc_gioi() const = 0;
};

class Bo : public Ong {
public:
    void ban_sung() {
    }
    void hoc_gioi() const override {
    	cout << "Toi hoc gioi" << endl;
    }
};

class Me: public Ong {
public:
    void boi_loi() {
    }
    void hoc_gioi() const override {
    	cout << "Toi hoc gioi" << endl;
    }
};

class Con: public Bo, public Me {
public:
    void hoc_gioi() const override {
    	cout << "Toi hoc gioi" << endl;
    }
};

int main() {
    Con c;
    c.hoc_gioi(); 
    Bo b;
    b.hoc_gioi(); 
    Me m;
    m.hoc_gioi();
    return 0;
}
```
## 5. So sánh sự khác nhau giữa tính trừu tượng và tính đóng gói:
Khác biệt rõ ràng giữa ẩn dữ liệu (đóng gói) và trừu tượng hóa dữ liệu là:
+ Trừu tượng là chỉ trích xuất thông tin có liên quan và bỏ qua các chi tiết không cần thiết. Còn đóng gói là ẩn dữ liệu khỏi các phần của chương trình.
+ Mục đích của abstraction là để che giấu sự phức tạp. Mặt khác, encapsulation là để đạt được tính đóng gói, che dấu và bảo vệ các thuộc tính của class để không bị sửa đổi bởi bên ngoài.
+ Tính trừu tượng tập trung vào hành vi có thể quan sát được của dữ liệu. Việc đóng gói tập trung vào việc hạn chế hoặc cho phép sử dụng dữ liệu trong một vùng và bảo mật dữ liệu.


