#include "pallet.hpp"

Pallet::Pallet(const std::string& itemName, int itemCapacity, int itemCount)
        : itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount){
            // Initialize the pallet
        }

std::string Pallet::getItemName() const{
    return itemName;
}

int Pallet::getItemCount() const{
    return itemCount;
}

int Pallet::getRemainingSpace() const{
    return itemCapacity - itemCount;
}

bool Pallet::reallocateEmptyPallet(const std::string& itemName, int itemCapacity){
    if (isEmpty())
    {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;
        itemCount = 0;
        return true;
    }

    return false;    
}

bool Pallet::takeOne(){
    if (!isEmpty())
    {
        itemCount--;
        return true;
    }
    return false;
}

bool Pallet::putOne(){
    if (!isEmpty())
    {
        itemCount++;
        return true;
    }
    return false;
}

bool Pallet::isEmpty() const{
    return itemCount == 0;
}

bool Pallet::isFull() const{
    return itemCount == itemCapacity;
}