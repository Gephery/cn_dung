//
// Created by Max Grucella on 7/18/17.
//

#ifndef CODE_NAME_REALLOCATION_LIST_H
#define CODE_NAME_REALLOCATION_LIST_H


#include <vector>
#include <queue>

class Mob;


template<class T>
class ReallocationList
{
public:
  unsigned long Add(T item);
  void Remove(unsigned long index);
  T Get(int index);
private:
  std::vector<T> things_;
  std::queue<unsigned long> empty_space_;
};

template<class T>
class ReallocationList<T*>
{
public:
  unsigned long Add(T* item);
  void Remove(unsigned long index);
  T* Get(int index);
private:
  std::vector<T*> things_;
  std::queue<unsigned long> empty_space_;
};

#endif //CODE_NAME_REALLOCATION_LIST_H
