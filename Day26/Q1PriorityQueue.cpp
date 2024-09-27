#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> pq;

public:
    void insert(int element) {
        pq.push_back(element);
        int i = pq.size() - 1;
        while (i > 0 && pq[i] > pq[i - 1]) {
            swap(pq[i], pq[i - 1]);
            i--;
        }
    }

    void deleteHighestPriority() {
        if (pq.empty()) {
            cout << "Priority queue is empty. Cannot delete.\n";
            return;
        }
        pq.erase(pq.begin());
    }

    int peek() {
        if (pq.empty()) {
            cout << "Priority queue is empty. Cannot peek.\n";
            return -1;
        }
        return pq.front();
    }

    void display() {
        if (pq.empty()) {
            cout << "Priority queue is empty.\n";
            return;
        }
        cout << "Priority queue elements: ";
        for (int element : pq) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(4);
    pq.insert(8);
    pq.insert(5);
    pq.insert(2);
    pq.insert(10);

    cout << "Priority queue after inserting elements: ";
    pq.display();

    cout << "Element with highest priority: " << pq.peek() << endl;

    pq.deleteHighestPriority();
    cout << "Priority queue after deleting highest priority element: ";
    pq.display();

    cout << "Element with highest priority: " << pq.peek() << endl;

    return 0;
}
