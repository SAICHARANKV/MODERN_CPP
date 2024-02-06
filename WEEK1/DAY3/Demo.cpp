#include <iostream>
int main()
{

    return 0;
}

/*
    Assume there are two classes
    Alpha & Beta

    Inheritance: To create a generalized code with specific subtypes.
    Alpha extends Beta or Beta extends Alpha.

    Association: Alpha uses functionalities from Beta
                    or
                Beta uses functionalities from Alpha

    Composition:    Alpha is instantiated by using one or more instances
                    of Beta.Instance of alpha controls the life of instance/s
                    of Beta.

                    or

                    Beta is instantiated by using one or more instances
                    of Alpha.Instance of Beta controls the life of instance/s
                    of Alpha.

    Aggregation:    Alpha is instantiated by using one or more instances
                    of Beta.Instance of alpha does not controls the life of instance/s
                    of Beta.

                    or

                    Beta is instantiated by using one or more instances
                    of Alpha.Instance of Beta does not controls the life of instance/s
                    of Alpha.

                    eg: employee having an account in a bank.


*/

/*

    For every data member, following things must be considered

    1) Is it supposed to be mutable or immutable?
            - Does it need to auto increment based on previous value?

    2) Should be accepted by value,by lvalue reference or rvalue reference
    or both?

    3) Is it stack allocated or heap allocated? (or maybe both partially?)

    4) Does it need to be smartly managed? (applicable only for heap allocated member memory)

    5) Does the data member need to have a non-null state at the time of
        instantiation of the object?
*/
/*

    BankAccount
        - _accountNumber (long) [ use a static value to auto increment]
        - _accountHolderName (std::string&&)
        - _accountType (either SAVINGS,CURRENT,PENSION) (enum)
        - _debitCard (shared_ptr to an instance of heap allocated DebitCard == smartpointer)
            - _cvv const unsigned short
            - _cardNumber long
            - _type (enum)
            - _expiry (std::string)

*/