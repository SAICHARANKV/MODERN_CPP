#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>

class Employee
{
public:
    int _id;
    std::string _name;
    std::mutex _mt;
    bool flag = false;
    std::condition_variable cv;

public:
    // Constructor to initialize ID and name
    Employee(int id, const std::string &name) : _id(id), _name(name) {}

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    const std::condition_variable& getCV() { return cv;}
    // void setCv(const std::condition_variable &cv_) { cv = cv_; }

    bool getFlag() const { return flag; }
    void setFlag(bool _flag) { flag = _flag; }

    void SqCalc(int n);
};

void Employee ::SqCalc(int n)
{
    std::unique_lock<std::mutex> lk(_mt);
    cv.wait(lk, [&]() { return flag; });
    std::cout << "Sq: " << n * n << "\n";
}

int main()
{
    int value;
    std::cout << "Enter the value : " << "\n";
    std::cin >> value;
    Employee e1(1, "Name");

    std::thread t1(&Employee::SqCalc, &e1, value); // No need for std::ref(value)

    {
        std::lock_guard<std::mutex> lk(e1._mt);
        e1.setFlag(true);
    }

    e1.cv.notify_one();

    t1.join();
}
