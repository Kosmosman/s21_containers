// #include <iostream>
#include "s21_Stack.h"
#include <Stack>

int main() {
    // s21::Stack<int>* st = new s21::Stack<int>();
    // s21::Stack<int> stack;

    // stack.push(4);
    // stack.push(5);
    // stack.push(324);
    // Stack.top() = 4;
    // std::cout << Stack.top();

    // s21::Stack<int> stack_2(stack);
    // std::cout << stack_2.top() << "\n";
    // stack_2.pop();
    // std::cout << stack_2.top() << "\n";
    // stack_2.pop();
    // std::cout << stack_2.top() << "\n";
    // stack_2.pop();
    // std::cout << stack_2.top() << "\n";

    // Stack_2.push(4);
    // Stack_2.push(5);
    
    // Stack.swap(Stack_2);
    // std::cout << Stack.top();
    std::stack<int> example;
    example.push(4);
    // std::cout << example.size();
    example.pop();
    std::cout << example.top();
    return 0;
}


// 