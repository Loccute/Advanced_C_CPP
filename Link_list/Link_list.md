# Bài 10: Linked List
## 1. Khái niệm
Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.

Có hai loại linked list chính:
- Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
- Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.

Một linked list cung cấp một cách linh hoạt để thêm, xóa và chèn các phần tử mà không cần phải di chuyển toàn bộ dãy số như mảng. Tuy nhiên, nó cũng có một số nhược điểm, như việc cần thêm một con trỏ cho mỗi nút, tăng độ phức tạp của bộ nhớ và có thể dẫn đến hiệu suất kém hơn trong một số trường hợp so với mảng.

Dưới đây là định nghĩa 1 node trong singly linked list:
```
struct Node {
    int data;         // Dữ liệu của nút
    Node* next;       // Con trỏ đến nút tiếp theo trong danh sách
};
```

Ta có định nghĩa 1 list:
```
typedef struct 
{
    Node *pHead;
    Node *pTail;
}List;
```
List chứa 2 con trỏ là pHead và pTail để trỏ đến phần tử đầu và cuối của list.

## 2. Một số thao tác trong list:
### a. Khởi tạo một node:

```
node *createNode(int value)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
```
### b. Khởi tạo 1 list:
Ta khởi tạo bằng cách gán con trỏ pHead và pTail của list là NULL.
```
void Create_list(List *L){
    L->pHead = NULL;
    L->pTail = NULL;
}
```
### c. Kiểm tra List rỗng:
Ta kiểm tra xem 1 list có rỗng không bằng cách so sánh pHead với con trỏ NULL:
```
bool isempty(List L)
{
    return L.pHead == NULL;
}
```

### d. Chèn một node vào cuối list:
Ta truyền 1 list và giá trị cần thêm vào hàm. Đầu tiên ta dùng hàm CreateNode để tạo 1 con trỏ Node p mới để chứa giá trị cần chèn. Tiếp theo ta thực hiện chèn Node vào cuối List. Ta xét trường hợp List rỗng, ta sẽ gán con trỏ pHead và pTail trỏ đến p sau đó thoát khỏi hàm. Nếu List không rỗng, ta sẽ tạo 1 con trỏ trỏ tới Node mà pHead trỏ tới và duyệt trên List cho đến Node cuối của List. Sau đó ta cho con trỏ pNext của Node cuối trỏ tới Node p và con trỏ pTail trỏ tới Node p.  
```
void pushback(List *L, int data){
    Node *p = CreateNode(data);
    if (isempty(*L)) {
        L->pHead = p;
        L->pTail = p;
        return;
    }
    Node *q = L->pHead;
    while(q->pNext != NULL) q = q->pNext;
    q->pNext = p;
    L->pTail = p;
}
```

### e. Chèn 1 node vào đầu list:
Ta truyền 1 list và giá trị cần thêm vào hàm. Đầu tiên ta dùng hàm CreateNode để tạo 1 con trỏ Node p mới để chứa giá trị cần chèn. Tiếp theo ta thực hiện chèn Node vào đầu List. Ta xét trường hợp List rỗng, ta sẽ gán con trỏ pHead và pTail trỏ đến p sau đó thoát khỏi hàm. Nếu List không rỗng, ta cho con trỏ pNext của p trỏ tới Node mà con trỏ pHead của List trỏ tới. Sau đó ta cho con trỏ pHead trỏ tới p.
```
void pushfront(List *L, int data){
    Node *p = CreateNode(data);
    if (isempty(*L)) {
        L->pHead = p;
        L->pTail = p;
        return;
    }
    p->pNext = L->pHead;
    L->pHead = p;
}
```

