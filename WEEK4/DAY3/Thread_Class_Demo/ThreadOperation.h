#ifndef THREADOPERATION_H
#define THREADOPERATION_H
#include <condition_variable>
#include <mutex>
#include <ostream>
#include <thread>
class ThreadOperation {
private:
  std::mutex mt;
  int _cube_val{-1};
  bool _cube_val_available{false};
  int _value;
  std::condition_variable cv;

public:
  ThreadOperation() = delete;
  ~ThreadOperation() = default;
  ThreadOperation(const ThreadOperation &) = delete;
  ThreadOperation &operator=(const ThreadOperation &) = delete;
  ThreadOperation(ThreadOperation &&) = delete;
  ThreadOperation &operator=(ThreadOperation &&) = delete;

void Square();
  // Producer  
  void Produce_value_for_cube();

  // Consumer
  void Cube();

  explicit ThreadOperation(int value) : _value(value) {}

  friend std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs);
};

#endif // THREADOPERATION_H
