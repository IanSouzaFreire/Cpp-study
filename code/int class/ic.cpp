#include <iostream>

class Int;

int main(int, char**) {
	Int a = 10;
	return 0;
}

class Int {
  friend Int;
  long long _original;
  long long value;
public:
  Int(const long long& given)
  : _original(given), value(given)
  { }
  
  Int()
  { }
  
  void operator= (const long long& given)
  { value = given; }
  
  void operator= (const Int& given)
  { value = given.value; }
  
  void operator+= (const long long given)
  { value += given; }
  
  void operator+= (const Int& given)
  { value += given.value; }
  
  void operator-= (const long long given)
  { value -= given; }
  
  void operator-= (const Int& given)
  { value -= given.value; }
  
  void operator*= (const long long given)
  { value *= given; }
  
  void operator*= (const Int& given)
  { value *= given.value; }
  
  void operator/= (const long long given)
  { value /= given; }
  
  void operator/= (const Int& given)
  { value /= given.value; }
  
  void operator%= (const long long given)
  { value %= given; }
  
  void operator%= (const Int& given)
  { value %= given.value; }
  
  long long operator+ (const long long given)
  { return (value + given); }
  
  long long operator+ (const Int& given)
  { return (value + given.value); }
  
  long long operator- (const long long given)
  { return (value - given); }
  
  long long operator- (const Int& given)
  { return (given.value - value); }
  
  long long operator* (const long long given)
  { return (value * given); }
  
  long long operator* (const Int& given)
  { return (value * given.value); }
  
  long long operator/ (const long long given)
  { return (value / given); }
  
  long long operator/ (const Int& given)
  { return (given.value / value); }
  
  long long operator% (const long long given)
  { return (value % given); }
  
  long long operator% (const Int& given)
  { return (given.value % value); }
  
  long long& get()
  { return value; }
  
  long long& original()
  { return _original; }
};