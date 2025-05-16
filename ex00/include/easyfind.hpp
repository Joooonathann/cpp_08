#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>

/* 
 * Function EasyFind:
 *
 * La fonction permet de retrouver dans un container
 * un int et retourne un itérateur pointant la valeur,
 * sinon elle retourne une exception.
 * 
 * T est un type de container générique.
 * T &container est une référence vers le container.
 * Value est la valeur qu'on recherche dans le container.
 * 
 */
template<typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    typename T::const_iterator i = std::find(container.begin(), container.end(), value);
    if (i == container.end())
        throw (std::runtime_error("Value not found in container"));
    return (i);
}