#pragma once
#include "include/shelf.hpp"

Shelf::Shelf(){
    //initialize the shelf with empty pallets
}

bool Shelf::swapPallet(int slot, int slot2){
    if (slot < 0 || slot >= Pallets.size() || slot2 <0 || slot2 >= Pallets.size() )
    {
        return false; //invalid slot index
    }
    //swap indexes
    Pallet temp = Pallets[slot];
    Pallets[slot] = Pallets[slot2];
    Pallets[slot2] = temp;

    return true;
}

bool Shelf::isEmpty() const{
    for (const auto& Pallet : Pallets)
    {
        if (Pallet.getItemCount() != 0)
        {
            return false;
        }
        return true;
    }

}
bool Shelf::isFull() const{
    for (const auto& Pallet : Pallets)
    {
        if(Pallet.getItemCount() == 0){
            return false;
        }
        return true;
    }

}