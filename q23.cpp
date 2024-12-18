class LinkedList {
private:
    Node* first; 
    Node* last;  

public:
    LinkedList() : first(nullptr), last(nullptr) {}

    void addToFront(int value) {
        Node* newNode = new Node(value);
        if (first == nullptr) { 
            first = last = newNode;
        } else {
            newNode->next = first;
            first = newNode;
        }
    }

    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (first == nullptr) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    // افزودن به وسط لیست بر اساس اندیس (index)
    void addToMiddle(int value, int position) {
        if (position <= 0) {
            // اگر اندیس کوچک‌تر یا برابر صفر باشد، به ابتدای لیست اضافه شود
            addToFront(value); 
            return;
        }

        Node* newNode = new Node(value);
        Node* current = first;
        int index = 0;

        while (current != nullptr && index < position - 1) { // حرکت تا گره قبلی
            current = current->next;
            index++;
        }

        if (current == nullptr) {
            // اگر موقعیت از طول لیست بیشتر باشد، به انتهای لیست اضافه شود
            addToEnd(value); 
        } else {
            newNode->next = current->next;
            current->next = newNode;

            if (newNode->next == nullptr) { 
                // به‌روزرسانی آخرین گره اگر در انتها اضافه شود
                last = newNode;
            }
        }
    }

    void removeFromMiddle(int position) {
        if (first == nullptr) { // اگر لیست خالی است
            cout << "لیست خالی است!" << endl;
            return;
        }

        if (position <= 0) { // حذف از ابتدای لیست
            Node* temp = first;
            first = first->next;
            if (first == nullptr) { // اگر لیست تنها یک عنصر داشت
                last = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = first;
        int index = 0;

        while (current->next != nullptr && index < position - 1) { // حرکت تا گره قبلی
            current = current->next;
            index++;
        }

        if (current->next == nullptr) { // اگر موقعیت خارج از محدوده باشد
            cout << "موقعیت معتبر نیست!" << endl;
        } else {
            Node* temp = current->next;
            current->next = temp->next;

            if (temp->next == nullptr) { 
                // به‌روزرسانی آخرین گره اگر از انتها حذف شود
                last = current;
            }

            delete temp;
        }
    }

    void display() const {
        Node* current = first;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* current = first;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
