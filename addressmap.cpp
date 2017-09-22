#include "addressmap.h"
//implement

#include <QDebug>

//AddressMap class
template<typename T>
AddressMap<T>::AddressMap()
{

}


template<typename T>
QList<Address> AddressMap<T>::keys() const{
    return addressList;
}


template<typename T>
int AddressMap<T>::findIndex(const Address address) const{
    for(int i=0; i<addressList.length(); ++i){
        Address ad = addressList[i];
        if(address.isSame(ad)){
            return i;
        }

    }

    qDebug() << "no such address";
    return -1;
}


template<typename T>
void AddressMap<T>::insert(const Address &address, const T &value){
   if(contains(address)){
       qDebug() << "this address already extists :" << address.host << " :" << address.port;
       return;
   }
   addressList.append(address);
   map.insert(address, value);
}

template<typename T>
T AddressMap<T>::take(const Address &address){
    int index = findIndex(address);
    Address key = addressList.takeAt(index);
    return map.take(key);
}

template<typename T>
bool AddressMap<T>::contains(Address address) const{
    int index = findIndex(address);

    return index != -1;
}

template<typename T>
const T AddressMap<T>::value(const Address &address, const T defaultValue) const{
    int index = findIndex(address);
    if(index == -1){
        return defaultValue;
    }else{
        return map[addressList[index]];
    }
}


