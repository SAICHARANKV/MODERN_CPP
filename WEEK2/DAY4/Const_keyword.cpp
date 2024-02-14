// Const Correctness!!!

/*
    Rule 1 : const gets applied on token to its immediate left.
    If there is no token on left.It is applied to the token on its
    immediate right.

    Rule 2: Pointer * symbol is also consisdered as a token.
*/

#include "../DAY4/VIRTUAL_CAST_DESTRUCT_EXAMPLE/Employee.hpp"

int main()
{
    // type 1: const with a non pointer  primitive variable
    const int n1 = 10; // n1 is a "constant integer"
    int const n2 = 20; // n2 is a "constant integer"

    // Type 2: const wit a pointer of any typen

    /* cptr is  a pointer to a CONSTANT CHAR*/
    const char *cptr = new char('A');
    //*cptr = 'B'; //error cannot change data because constant char
    cptr = new char('B'); // works

    // char * const cptr2 = new char('A');

    // tyep 2b: const applied on *
    int a = 100;

    // iptr is a constant pointer to an integer
    int *const iptr = &a;
    *iptr = 1000; // okay because integer can be changed
    // *ptr=&n1; // not okay! because pointer  itself is fixed address cannot change

    // *sptr=100; //not allowed

    // sptr =&n1; // not allowed

    // Type 3: const on a object(reference-type/user defined type)
    // const Employee e1(101); // e1  is a const employee,

    // e1._eid=100; //cannot modify any data value from the object

    // Even if we use setters it wont be allowed to modify.
    // e1.setEid(100);

    // These are functions are safe for constant objects
    // Constant objects ARE ONLY ALLOWED TO CALL MEMBER FUNCTIONS WHICH
    // ARE MARKED AS CONST.Employee/Employee.hpp
}