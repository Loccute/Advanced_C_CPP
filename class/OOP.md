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

### d. Đa kế thừa: 
Một class con có thể kế thừa từ 2 hoặc nhiều class cha. Nên cân nhắc việc đa kế thừa nhiều class vì có thể dễ gây xung đột phạm vi kế thừa giữa các class khác nhau.

Ví dụ: 
```
class Doituong{
    // các thuộc tính và phương thức tương ứng
};

class Sinhvien{
    // các thuộc tính và phương thức tương ứng
};

class Hocsinh : public Doituong, public Sinhvien{
    // các thuộc tính và phương thức tương ứng
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

### 4.1. Đa hình tại thời điểm biên dịch (Compile-time Polymorphism).
#### 4.1.1 Nạp chồng hàm (Function overloading)

#### 4.1.2 Nạp chồng toán tử (Operator overloading)

### b. Đa hình tại thời điểm chạy (Run-time Polymorphism).

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

    TinhToan th, th1, th2;
    cout << th.tong(2, 5) << endl;
    cout << th1.tong(2, 5, 7, 6.7) << endl;
    cout << th2.tong(2, 3.5) << endl;

    return 0;
}
```

## 5. So sánh sự khác nhau giữa tính trừu tượng và tính đóng gói:
Khác biệt rõ ràng giữa ẩn dữ liệu (đóng gói) và trừu tượng hóa dữ liệu là:
+ Trừu tượng là chỉ trích xuất thông tin có liên quan và bỏ qua các chi tiết không cần thiết. Còn đóng gói là ẩn dữ liệu khỏi các phần của chương trình.
+ Mục đích của abstraction là để che giấu sự phức tạp. Mặt khác, encapsulation là để đạt được tính đóng gói, che dấu và bảo vệ các thuộc tính của class để không bị sửa đổi bởi bên ngoài.
+ Tính trừu tượng tập trung vào hành vi có thể quan sát được của dữ liệu. Việc đóng gói tập trung vào việc hạn chế hoặc cho phép sử dụng dữ liệu trong một vùng và bảo mật dữ liệu.


