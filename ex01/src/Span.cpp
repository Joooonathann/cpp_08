#include "../include/Span.hpp"

Span::Span(unsigned int N): _capacity(N) { }

Span::Span(const Span &copy): _capacity(copy._capacity), _data(copy._data) { }


Span    &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_capacity = copy._capacity;
        this->_data = copy._data;
    }
    return (*this);
}

Span::~Span(void) { }

void    Span::addNumber(int n)
{
    if (this->_data.size() >= _capacity)
        throw (std::overflow_error("Cannot add number: capacity exceeded"));
    this->_data.push_back(n);
}

//Plus petit écart
int     Span::shortestSpan(void) const
{
    if (this->_data.size() < 2)
        throw (std::logic_error("Not enough numbers to compute span"));
    std::vector<int>    sorted = this->_data;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return (minSpan);
}

//Plus grand écart
int     Span::longestSpan(void) const
{
    if (this->_data.size() < 2)
        throw (std::logic_error("Not enough numbers to compute span"));
    int min = *std::min_element(this->_data.begin(), this->_data.end());
    int max = *std::max_element(this->_data.begin(), this->_data.end());
    return (max - min);
}