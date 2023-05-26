#pragma once
#include <vector>
#include <algorithm>
#include "employee.hpp"
#include "shelf.hpp"
class Warehouse
{    
public:
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;
    Warehouse();
    void addEmployee(const Employee& employee);
    void addShelf(const Shelf& shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(const std::string& itemName, int itemCount);

};