### f. Thêm phần tử vào 1 vị trí bất kì trong list:
Ta truyền 1 list, giá trị cần thêm, và vị trí để thêm phần tử vào hàm. Đầu tiên ta dùng hàm CreateNode để tạo 1 con trỏ Node p mới để chứa giá trị cần chèn. Ta khởi tạo 1 biến k = 0 để chỉ phần tử đầu tiên của List và con trỏ  q = L->pHead để biểu diễn phần tử đầu tiên của List. Ta duyệt qua lần lượt các phần tử trong List và đồng thời tăng k lên 1. Ta lặp lại đến khi k = pos - 1 chỉ phần tử liền trước cần chèn hoặc duyệt đến cuối List. Tiếp theo ta kiểm tra xem nếu duyệt đến cuối danh sách thì ta gán pTail = p (giống như chèn Node vào cuối danh sách). Nếu đến đúng vị trí cần chèn, ta gán pNext của p cho pNext của q (trỏ đến phần tử thứ pos của List). Cuối cùng, ta lấy pNext của q gán cho p để chèn hoàn tất.

```
void insert(List *L, int data, int pos){
    Node *p = CreateNode(data);
    int k = 0;
    Node *q = L->pHead;
    while((q->pNext != NULL) && (k != pos - 1)){
        k++;
        q = q->pNext;
    }
    if (q->pNext != NULL) p->pNext = q->pNext;
    else L->pTail = p;
    q->pNext = p;
}
```

### g. Xóa node cuối cùng của list:
Đầu tiên ta kiểm tra xem List có rỗng không, nếu có, ta in ra "List is empty!" rồi thoát khỏi hàm. Nếu List chỉ có 1 phần tử, ta xóa phần tử đó và gán pHead và pTail của List với con trỏ NULL. Nếu List có từ 2 phần tử trở lên, ta sẽ duyệt lần lượt các phần tử trong list. Ta khởi tạo con trỏ p = L->pHead để duyệt qua các phần tử, con trỏ q = NULL để lưu lại vị trí ngay phía trước sau khi con trỏ p duyệt qua. Ta dùng while lặp cho đến khi con trỏ p trỏ tới Node cuối trong List, khi đó q trỏ tới Node ngay phía trước Node cuối. Ta thực hiện gán con trỏ pNext của q là NULL và gán pHead = q (q lúc này là con trỏ trỏ đến Node cuối trong List). Sau đó ta thực hiện xóa Node mà p trỏ tới. 

```
void popback(List *L){
    if (isempty(*L)) {
        printf("List is empty!\n");
        return;
    }
    if (L->pHead == L->pTail){
        L->pTail = NULL;
        free(L->pHead);
        L->pHead = NULL;
        return;
    }
    Node *p = L->pHead;
    Node *q = NULL;
    while(p->pNext != NULL)
    {
        q = p;
        p = p->pNext;
    }
    q->pNext = NULL;
    L->pTail = q;
    free(p);
    p = NULL;
}
```
### h. Xóa Node đầu tiên của List:
Đầu tiên ta kiểm tra xem List có rỗng không, nếu có, ta in ra "List is empty!" rồi thoát khỏi hàm. Nếu không, ta tạo Node p = L->phead là con trỏ đến Node đầu tiên của List.
Ta cần pHead trỏ đến Node thứ 2 của List nên pHead = p->pNext. Nếu List chỉ có 1 phần tử, ta gán L->pTail = NULL. Tiếp đó, ta thực hiện xóa Node p trỏ tới.


```
void popfront(List *L){
    if (isempty(*L)) {
        printf("List is empty!\n");
        return;
    }
    Node *p = L->pHead;
    if (p == L->pTail) L->pTail = NULL;
    L->pHead = p->pNext;
    p->pNext = NULL;
    free(p);
    p = NULL;
}
```
### i. Xóa 1 Node ở vị trí bất kì:
Đầu tiên ta kiểm tra xem List có rỗng không, nếu có, ta in ra "List is empty!" rồi thoát khỏi hàm. Nếu không, ta khởi tạo 1 biến k = 0 để chỉ phần tử đầu tiên của List và con trỏ p = L->pHead để biểu diễn phần tử đầu tiên của List. Ta duyệt qua lần lượt các phần tử trong List và đồng thời tăng k lên 1. Ta lặp lại đến khi k = pos - 1 chỉ phần tử liền trước cần xóa hoặc duyệt đến cuối List. Nếu ta duyệt đến cuối danh sách mà k vẫn không bằng pos - 1 thì in ra "Don't find the position need to delete!" rồi thoát khỏi hàm. Nếu không, ta tạo con trỏ p = p->pNext trỏ tới Node cần xóa. Sau đó thực hiện xóa Node tương tự như hai hàm xóa bên trên.

