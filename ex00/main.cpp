#include "./include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void) 
{
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {10, 20, 30, 40, 50};
    
    std::vector<int> vec(array1, array1 + 5);
    std::list<int> lst(array2, array2 + 5);
    try 
    {
        std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;
        std::cout << "Found in list: " << *easyfind(lst, 30) << std::endl;
        std::cout << "Trying to find 100 in vector..." << std::endl;
        easyfind(vec, 100);
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}