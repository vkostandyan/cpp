#include "Span.hpp"

Span::Span() : N(5) {}

Span::Span(const unsigned int n) : N(n) {}

Span::Span(const Span& other) : N(other.N), v(other.v) {}

Span& Span::operator=(const Span& rhs)
{
    if (&rhs != this)
    {
        this->N = rhs.N;
        this->v = rhs.v;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int nb)
{
    if (this->v.size() == this->N)
          throw std::length_error("Exceeded maximum size");
    v.push_back(nb);
}

int Span::longestSpan(void) const
{
    if (v.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    return *std::max_element(v.begin(), v.end()) - *std::min_element(v.begin(), v.end());
}

int Span::shortestSpan() const
{
    if (v.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");

    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());

    int minDiff = INT_MAX;
    for (std::size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}