```
void delete_Node(List *L, int pos){
    if (isempty(*L)) {
        printf("List is empty!\n");
        return;
    }
    int k = 0;
    Node *p = L->pHead;
    while((p->pNext != NULL) && (k != pos - 1)) {
        p = p->pNext;
        k++;
    }
    if (k != pos - 1) {
        printf("Don't find the position need to delete!\n");
        return;
    }

    Node *q = p->pNext;
    p->pNext = q->pNext;
    if (L->pTail == q) L->pTail = p;
    q->pNext = NULL;
    free(q);
    q = NULL;
}
```
### j. Lấy giá trị phần tử đầu danh sách:
Ta chỉ cần trả về data của Node mà pHead của List trỏ tới.
```
int front(List L){
    return L.pHead->data;
}
```
### k. Lấy giá trị phần tử cuối danh sách:
Ta chỉ cần trả về data của Node mà pTail của List trỏ tới.
```
int back(List L){
    return L.pTail->data;
}
```

### l. Tính số lượng phần tử trong List:
Ta khởi tạo 1 con trỏ p = L.pHead để duyệt lần lượt qua các Node của List. Ta khởi tạo biến đếm size = 1 vì ban đầu p đã trỏ tới Node đầu tiên của List. Ta tiến hành duyệt qua các Node của List, mỗi lần duyệt thì size sẽ tăng lên 1. Cuối cùng, ta trả về biến size lưu số lượng phần tử của List.

```
int size(List L){
    Node *p = L.pHead;
    int size = 1;
    while(p->pNext != NULL){
        size++;
        p = p->pNext;
    }
    return size;
}
```

### m. Lấy giá trị của Node bất kì trong List:
Ta khởi tạo biến đếm k = 0 và con trỏ p = L.pHead để duyệt qua các phần tử trong List. Mỗi lần duyệt qua 1 phần tử, biến k tăng lên 1 đơn vị. Ta duyệt đến cuối danh sách hoặc khi k = pos. Nếu duyệt đến cuối danh sách mà không tìm thấy phần tử thứ pos, ta sẽ trả về mã lỗi ERROR_GET (được define là -999). Nếu tìm thấy, ta trả về giá trị data đang lưu ở Node đó.

```
int get(List L, int pos){
    int k = 0;
    Node *p = L.pHead;
    while ((p->pNext != NULL) && (k != pos)){
        k++;
        p = p->pNext;
    }
    if (k != pos) return ERROR_GET; // -999
    return p->data;
}
```

### n. In các phần tử trong List:
Ta duyệt và in lần lượt các phần tử trong List theo thứ tự.

```
void display(List L){
    Node *p = L.pHead;
    int i = 0;
    while(p != NULL){
        printf("Value of Node %d: %d\n", i, p->data);
        p = p->pNext;
        i++;
    }
}
```

### o. Xóa danh sách:
Đầu tiên ta kiểm tra xem List có rỗng không, nếu có, ta thoát khỏi hàm. Nếu không, ta thực hiện xóa List. Đầu tiên ta tạo con trỏ p = L->pHead để duyệt qua các phần tử của List, sau đó, ta gán 2 con trỏ pHead và pTail bằng NULL. Sau đó ta duyệt qua các phần tử của List cho đến khi p = NULL. Mỗi lần duyệt qua 1 phần tử, ta tạo con trỏ q để lưu vị trí con trỏ p trỏ tới và thực hiện xóa con trỏ q đó. Cuối cùng, ta đã xóa thành công List đó. 

```
void free_list(List *L){
    if (isempty(*L)) return;
    Node *p = L->pHead;
    L->pTail = NULL;
    L->pHead = NULL;
    while(p != NULL){
        Node *q = p;
        p = q->pNext;
        // free(q)
        q->pNext = NULL;
        free(q);
        q = NULL;
    }
}
```
