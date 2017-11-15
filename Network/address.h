#ifndef ADDRESS_H
#define ADDRESS_H

#include <QHostAddress>

class Address{
public:
    Address(int port, QHostAddress host);
    int port;
    QHostAddress host;


    bool isSame(Address other) const;
    bool operator <(const Address &address) const;
    bool operator >(const Address &address) const;
};


#endif // ADDRESS_H
