#include <iostream>

template <class T, int _size, T defaul>
struct Queque {
  int to_add = 0;
  int to_remove = 0;
  T stack[_size];
public:
  void in(const T& given) {
    if (to_add < _size) {
      stack[to_add] = given;
      to_add = (to_add + 1) % _size;
    } else {
      error("Queue is full. Cannot add more elements.\n");
    }
  }
  
  T out() {
    if (to_remove < to_add) {
      T temp = stack[to_remove];
      stack[to_remove] = defaul;
      to_remove = (to_remove + 1) % _size;
      return temp;
    } else {
      error("Queue is empty. Cannot remove elements.\n");
      return defaul;
    }
  }
  
  int size() {
    return _size;
  }
  
  bool isEmpty() {
    return to_add == to_remove;
  }
  
  bool isFull() {
    return (to_add + 1) % _size == to_remove;
  }
private:
  inline void error(const char* s) {
    throw std::runtime_error(s);
  }
};

template <class T, int _size, T defaul>
struct Stack {
  int current = 0;
  T stack[_size];
public:
  void in(const T& given) {
    if (current < _size) {
      stack[current] = given;
      current += 1;
    } else {
      error("Stack is full. Cannot add more elements.\n");
    }
  }
  
  T out() {
    if (current > 0) {
      current -= 1;
      T temp = stack[current];
      stack[current] = defaul;
      return temp;
    } else {
      error("Stack is empty. Cannot remove elements.\n");
      return defaul;
    }
  }
  
  int size() {
    return _size;
  }
  
  bool isEmpty() {
    return current == 0;
  }
  
  bool isFull() {
    return current == _size;
  }
private:
  inline void error(const char* s) {
    throw std::runtime_error(s);
  }
};

int main(int, char**) {
  using namespace std;
  
  struct Stack<char, 3, 0> s;
  struct Queque<char, 3, 0> q;
  
  s.in('a');
  s.in('b');
  
  q.in('x');
  q.in('y');
  
  cout << "in stack: [" << s.out() << ", " << s.out() << "];" << '\n';
  cout << "in stack: [" << q.out() << ", " << q.out() << "]; "<< '\n';
  
  return 0;
}