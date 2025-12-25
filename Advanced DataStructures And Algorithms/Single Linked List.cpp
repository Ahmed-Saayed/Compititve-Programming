class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }


    void append(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void insertAfter(int target, int value) {
        Node* current = head;

        while (current != NULL && current->data != target) {
            current = current->next;
        }

        if (current == NULL) return;

        Node* newNode = new Node(value);
        newNode->next = current->next;
        current->next = newNode;

        if (current == tail)
            tail = newNode;
    }

    void remove(int value) {
        if (head == NULL) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->data != value) {
            current = current->next;
        }

        if (current->next == NULL) return;

        Node* temp = current->next;
        current->next = temp->next;

        if (temp == tail) {
            tail = current;
        }

        delete temp;
    }

    void Bublesort(){
        Node* cur = head;

        int sz = 0;
        while(cur != NULL)
            sz++, cur = cur ->next;

        for(int i = 0; i < sz; i++){
            cur = head;

            while(cur->next != NULL){
                int val1 = cur->data, val2 = cur->next->data;

                if(val1 > val2){
                    remove(val1),
                    insertAfter(val2, val1);

                    break;
                }
                cur = cur -> next;
            }
        }
    }

    void Print(){
        Node* cur=head;
        while(cur!=NULL){

            cout<<cur->data<<' ';
            cur=cur->next;
        }

        cout<<"\n**********\n";
    }
};
