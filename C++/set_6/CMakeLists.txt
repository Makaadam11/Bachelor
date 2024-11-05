cmake_minimum_required(VERSION 3.22)
project(set_6)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        set_7 task_1/main.cpp  task_1/checking_policy.h task_2/main.cpp task_2/stack.h task_2/checking_policy.h
        task_3/main.cpp task_4/main.cpp task_3/allocator.h task_3/stack.h task_3/checking_policy.h task_4/stack.h
        task_4/allocator.h task_4/checking_policy.h
        task_1/color.h task_1/col_fact.h)
