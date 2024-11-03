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
Đầu tiên ta kiểm tra xem List có rỗng không, nếu có, ta in ra "List is empty!" rồi thoát khỏi hàm.

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


