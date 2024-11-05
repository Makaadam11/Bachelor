
#include "checking_policy.h"
#include "stack.h"
#include<iostream>

const int n=10;

main() {
  int n=10;
  Stack<int,0,Std_exception_on_error_policy,Expandable_new_allocator > s1(n);
  Stack<int,10,Abort_on_error_policy,Static_table_allocator > s2(n);
    s1.push(0);
    s1.push(1);
    std::cout << "ok" << std::endl;

    s2.push(0);
    s2.push(1);
    std::cout << "won't run due to error" << std::endl;

    return 0;
}