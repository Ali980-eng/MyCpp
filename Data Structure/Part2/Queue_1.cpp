#include <iostream>
#include "InOut.hpp"
using namespace std;
template <typename T>
class Queue_arr
{
private:
    size_t rear;
    size_t front;
    int length;
    T *arr;
    int maxSize;

public:
    Queue_arr(int ArrSize)
    {
        if (ArrSize < 0)
            throw invalid_argument("the size have to be bigger then zero");
        front = 0;
        arr = new T[ArrSize];
        maxSize = ArrSize;
        rear = maxSize - 1;
        length = 0;
    }
    Queue_arr(initializer_list<T> &vec) : arr(vec) {};
    constexpr bool empty() const noexcept
    {
        return length == 0;
    }
    constexpr bool full() const noexcept
    {
        return length == maxSize;
    }
    void addQueue(T element) noexcept
    {
        if (full())
            io::println_error("Queue Full Can't Enqueue");
        else
        {
            rear = (rear + 1) % maxSize;
            arr[rear] = element;
            length++;
        }
    }
    void deleteQueue() noexcept
    {
        if (empty())
            io::println_error("Empty Queue Can't Dequeue");
        else
        {
            front = (front + 1) % maxSize;
            length--;
        }
    }
    T get_front() const
    {
        if (empty())
        {
            io::println_error("the queue is empty, no elements to get");
            throw std::invalid_argument("Queue is empty, no front element available.");
        }
        return arr[front];
    }
    void get_front(T &element) const noexcept
    {
        if (empty())
        {
            io::println_error("the queue is empty, no elements to get");
            return;
        }
        element = arr[front];
    }
    T get_rear() const
    {
        if (empty())
        {
            io::println_error("the queue is empty, no elements to get");
            throw std::invalid_argument("Queue is empty, no rear element available.");
        }
        return arr[rear];
    }
    void print() const noexcept
    {
        if (empty())
        {
            io::println_error("the queue is empty, no elements to print");
            return;
        }
        cout << "Queue elements: ";
        for (size_t i = 0; i < length; i++)
            cout << arr[(front + i) % maxSize] << " ";
        cout << endl;
    }
    T search(T element) const noexcept
    {
        if (!empty())
        {
            for (int i = front; i != rear; i = (i + 1) % maxSize)
            {
                if (arr[i] == element)
                    return i;
            }
            if (arr[rear] == element)
                return rear;
        }
        else
            io::println_error("Q is empty ! ");
        return -1;
    }
    void operator=(const vector<T> &vec)
    {
        if (!vec.empty())
        {
            for (int i = 0; i < vec.size(); i++)
                addQueue(vec[i]);
        }
        else
            io::println_error("Empty Error");
    }
    void operator=(const Queue_arr &other) noexcept
    {
        if (this != &other)
        {
            front = other.front;
            rear = other.rear;
            length = other.length;
            for (size_t i = 0; i < maxSize; i++)
                arr[i] = other.arr[i];
        }
    }
    T operator>>(T &element)
    {
        if (empty())
        {
            io::println_error("the queue is empty, no elements to read");
            throw std::invalid_argument("Queue is empty, no elements to read.");
        }
        element = get_front();
        deleteQueue();
        return element;
    }
    T operator<<(const T &element)
    {
        if (full())
        {
            io::println_error("Queue Full Can't Enqueue");
            throw std::out_of_range("Queue is full, cannot add more elements.");
        }
        addQueue(element);
        return element;
    }
    ~Queue_arr() = default;
};

int main()
{
    io::NewLines(4);
    Queue_arr<int> que(10);
    que.addQueue(10);
    que.addQueue(77);
    que.addQueue(67);
    io::print("is it full: ");
    io::println(que.full() ? "true" : "false");
    io::print("The front(1): ");
    io::println(que.get_front());
    que.deleteQueue();
    io::print("The front(2): ");
    io::println(que.get_front());
    que.deleteQueue();
    io::print("The front(3): ");
    io::println(que.get_front());
    que.deleteQueue();
    io::print("is it empty: ");
    io::println(que.full() ? "true" : "false");
    que = {10, 88, 19, 90};
    que << 98;
    que << 77;
    io::print(que.search(19));
    return 0;
}
