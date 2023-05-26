#include <iostream>
#include "warehouse.hpp"
int main(){
    //create a warehouse
    Warehouse warehouse;
    
    // Add employees
    Employee employee1("Bob", true);
    warehouse.addEmployee(employee1);

    // Add shelves
    Shelf shelf1;
        shelf1.Pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };
    warehouse.addShelf(shelf1);

    // Rearrange shelf
    bool rearranged = warehouse.rearrangeShelf(shelf1);
    std::cout << "Shelf rearrangement status: " << (rearranged ? "Success" : "Failed") << std::endl;

    // Pick items from the shelf
    bool pickedItems = warehouse.pickItems("Books", 5);
    std::cout << "Item picking status: " << (pickedItems ? "Success" : "Failed") << std::endl;

    return 0;

}