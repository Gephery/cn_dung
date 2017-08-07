//
// Created by Max Grucella on 7/18/17.
//

#include "reallocation_list.h"

template <class T>
unsigned long ReallocationList<T>::Add(T item)
{
  if (empty_space_.empty())
  {
    things_.push_back(item);
    return things_.size() - 1;
  }

  unsigned long index = empty_space_.front();
  empty_space_.pop();
  things_[index] = item;

  return index;
}

template <class T>
unsigned long ReallocationList<T*>::Add(T* item)
{
  if (empty_space_.empty())
  {
    things_.push_back(item);
    return things_.size() - 1;
  }

  unsigned long index = empty_space_.front();
  empty_space_.pop();
  things_[index] = item;

  return index;
}

template <class T>
void ReallocationList<T*>::Remove(unsigned long index)
{
  empty_space_.push(index);
  things_[index] = nullptr;
}

template <class T>
T* ReallocationList<T*>::Get(int index)
{
  return (things_[index]);
}

template class ReallocationList<Mob*>;