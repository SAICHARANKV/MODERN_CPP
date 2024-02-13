#include <iostream>
#include <string>
#include <mutex>
#include <thread>

class Employee
{
private:
    int _id;
    std::string _name;
    std::mutex _mt;

public:
    // Constructor to initialize ID and name
    Employee(int id, const std::string &name) : _id(id), _name(name) {}

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    // Method to lock the mutex
    // void lockMutex() { _mt.lock(); }

    // Method to unlock the mutex
    // void unlockMutex() { _mt.unlock(); }

    void display();
};

int main()
{
    Employee e1(1, "Sai");
    Employee e2(2, "Charan");
    Employee e3(3, "Kushal");
          
    std::thread t1(&Employee::display, &e1); // Thread for e1
    std::thread t2(&Employee::display, &e2); // Thread for e2
    std::thread t3(&Employee::display, &e3); // Thread for e3

    // Join threads
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}

void Employee::display()
{                   
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    _mt.lock();
    // std::lock_guard<std::mutex> lk(_mt);
    std::cout << "ID: " << _id << "\n" <<  "Name: " << _name << "\n";
    _mt.unlock();
}
