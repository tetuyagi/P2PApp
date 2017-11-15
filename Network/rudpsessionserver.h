#ifndef RUDPSESSIONSERVER_H
#define RUDPSESSIONSERVER_H

#include <QTimer>
#include <QJsonObject>

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
    SessionData(const SessionData &other);

    void setState(State state);
    bool needKeepAlive();

    const QString name() const;
    const Address externalAddress() const;
    const Address localAddress() const;
    const State state() const;

public slots:
    

private:
    QString m_name;
    Address m_externalAddress;
    Address m_localAddress;
    State m_state;
    QDeadlineTimer deadlineTimer;
    QTimer keepAliveTimer;

};


class SessionMessage{
public:
    enum MessageType{
        NONE = -1,
        
        //他ユーザーとの通信
        KEEP_ALIVE = 0,
        REPLY = 1,
        MAKE_SESSION = 2,
        CLOSE_SESSION = 3,
    };

    SessionMessage();
    const MessageType messageType() const;
    const QString name() const;
    const QList<QString> Names() const;
    const Address localAddress() const;
    const Address externalAddress() const;

    static SessionMessage parseMessage(QByteArray byteArray);
    static QByteArray makeMessage(MessageType messageType);

private:
    MessageType m_messageType;
    QString m_name;
    QList<QString> m_sessionNames;
    Address m_localAddress;
    Address m_externalAddress;

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
    QString m_name;

private slots:
    void receiveMessage(Address address, QByteArray byteArray);
    //void receiveMessage(Address, address, QByteArray byteArray);
    void processSession(SessionData session, QByteArray byteArray);
    void keepAlive(SessionData session);

};

#endif // RUDPSESSIONSERVER_H
