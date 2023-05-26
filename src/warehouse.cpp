#pragma once
#include "include/warehouse.hpp"

Warehouse::Warehouse(){
    //initialize the warehouse
}
void Warehouse::addEmployee(const Employee& employee){
    employees.push_back(employee);
}

void Warehouse::addShelf(const Shelf& shelf){
    shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf){
     // Check if there are any employees available with forklift certificates
    for (Employee& employee : employees) {
        if (!employee.getBusy() && employee.getForkliftCertificate()) {
            // Rearrange the pallets on the shelf by itemCount
            std::array<Pallet, 4>& pallets = shelf.Pallets;

            // Sort pallets by itemCount if the shelf is not empty
            if (!pallets.empty()) {
                std::sort(pallets.begin(), pallets.end(),
                          [](const Pallet& a, const Pallet& b) {
                              return a.getItemCount() < b.getItemCount();
                          });

                // Rearrange the pallets using swapPallet function
                for (size_t i = 0; i < pallets.size(); i++) {
                    for (size_t j = i + 1; j < pallets.size(); j++) {
                        if (pallets[i].getItemCount() > pallets[j].getItemCount()) {
                            if (shelf.swapPallet(static_cast<int>(i), static_cast<int>(j))) {
                                // Pallets swapped successfully
                                break;
                            }
                        }
                    }
                }
            }

            return true; // Rearrangement successful
        }
    }

    return false; // No available employee with a forklift certificate
}

bool Warehouse::pickItems(const std::string& itemName, int itemCount){
   //Iterate through the shelves to find the item
   for(Shelf& Shelf : shelves){
        for(Pallet& pallet : Shelf.Pallets){
            if(pallet.getItemName() == itemName && pallet.getItemCount() >= itemCount){
                while (itemCount > 0)
                {
                    if(!pallet.takeOne()){
                        //failed to pick items, rollback changes
                        while (itemCount < pallet.getRemainingSpace())
                        {
                            pallet.putOne();
                            itemCount++;
                        }
                        return false;
                    }
                    itemCount--;
                }
                return true; //Items picked successfully                
            }

    }
   }

}