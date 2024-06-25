#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};

// Capture by value
// The global variable global_x cannot be captured because it is not
// within the reaching scope of the lambda. It can however still be accessed
// from within the lambda using normal name lookup rules.
void test1()
{
	std::cout << "\n---Test1 --------------------------" << std::endl;
    
    int local_x {100};
    
    auto l = [local_x] () {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains to
// the captured variable within the lambda body and not the actual variable.
void test2()
{
	std::cout << "\n---Test2 --------------------------" << std::endl;
    
    int x {100};
    
    auto l = [x] () mutable {
        x += 100;
        std::cout << x << std::endl;
    };
    
    l();
    std::cout << x << std::endl;
    
    l();
    std::cout << x << std::endl;
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual variable.
void test3()
{
	std::cout << "\n---Test3 --------------------------" << std::endl;
    
    int x {100};
    
    auto l = [&x] () mutable {
        x += 100;
        std::cout << x << std::endl;
    };
    
    l();
    std::cout << x << std::endl;
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value.
// The variable z is not captured by the lambda.
void test4()
{
	std::cout << "\n---Test4 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};    // Note that z is not captured in the lambda since it is not used.
                    // This should produce an 'unused variable' warning when compiling.
    
    auto l = [=] () mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

// Default capture by reference
// This time because all three variables - x,y,z are used within
// the lambda body, all three of them will be captured by reference.
void test5()
{
	std::cout << "\n---Test5 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto l = [&] () {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by value, capture y by reference
void test6()
{
	std::cout << "\n---Test6 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto l = [=, &y] () mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference, capture x and z by value
void test7()
{
    
}

void test8()
{
    
}

void test9()
{
    
}

void test10()
{
    
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    return 0;
}
