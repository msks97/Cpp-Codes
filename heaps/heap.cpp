#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    private:
        vector<int> heap;

        int parent(int index)
        {
            return (index-1)/2;
        }

        int leftChild(int index)
        {
            return 2*index + 1;
        }

        int rightChild(int index)
        {
            return 2*index + 2;
        }

        void swap(int index1, int index2)
        {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }

        void sinkDown(int index)
        {
            int max = index;
            while(true)
            {
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);

                if(leftIndex < heap.size() && heap[leftIndex] > heap[max])
                {
                    max = leftIndex;
                }

                if(rightIndex < heap.size() && heap[rightIndex] > heap[max])
                {
                    max = rightIndex;
                }

                if(max != index)
                {
                    swap(max, index);
                    index = max;
                }
                else return;
            }
            
        }

    public:
        void insert(int value)
        {
            heap.push_back(value);
            
            int current = heap.size() - 1;
            while(current> 0 && heap[current] > heap[parent(current)])
            {
                swap(current, parent(current));
                current = parent(current);
            }
        }

        void printHeap()
        {
            cout<<"Heap : [";
            for (auto i : heap)
            {
                cout << i << " ";
            }
            cout<<"]"<<endl;
        }

        void remove() //in heap only top item/ root is removed
        {
            if(heap.empty()) return; //INT_MIN; // if heaps is empty

            int maxValue = heap.front();
            if(heap.size() == 1) heap.pop_back();
            else
            {
                heap[0] = heap.back();
                heap.pop_back();
                sinkDown(0);
            }
        }

        
};

int main()
{
    Heap* h = new Heap();

    h->insert(99);
    h->insert(72);
    h->insert(61);
    h->insert(58);

    h->printHeap();

    h->insert(100);
    h->printHeap();

    h->insert(75);
    h->printHeap();

    h->remove();
    h->printHeap();

    h->remove();
    h->printHeap();

    return 0;
}