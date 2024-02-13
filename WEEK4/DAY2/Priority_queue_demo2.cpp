/*
Make a Priority queue where objects of a class automobile are stored via
priority based on"Max price first!"

The attributes of the class are as follows:
_id :string,
_price :float,
_type : either PRIVATE or COMMERICAL

*/

#include <iostream>
#include <queue>
#include <vector>

enum class vtype { PRIVATE, COMMERICAL };

class Vehicle {
private:
  std::string _id;
  float _price;
  vtype _type;

public:
  Vehicle() = delete;
  ~Vehicle() = default;
  Vehicle(const Vehicle &) = default;
  Vehicle(Vehicle &&) = default;
  Vehicle &operator=(const Vehicle &) = default;
  Vehicle &operator=(Vehicle &&) = default;
  Vehicle(std::string id, float price, vtype type)
      : _id(id), _price(price), _type(type) {}

  std::string id() const { return _id; }
  void setId(const std::string &id) { _id = id; }

  float price() const { return _price; }
  void setPrice(float price) { _price = price; }

  vtype type() const { return _type; }
  void setType(const vtype &type) { _type = type; }

  friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id << " _price: " << rhs._price
       << " _type: " << static_cast<int>(rhs._type);
    return os;
  }
};

struct Max_Price_Comparator {
  bool operator()(Vehicle a, Vehicle b) {
    return a.price() <= b.price(); // Max heap
  }
};

int main() {
  std::vector<Vehicle> data{Vehicle("1", 8820.0f, vtype::PRIVATE),
                            Vehicle("2", 982.2f, vtype::COMMERICAL),
                            Vehicle("3", 789.3f, vtype::PRIVATE)};
  std::priority_queue<Vehicle, std::vector<Vehicle>, Max_Price_Comparator> pq{
      data.begin(), data.end()};

  std::cout << "MAX PRICE RESULT: " << pq.top().price() << "\n";
}
