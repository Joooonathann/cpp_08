#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        unsigned int        _capacity;
        std::vector<int>    _data;
    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span(void);

        void addNumber(int n);

        template<typename I>
        void addNumber(I begin, I end)
        {
            if ((static_cast<unsigned int>(std::distance(begin, end)) + this->_data.size()) > this->_capacity)
                throw (std::overflow_error("Cannot add numbers: capacity exceeded"));
            this->_data.insert(this->_data.end(), begin, end);
        }

        int shortestSpan(void) const;
        int longestSpan(void) const;
};
