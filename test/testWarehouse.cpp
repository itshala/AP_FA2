#include "include/catch.hpp"

#include "../src/include/warehouse.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////
//                                                           //
//                    Warehouse unittests                    //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
// This file contains all testcases for the Warehouse class. //
// Currently it only contains tests for the rearranging of   //
// shelves. All other Warehouse functions will also need to  //
// be tested. You will have to do this yourself.             //
//                                                           //
// For information on how to write testcases with catch2,    //
// see https://github.com/catchorg/Catch2.                   //
//                                                           //
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//                Functions used in testcases                //
///////////////////////////////////////////////////////////////

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.Pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.Pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.Pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee(std::move(std::string("Bob")), true));

    return warehouse;
}
///////////////////////////////////////////////////////////////
//          Warehouse::pickItems test cases                  //
///////////////////////////////////////////////////////////////

// Test case for picking items successfully
TEST_CASE("Pick items from a shelf successfully") {
    Warehouse warehouse = createMockWarehouse();

    bool result = warehouse.pickItems("Books", 25);

    // Assert that the items were successfully picked
    REQUIRE(result == true);
    // Assert the updated item count on the shelf
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 15);
}

// Test case for trying to pick more items than available
TEST_CASE("Pick more items than available on a shelf") {
    Warehouse warehouse = createMockWarehouse();

    bool result = warehouse.pickItems("Toy Bears", 50);

    // Assert that the items could not be picked due to insufficient count
    REQUIRE(result == false);
    // Assert that the item count on the shelf remains the same
    REQUIRE(warehouse.shelves[2].Pallets[0].getItemCount() == 20);
}

// Test case for trying to pick items from a shelf with no matching item
TEST_CASE("Pick items from a shelf with no matching item") {
    Warehouse warehouse = createMockWarehouse();

    bool result = warehouse.pickItems("Candies", 10);

    // Assert that the items could not be picked as the item is not found on the shelf
    REQUIRE(result == false);
    // Assert that the item count on the shelf remains the same
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 40);
}

///////////////////////////////////////////////////////////////
//           Warehouse::rearrangeShelf test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Rearrange empty shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = Warehouse();
    warehouse.addShelf(Shelf());
    warehouse.addEmployee(Employee(std::move(std::string("Bob")), true));

    // Check if shelf is already arranged.
    // Empty shelf should already be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Empty shelf should still be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 0);
}

TEST_CASE("Rearrange full shelf", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.Pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee(std::move(std::string("Bob")), true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange half filled shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.Pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet()
    };
    
    warehouse.addEmployee(Employee(std::move(std::string("Bob")), true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange shelf without qualified employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.Pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    warehouse.addEmployee(Employee(std::move(std::string("Bob")), false));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 10);
}

TEST_CASE("Rearrange shelf with quallified, but busy, employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.Pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee(std::move(std::string("Bob")), true);
    bert.setBusy(true);

    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.shelves[0].Pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.shelves[0].Pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.shelves[0].Pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.shelves[0].Pallets[3].getItemCount() == 10);
}
