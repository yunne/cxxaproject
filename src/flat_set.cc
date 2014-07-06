#include "flat_set.hh"

template <class T>
Flat_set<T>::Flat_set()
{
    cnt = std::vector<T>();
}
template <class T>
Flat_set<T>::~Flat_set()
{
}

template <class T>
bool Flat_set<T>::contain(T elt)
{
    for (auto e : cnt)
    {
        if (e == elt)
            return true;
    }
    return false;
}

template <class T>
void Flat_set<T>::insert_in_place(T elt)
{
    cnt.push_back(elt);
}

template <class T>
bool Flat_set<T>::insert(T elt)
{
    auto it = cnt.begin();
    for (; it != cnt.end() && *it < elt; it++)
        continue;
    if (it == cnt.end())
        cnt.push_back(elt);
    else if (*it == elt)
        return false;
    else
        cnt.insert(it, elt);
    return true;
}

template <class T>
bool Flat_set<T>::empty()
{
    return cnt.empty();
}

template <class T>
void Flat_set<T>::print(std::ostream& os)
{
    for (auto e : cnt)
        os << e << " ";
}

template <class T>
std::ostream& operator<<(std::ostream& os, Flat_set<T> set)
{
    set.print(os);
    return os;
}
