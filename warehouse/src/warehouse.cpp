#include "warehouse.hpp"
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
    //Check if there's an available employee with a forklift certificate and not busy
    for (Employee& employee : employees)
    {
        if (employee.getForkliftCertificate() && !employee.getBusy())
        {
            employee.setBusy(true);
            return true;
        }
        
    }
    return false; //no suitable employee found
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