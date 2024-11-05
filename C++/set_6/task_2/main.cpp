
#include<iostream>
#include"stack.h"




const int n=10;

main() {
    
    Stack<int,10>                                  s_no_check;
    Stack<double ,100,Abort_on_error_policy>       s_abort;
    Stack<int *,25,Std_exception_on_error_policy>  s_except;

    /// no checking policy

    s_no_check.pop();
    std::cout << "ok" << std::endl;

    /// abort on error policy

    s_except.pop();
    std::cout << "won't run because of error" << std::endl;

    return 0;
}