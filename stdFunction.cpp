// Compile-time and run-time type erasure example
#include <iostream>
#include <memory>
#include <ostream>

template<typename T>
class function;

// Partial specialisation
template<typename Ret, typename ... Param>
class function<Ret (Param...)>
{
public:
    /* Constructor with function object (lambda) */
    template<typename FunctionObject>
    function(FunctionObject fo) : callable{std::make_unique<callable_impl<FunctionObject>>(std::move(fo))}
    {
    }; 

    Ret operator()(Param... param)
    {
        return callable->call(param...);
    };
    
private:
    /* Pointer to abstract interface */
    struct callable_interface
    {
        virtual Ret call(Param...) = 0; /* Pure virtual */
        virtual ~callable_interface() = default;
    };

    template<typename Callable>
    struct callable_impl : callable_interface
    {
        callable_impl(Callable callable_) : callable{std::move(callable_)} {};
        Ret call (Param...param) { return callable(param...); }
        Callable callable;
    };

    std::unique_ptr<callable_interface> callable;
};

int f(int x, int y) {
    return x + y;
}

int main()
{
    function<int (int, int)> func1{f}; /* Construct with function object */
    function<int (int, int)> func2{[](int x, int y){ return x + y; } }; /* Construct with lambda */
    std::cout << "Func1: " << func1(1, 2) << std::endl;
    std::cout << "Func2: " << func2(1, 2) << std::endl;
}
