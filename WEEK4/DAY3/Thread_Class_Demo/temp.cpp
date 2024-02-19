// a preprocessor macro #include to copy and paste all code in the iostream header file
//the copy pasted code will form the material for AST and compilation

#include <iostream> // g++ temp1.cpp -E (shows the exact source code after the finish of preprocessing)


/*
    declaration and definition of the global top level function
    The function is called add.
    It takes 2 parameters, both of which are integers passed by value.
    Function return an integer by value // by value means copy
*/
int add(int n1 , int n2) 
{
    return n1 + n2;
}

/*
    The declaration and definition of entry-point function main
    main returns an integer (representing the exit status of the program)
    Since we are use a compiler from post c99, return value is not mentioned
    explicitly. 
*/
int main()
{

    /*
        we invoke a callable with the identifier name add by passing
        2 rvalues which are integer literals 10 and 20
        The return value from callable is then used as an operand
        which is the rhs operand to << operator.

        This result is a new updated std::ostream object to be created
        whose reference becomes the lhs second << operator.
        The second << operator takes a const char* with literal "\n" as its
        rhs operand.

        This will result in a the final std::ostream object to be created
        which will connect with the stdout file descriptor the running process
        so that the output can be sent to the console foro user's view
    */
    std::cout << add(10, 20) << "\n";
}