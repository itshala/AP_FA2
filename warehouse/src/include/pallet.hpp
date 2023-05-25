#include <iostream>
#include <string>
#include "IContainer.hpp"
class Pallet : public IContainer
{

private:
    std::string itemName;
    int itemCapacity;
    int itemCount;

public:
    Pallet(const std::string& itemName, int itemCapacity, int itemCount);
    Pallet();
    std::string getItemName() const;
    int getItemCount() const;
    int getRemainingSpace() const;
    bool reallocateEmptyPallet(const std::string& itemName, int itemCapacity);
    bool takeOne();
    bool putOne();

    // Inherited from IContainer
    bool isEmpty() const override;
    bool isFull() const override;
};