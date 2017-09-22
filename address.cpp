#include "address.h"

#include <QDebug>


Address::Address(int port, QHostAddress host) :
port(port), host(host)
{

}

bool Address::isSame(Address address) const{
    return (port == address.port && host == address.host);
}

bool Address::operator <(const Address &address) const{
    return false;
}

bool Address::operator >(const Address &address) const{
    return false;
}
