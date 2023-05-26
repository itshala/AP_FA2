# Warehouse management system
This is a Warehouse Management System that allows you to manage employees, shelves, and pallets within a warehouse. It provides functionality for adding employees, adding shelves, rearranging shelves, and picking items from the shelves.
## About
this warehouse managment system makes use of the following classes
Employee
The Employee class represents an employee in the warehouse. It has the following attributes:

name (std::string): The name of the employee.
busy (bool): Indicates whether the employee is currently busy.
forkliftCertificate (bool): Indicates whether the employee has a forklift certificate.
The Employee class provides the following methods:

Employee(name: std::string, forkliftCertificate: bool): Constructor to initialize the Employee object.
getName(): Returns the name of the employee.
getBusy(): Returns whether the employee is currently busy.
setBusy(busy: bool): Sets the busy status of the employee.
getForkliftCertificate(): Returns whether the employee has a forklift certificate.
setForkliftCertificate(forkliftCertificate: bool): Sets the forklift certificate status of the employee.
Pallet
The Pallet class represents a pallet in the warehouse. It has the following attributes:

itemName (std::string): The name of the item on the pallet.
itemCapacity (int): The maximum capacity of the pallet.
itemCount (int): The current count of items on the pallet.
The Pallet class provides the following methods:

Pallet(itemName: std::string, itemCapacity: int, itemCount: int): Constructor to initialize the Pallet object.
getItemName(): Returns the name of the item on the pallet.
getItemCount(): Returns the current count of items on the pallet.
getRemainingSpace(): Returns the remaining space on the pallet.
reallocateEmptyPallet(itemName: std::string, itemCapacity: int): Reallocates an empty pallet with a new item name and capacity.
takeOne(): Takes one item from the pallet and updates the count.
putOne(): Puts one item onto the pallet and updates the count.
Shelf
The Shelf class represents a shelf in the warehouse. It contains an array of Pallet objects. The maximum number of pallets per shelf is defined by the constant kMaxPallets.

The Shelf class provides the following methods:

Shelf(): Default constructor to initialize an empty shelf.
addPallet(pallet: Pallet): Adds a pallet to the shelf.
swapPallet(slot: int, slot2: int): Swaps two pallets on the shelf based on their slots.
Warehouse
The Warehouse class represents a warehouse and manages employees and shelves. It has the following attributes:

employees (std::vector<Employee>): A vector to store the employees in the warehouse.
shelves (std::vector<Shelf>): A vector to store the shelves in the warehouse.
The Warehouse class provides the following methods:

Warehouse(): Default constructor to initialize an empty warehouse.
addEmployee(employee: Employee): Adds an employee to the warehouse.
addShelf(shelf: Shelf): Adds a shelf to the warehouse.
rearrangeShelf(shelf: Shelf&): Rearranges the pallets on a shelf based on their
## How to run
cloning this repostory is supposed to be enough for running it if youn have the makefile setup, otherwisre i would suggest you to follow the instructions:
for windows:  https://code.visualstudio.com/docs/cpp/config-mingwLinks to an external site. <br> for linux  https://code.visualstudio.com/docs/cpp/config-linuxLinks to an external site.<br>for mac https://brew.shLinks to an external site.