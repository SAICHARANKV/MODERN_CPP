#ifndef HR_HPP
#define HR_HPP
#include "Employee.hpp"
#include "HrSpecializationType.hpp"
#include <ostream>
/*
    public : (most lenient)

    protected

    private: (most strict)
*/

/*
    Protected Inheritance
    Base class : private---> protected (reducing security) {not allowed}
                protected ----> protected okay
                public----->protected (increasing security)

    Public Inheritance
    Base class : private(base class)-----> public(child) {not allowed}
                protected(base class)------> public(child) {not allowed}
                public(base class)------>public(child) {allowed}
*/

class HR : public Employee
{
private:
    int _hrTeamSize{0};
    HrSpecializationType _hrSpecialization{HrSpecializationType::TAG};

public:
    HR() = delete;
    HR &operator=(const HR &) = delete;
    HR &operator=(HR &&) = delete;
    HR(const HR &) = delete;
    HR(HR &&) = delete;
    ~HR(){std::cout << "HR Destructor called\n";};
    HR(int id, std::string name, float salary, int size, HrSpecializationType specialization); // Parent first Child next
    float CalculateTax() override;

    int hrTeamSizeHr() const { return _hrTeamSize; }
    void setHrTeamSize(int hrTeamSize) { _hrTeamSize = hrTeamSize; }

    HrSpecializationType hrSpecialization() const { return _hrSpecialization; }
    void setHrSpecialization(const HrSpecializationType &hrSpecialization) { _hrSpecialization = hrSpecialization; }

    friend std::ostream &operator<<(std::ostream &os, const HR &rhs);
};

#endif // HR_HPP
