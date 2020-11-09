#include <iostream>
#include <vector>

using namespace std;

class queue {

public:

    queue () {
        cout << __PRETTY_FUNCTION__ << endl;
        head.next = nullptr;

    }

    void enqueue (int elem) {
        cout << __PRETTY_FUNCTION__  << "(" << elem << ")" << endl;
        link *l = new link;
        (*l).value = elem;
        l->next = nullptr;
        link *h = &head;
        while (h->next != nullptr) {
            h = h->next;
            h->next = l;
        }
    }

    int dequeue () {
        cout << __PRETTY_FUNCTION__ << endl;
        if (head.next != nullptr) {
            int ret = head.next->value;
            link *old = head.next;
            head.next = head.next->next;
            delete old;
            return ret;
        }
        return 0;
    }

    bool empty() {
        cout << __PRETTY_FUNCTION__ << endl;
        return head.next == nullptr;
    }

    ~queue() {
        while (!empty()) {
            dequeue();
        }
        cout << __PRETTY_FUNCTION__ << endl;
    }

private:
    struct link {
        int value;
        struct link *next;
    } head;
};

int main() {
    queue q;
    for (int i = 0; i < 10; i++) {
        queue tmp;
        q.enqueue(i);
    }
    while (!q.empty()) {
        int elem = q.dequeue();
        cout << elem;
    }
}

