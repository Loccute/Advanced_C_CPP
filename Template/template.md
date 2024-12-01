# Bài  16: Template
## 1. Định nghĩa:
Trong C++, function templates là một tính năng mạnh mẽ giúp viết các function hoặc class chung có thể được sử dụng
cho nhiều kiểu dữ liệu khác nhau mà không cần phải triển khai nhiều phiên bản của cùng một function hoặc class.

## 2. Cú pháp chung
- Đối với function template:
  ```
  template <typename T1, typename T2, ...>
  <Kiểu trả về> <Tên hàm> (<Danh sách tham số>){
    // Nội dung của hàm
    return <giá trị trả về>;
  }
  ```
  Ví dụ:
  ```
  #include <iostream>
  using namespace std;
  
  template<typename T1, typename T2>
  auto sum(T1 a, T2 b)
  {
      return a + b;
  }

  int main(){
    cout << "Sum: " << sum(1, 5) << endl;      // Tự động suy luận T1, T2, kiểu trả về là kiểu int
    cout << "Sum: " << sum(1.5, 5.6) << endl;  // Tự động suy luận T1, T2, kiểu trả về là kiểu double
    cout << "Sum: " << sum(1, 5.6) << endl;    // Tự động suy luận T1 là kiểu int, T2 là kiểu double, kiểu trả về là double
  }
  ```
- Đối với class template:
  ```
  template <typename T1, typename T2, ...>
  class <Tên class>{
    private:
      T1 a;
      T2 b;
      // ...
    public:
      // Các hàm thành viên trong class
  }
  ```
  Ví dụ:
  ```
  #include <iostream>
  using namespace std;
  
  template<typename T1, typename T2>
  class Sensor{
      private:
          T1 value;
          T2 value1;
      public:
          Sensor(T1 init1, T2 init2): value(init1), value1(init2){}
          T1 getvalue1() const{
              return value;
          }
  
          T2 getvalue2() const{
              return value1;
          }
          void setvalue1(const T1& newValue){
              value = newValue;
          }
          void setvalue2(const T2& newValue){
              value1 = newValue;
          }
          void display(){
              cout << "Gía trị cảm biến: " << getvalue1() << endl;
              cout << "Gía trị cảm biến: " << getvalue2() << endl;
          }
  };
  
  int main(){
      Sensor<double, double> tempSensor(25.7, 30);      // Khai báo đối tượng thuộc class Sensor, với kiểu dữ liệu truyền vào là T1, T2: double
      tempSensor.display();
  
      Sensor<int, int> lightSensor(120, 256);           // Khai báo đối tượng thuộc class Sensor, với kiểu dữ liệu truyền vào là T1, T2: int
      lightSensor.display();
  
      Sensor<string, float> stateSensor("OFF", 3.14);   // Khai báo đối tượng thuộc class Sensor, với kiểu dữ liệu truyền vào là T1: string, T2: float
      stateSensor.display();
      return 0;
  }
  ```

- Lưu ý:
  + Nên định nghĩa số lượng kiểu dữ liệu của template bằng số lượng tham số truyền vào hàm.
  + Ngoài việc sử dụng từ khóa **typename** để định nghĩa kiểu dữ liệu trừu tượng, ta có thể sử dụng các kiểu dữ liệu tường minh như: int, double, float, char, string, ... tại phần khai báo template.
  Khi đó khi khai báo đối tượng của class template ở bất kì hàm nào, thay vì truyền kiểu dữ liệu do dùng từ khóa **typename**, ta có thể truyền trực tiếp giá trị vào.
  Ví dụ:
  ```
  
  ```

## 3. Một số kỹ thuật sử dụng template nâng cao:
### 3.1 Metaprogramming
Mục đích: Dùng để tính toán giai thừa tại thời điểm biên dịch.
```
#include <iostream>
using namespace std;

template <unsigned int n>
struct Factorial {
    enum 
    { 
        value = n * Factorial<n - 1>::value 
    };
};

template <>
struct Factorial<0> {
    enum { 
        value = 1 
    };
};

int main() {
    cout << "Factorial of 5 is " << Factorial<5>::value << endl;
    return 0;
}
```
### 3.1 Expression Templates
Thực hiện một phép cộng đơn giản giữa 2 số nguyên:
```
#include <iostream>

using namespace std;

template <typename A, typename B>
class AddExpr {
private:
	const A& a;
	const B& b;

public:
	AddExpr(const A& a, const B& b) : a(a), b(b) {}

	
	int eval() const {
		return a + b;
	}
};


template <typename A, typename B>
AddExpr<A, B> add(const A& a, const B& b) {
	return AddExpr<A, B>(a, b);
}

int main() {
	int x = 5,	y = 3;

	auto expr = add(x, y);

	cout << "Result: " << expr.eval() << endl; // Output: 8

	return 0;
}
```
### 3.2 Variadic Templates
Mục đích: Tạo một hàm có thể chấp nhận số lượng tham số đầu vào không xác định.
```
#include <iostream>

using namespace std;

void print1()
{
    cout << endl;
}

template<typename T, typename... Rest>
void print1(T first, Rest... rest) {
    cout << first << endl;
    print1(rest...);
}


template <typename... Args>
void print(Args... args) {
  (cout << ... << args) << '\n';
}

int main() {
  print1(1, 2, 3, "hello", 4.5, "Trung", 55);
  print(1, 2, 3, "hello", 4.5, "Trung", 55);
  return 0;
}
```
  
