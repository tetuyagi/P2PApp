#ifndef ADDRESSMAP_H
#define ADDRESSMAP_H

#include <QMap>
#include "address.h"


template<typename T>
class AddressMap
{
public:
    AddressMap();

    void insert(const Address &address, const T &value);
    T take(const Address &address);

    QList<Address> keys() const;
    bool contains(Address address) const;

    const T value(const Address &address, const T defaultValue = T()) const;


private:

    QList<Address> addressList;
    QMap<Address, T> map;

    int findIndex(const Address address) const;

};

#include "addressmap.cpp"

#endif // ADDRESSMAP_H
