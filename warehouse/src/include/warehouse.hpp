#include <vector>
#include "employee.hpp"
#include "shelf.hpp"
class Warehouse
{
private:
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;

public:
    Warehouse();
    void addEmployee(const Employee& employee);
    void addShelf(const Shelf& shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(const std::string& itemName, int itemCount);

};


