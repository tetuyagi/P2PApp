#ifndef RUDPSESSIONSERVER_H
#define RUDPSESSIONSERVER_H

#include "rudpserver.h"
#include "addressmap.h"

class SessionData{
public:
    enum State{
        NONE = -1,
        DISCONNECTED = 0,
        CONNECTED = 1,
        CONNECTING = 2,
        DISCONNECTING = 3
    };

    SessionData(QString name, Address externalAddress);

    void setSate(State state);
    bool needKeepAlive();

    const QString name() const;
    const Address externalAddress() const;
    const Address localAddress() const;
    const State state() const;


private:
    QString name;
    Address externalAddress;
    Address localAddress;
    State state;

};

class SessionMessage{
public:
    enum MessageType{
        NONE = -1,
        KEEP_ALIVE = 0,
        REPLY = 1,
        MAKE_SESSION = 2,
        CLOSE_SESSION = 3,
    };

    SessionMessage();
    const MessageType messageType() const;
    const QString name() const;
    const Address localAddress() const;

private:
    MessageType messageType;
    QString name;
    Address localAddress;

    static SessionMessage parseMessage(QByteArray byteArray);
    static QByteArray makeMessage(MessageType messageType);
};

class RudpSessionServer : public QObject
{
    Q_OBJECT
public:
    explicit RudpSessionServer(QString name, int port, QHostAddress host, QObject *parent = Q_NULLPTR);
    ~RudpSessionServer();

    const QString name() const;

public slots:
    void update();
    void startSession(SessionData session);
    void stopSession(SessionData session);

private:
    RudpServer *server;
    AddressMap<SessionData*> sessionMap;
    QString name;

private slots:
    void receiveMessage(Address, address, QByteArray byteArray);
    void processSession(SessionData session, QByteArray byteArray);
    void keepAlive(SessionData session);

};

#endif // RUDPSESSIONSERVER_H
