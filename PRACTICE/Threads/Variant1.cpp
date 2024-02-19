#include <iostream>
#include <vector>
#include <array>
#include <variant>
#include <memory>
#include <functional>

class Car
{
private:
    int _price;
    std::string _id;

public:
    Car() = default;
    Car(const Car &) = default;

    Car &operator=(const Car &) = default;
    int price() const { return _price; };

    void setPrice(int price) { _price = price; };
    ~Car() = default;
    Car(int price, std::string id) : _price(price), _id(id){};

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs)
    {
        os << "_price: " << rhs._price
           << " _id: " << rhs._id;
        return os;
    }
};

class Vehicle
{
private:
    int _carPrice;
    std::string _carEngineId;

public:
    Vehicle() = default;
    ~Vehicle() = default;
    Vehicle(const Vehicle &) = default;
    Vehicle(int price, std::string id) : _carPrice(price), _carEngineId(id){};
    int carPrice() const { return _carPrice; }
    void setCarPrice(int carPrice) { _carPrice = carPrice; }

    std::string carEngineId() const { return _carEngineId; }
    void setCarEngineId(const std::string &carEngineId) { _carEngineId = carEngineId; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs)
    {
        os << "_carPrice: " << rhs._carPrice
           << " _carEngineId: " << rhs._carEngineId;
        return os;
    }
};

using CarPointer = std::shared_ptr<Car>;
using VehiclePointer = std::shared_ptr<Vehicle>;
using Container = std::vector<std::variant<CarPointer, VehiclePointer>>;

void operation(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("EMpty Data!!!\n");
    int total = 0;
    for (const auto &v : data)
    {
        auto f1 = [](auto &&val)
        { std::cout << *val << "\n"; };
        std::visit(f1, v);
        if (std::holds_alternative<CarPointer>(v))
        {
            auto carPtr = std::get<CarPointer>(v);
            total += carPtr->price();
        }
        else // if (std::holds_alternative<VehiclePointer>(v))
        {
            auto vehiclePtr = std::get<VehiclePointer>(v);
            std::cout << vehiclePtr->carEngineId() << "\n";
        }
    }
    std::cout << "Total Car Price: " << total << "\n";
}

void maxEnginePrice(const Container &data)
{
    if (data.empty())
        throw std::runtime_error("EMpty Data!!!\n");
    int result = 0; // Initialize result to 0
    for (const std::variant<CarPointer, VehiclePointer> &v : data)
    {
        if (std::holds_alternative<VehiclePointer>(v))
        {
            auto vehiclePtr = std::get<VehiclePointer>(v);
            int currentPrice = vehiclePtr->carPrice(); // Get the current vehicle's engine price

            if (currentPrice > result) // Update result if current price is greater
            {
                result = currentPrice;
            }
        }
    }
    std::cout << "Maximum Engine Price: " << result << std::endl;
}

std::optional<int> FindPriceById(const Container &data, std::string CarId)
{
    if (data.empty())
    {
        throw std::runtime_error("Data Not Available");
    }

    for (const auto &v : data)
    {
        if (std::holds_alternative<VehiclePointer>(v))
        {
            auto vehiclePtr = std::get<VehiclePointer>(v);
            if (vehiclePtr->carEngineId() == CarId)
            {
                return vehiclePtr->carPrice();
            }
        }
    }

    return std::nullopt;
}



int main()
{
    Container data;
    data.emplace_back(std::make_shared<Car>(13, "1"));
    data.emplace_back(std::make_shared<Car>(25, "2"));
    data.emplace_back(std::make_shared<Car>(12, "3"));
    data.emplace_back(std::make_shared<Vehicle>(15, "101"));
    data.emplace_back(std::make_shared<Vehicle>(16, "202"));
    data.emplace_back(std::make_shared<Vehicle>(17, "303"));
    operation(data);
    maxEnginePrice(data);
    
    auto result = FindPriceById(data, "101");
    if (result.has_value())
    {
        // std::visit([](auto &&arg) { std::cout << arg << std::endl; }, result.value());
        std::cout<<"result: "<<result.value()<<"\n";
    }
    else
    {
        std::cout << "Item not found." << std::endl;
    }
    
}
