#include <iostream>
#include "./include/Span.hpp"

int main() {
    srand((unsigned) time(NULL));
    
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        Span bigSpan(10000);
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(rand());

        std::cout << "Big span shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big span longest : " << bigSpan.longestSpan() << std::endl;
    }

    return (0);
}