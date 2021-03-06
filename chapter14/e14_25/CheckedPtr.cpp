#include "CheckedPtr.hpp"
#include <stdexcept>

CheckedPtr& CheckedPtr::operator++()
{
  if (curr == end)
    throw std::out_of_range ("increment past the end of CheckedPtr");
  ++curr;
  return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
  if (curr == beg)
    throw std::out_of_range("decrement past the beginning of CheckedPtr");
  --curr;
  return *this;
}

int& CheckedPtr::operator[] (const size_t index)
{
  if ( beg + index >= end )
    throw std::out_of_range ("index past the end of CheckedPtr");
  return *(beg + index);
}

const int& CheckedPtr::operator[] (const size_t index) const
{
  if ( beg + index >= end )
    throw std::out_of_range ("index past the end of CheckedPtr");
  return *(beg + index);
}

int& CheckedPtr::operator* ()
{
  return *curr;
}

const int& CheckedPtr::operator* () const
{
  return *curr;
}
