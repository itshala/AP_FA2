#include <array>
#include "pallet.hpp"
#include "IContainer.hpp"

class Shelf
{
private:
    std::array<Pallet, 4> Pallets;
public:
    Shelf();
    bool swapPallet(int slot, int slot2);

    //Inherited from Icontainer
    bool isEmpty() const ;
    bool isFull() const ;
};


