# Bài 11: Stack - Queue
## 1. Stack
Stack (ngăn xếp) là một cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra. 

Các thao tác cơ bản trên stack bao gồm:
- “ push” (đẩy) để thêm một phần tử vào đỉnh của stack.
- “ pop” để xóa một phần tử ở đỉnh stack.
- “ top” để lấy giá trị của phần tử ở đỉnh stack.

Đầu tiên ta tạo 1 stack dưới dạng 1 struct như sau:
```
typedef struct{
    int* items;
    int size;
    int top;
} Stack;
```
Trong đó, con trỏ "items" dùng để lưu các phần tử của stack (kiểu int). Biến "size" dùng để lưu kích thước của stack và biến "top" dùng để lưu vị trí ở đỉnh của stack.

Để thao tác với stack, trước tiên ta cần khởi tạo stack bằng hàm "initialize", truyền vào địa chỉ của 1 stack đã được khai báo trước đó cùng với kích thước khởi tạo.
Ta cấp phát động bộ nhớ cho con trỏ items với kích thước bằng với kích thước khởi tạo "size". Ta khởi tạo top là -1 vì ban đầu stack chưa có phần tử.

```
void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}
```
Để push 1 phần tử vào stack, đầu tiên ta cần kiểm tra stack có đầy hay không bằng hàm "is_full", nếu stack đầy thì ta in ra màn hình "Stack overflow" và kết thúc hàm. Nếu stack vẫn còn chỗ trống, ta tăng vị trí đỉnh lên 1 đơn vị rồi thêm giá trị vào đỉnh của stack.

```
void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}
```
Để kiểm tra xem stack có đầy hay không, ta dùng hàm is_full(stack). Hàm này kiểm tra xem "top" của "stack" có bằng size không.
```
int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}
```

Để xóa 1 phần tử ở đỉnh stack, ta dùng hàm "pop". Đầu tiên, ta kiểm tra xem stack có rỗng hay không bằng hàm "is_empty", nếu stack rỗng, in ra "Stack underflow" rồi trả về -1 đại diện cho lỗi chức năng. Ngược lại, ta trả về giá trị ở đỉnh stack và giảm stack xuống 1 đơn vị.

```
int pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}
```

Hàm is_empty(stack) dùng để kiểm tra xem 1 stack có rỗng không, nó trả về kết quả so sánh top với -1.
```
int is_empty( Stack stack) {
    return stack.top == -1;
}
```

Để lấy giá trị ở đỉnh của stack, ta dùng hàm "top". Đầu tiên ta kiểm tra xem thử stack có rỗng hay không bằng hàm "is_empty", nếu có, ta in ra "Stack is empty" rồi trả về -1 thể hiện truy xuất thất bại. Ngược lại, ta trả về giá trị ở đỉnh stack.

```
int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}
```

## 2. Queue
Queue là một cấu trúc dữ liệu tuân theo nguyên tắc "First In, First Out" (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra. 

Các thao tác cơ bản trên hàng đợi bao gồm:
- “enqueue” (thêm phần tử vào cuối hàng đợi)
- “dequeue” (lấy phần tử từ đầu hàng đợi). 
- “front” để lấy giá trị của phần tử đứng đầu hàng đợi.

Đầu tiên ta cũng tạo 1 struct Queue như sau:

```
typedef struct{
    int* items;
    int size;
    int front, rear;
} Queue;
```

Con trỏ "items" dùng để lưu các phần tử trong stack. "size" dùng để lưu số lượng phần tử. Hai biến front và rear lần lượt lưu vị trí đầu và cuối của queue.


Để khởi tạo 1 hàng đợi, ta dùng hàm iniialize, truyền vào địa chỉ của 1 queue đã được khai báo trước đó cùng với kích thước khởi tạo.
Ta cấp phát động bộ nhớ cho con trỏ items với kích thước bằng với kích thước khởi tạo "size". Ta khởi tạo front và rear là -1 vì ban đầu stack chưa có phần tử.
```
void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}
```

Ta dùng hàm "enqueue" để thêm giá trị mới vào cuối hàng đợi. Đầu tiên ta cần kiểm tra queue có đầy hay không bằng hàm "is_full", nếu queue đầy thì ta in ra màn hình "Queue overflow" và kết thúc hàm. Nếu queue vẫn còn chỗ trống, ta tiếp tục kiểm tra xem queue có rỗng không bằng hàm "is_empty", nếu rỗng, ta gắn cả front và rear của queue lên 0. Nếu không, ta tăng vị trí rear lên 1 đơn vị và lấy dư với size để tránh nó vượt quá kích thước của queue. Cuối cùng thêm giá trị vào vị trí rear chỉ tới.

```
int is_empty(Queue queue) {
    return queue.front == -1;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}
```

Ta dùng hàm "dequeue" để xóa và lấy ra giá trị ở đầu hàng đợi. Nếu Queue rỗng, ta in ra "Queue underflow" rồi return -1 biểu thị không xóa được. Nếu không, ta tạo 1 biến dequeued_value để lưu giá trị ở đầu queue. Sau đó ta kiểm tra nếu front = rear, có nghĩa là queue rỗng, thì ta reset lại front = rear = -1. Nếu không, ta tăng vị trí front lên 1 đơn vị và lấy dư với size để tránh nó vượt quá kích thước của queue. Cuối cùng, ta trả về giá trị dequeued_value.

```
int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}
```
Ta dùng hàm "front" để lấy giá trị ở đầu hàng đợi. Nếu Queue rỗng, ta in ra "Queue is empty" rồi return -1 biểu thị không truy xuất được giá trị. Nếu không, ta trả về giá trị ở đầu hàng đợi (vị trí lưu ở queue.front). 
```
int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}
```




