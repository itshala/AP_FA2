#pragma once
#include <array>
#include "pallet.hpp"
#include "IContainer.hpp"

class Shelf
{
public:
    std::array<Pallet, 4> Pallets;
    Shelf();
    bool swapPallet(int slot, int slot2);

    //Inherited from Icontainer
    bool isEmpty() const ;
    bool isFull() const ;
};