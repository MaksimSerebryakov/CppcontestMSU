#include <map>
#include "../inc/complex_stack.hpp"
#include "../inc/polish_notation.hpp"

using namespace numbers;

complex numbers::eval(const std::vector<std::string> &args, const complex &z) {
    complex_stack notation;
    static std::map<std::string, void (*)(complex_stack &stack)> mp;

    //move to mp initialization
    mp["+"] = [](complex_stack &stack) {complex num = +stack; stack = ~stack; num += +stack; 
        stack = ~stack; stack = stack << num;};
    mp["-"] = [](complex_stack &stack) {complex num = +stack; stack = ~stack; num = -num; 
        num += +stack; stack = ~stack; stack = stack << num;};
    mp["*"] = [](complex_stack &stack) {complex num = +stack; stack = ~stack; num *= +stack; 
        stack = ~stack; stack = stack << num;};
    mp["/"] = [](complex_stack &stack) {complex divider = +stack; stack = ~stack; 
        complex divisible = +stack; stack = ~stack; divisible /= divider; stack = stack << divisible;};
    mp["!"] = [](complex_stack &stack) {stack = stack << +stack;};
    mp[";"] = [](complex_stack &stack) {stack = ~stack;};
    mp["~"] = [](complex_stack &stack) {complex num = ~(+stack); stack = ~stack; stack = stack << num;};
    mp["#"] = [](complex_stack &stack) {complex num = -(+stack); stack = ~stack; stack = stack << num;};

    for (size_t i = 0; i < args.size(); ++i) {
        if(mp.find(args[i]) != mp.end()) {
            mp[args[i]](notation);
        } else {
            if(args[i] == "z") {
                notation = notation << z;
            } else {
                notation = notation << complex(args[i]);
            }
        }
    }

    return +notation;        
}
