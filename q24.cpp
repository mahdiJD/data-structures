class LinkedQueue {
private:
    Node* front;    // اشاره‌گر به ابتدای صف
    Node* rear;     // اشاره‌گر به انتهای صف
    int size;       // تعداد عناصر در صف

public:
    LinkedQueue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(int value) {
        Node* newNode = new Node(value); // ایجاد گره جدید
        if (isEmpty()) {
            front = rear = newNode; // اگر صف خالی باشد
        } else {
            rear->next = newNode;  // اتصال گره جدید به انتهای صف
            rear = newNode;        // به‌روزرسانی اشاره‌گر انتها
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "صف خالی است" << endl;
            return;
        }
        Node* temp = front;    // ذخیره گره فعلی ابتدای صف
        front = front->next;   // حرکت اشاره‌گر به گره بعدی
        delete temp;           // آزادسازی حافظه
        size--;

        if (front == nullptr) { // اگر صف خالی شد
            rear = nullptr;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "صف خالی است." << endl;
            return -1; // مقدار پیش‌فرض
        }
        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int getSize() const {
        return size;
    }

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue(); // حذف تمامی گره‌ها
        }
    }
};
