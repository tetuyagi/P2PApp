#include "rudpsessionserver.h"

//SessionData class
SessionData::SessionData(QString name, Address externalAddress)
    :m_name(name), m_externalAddress(externalAddress), m_localAddress(0, QHostAddress::LocalHost)
{
    m_state = State::NONE;
}

SessionData::SessionData(const SessionData &other) :
m_name(other.name()), m_externalAddress(other.externalAddress()), m_localAddress(other.localAddress()), m_state(other.state())
{
}

const QString SessionData::name() const{
    return m_name;
}

const Address SessionData::externalAddress() const{
    return m_externalAddress;
}

const Address SessionData::localAddress() const{
    return m_localAddress;
}

const SessionData::State SessionData::state() const{
    return m_state;
}

void SessionData::setState(State state){
    m_state = state;
}

bool SessionData::needKeepAlive(){
    return m_state == State::CONNECTED;
}



//SessionMessage class
SessionMessage::SessionMessage() :
m_localAddress(0, QHostAddress::LocalHost), m_externalAddress(0, QHostAddress::LocalHost)
{

}

SessionMessage SessionMessage::parseMessage(QByteArray byteArray){
    
}                               

QByteArray SessionMessage::makeMessage(MessageType messageType){
    
}


//RudpSessionServer class
RudpSessionServer::RudpSessionServer(QString name, int port, QHostAddress host, QObject *parent)
    :QObject(parent), m_name(name)
{
    server = new RudpServer(port, host, this);
}

RudpSessionServer::~RudpSessionServer(){
    delete server;
}

const QString RudpSessionServer::name() const{
    return m_name;
}

void RudpSessionServer::startSession(SessionData session){
    if(sessionMap.contains(session.externalAddress())){
        if(session.state() == (SessionData::NONE || SessionData::DISCONNECTED)){
        }else{
            qDebug() << "not ready to start session";
            return;
        }
        
    }else{
        sessionMap.insert(session.externalAddress(), &session);
        connect(server, SIGNAL(receivedData(Address, QByteArray)), this, SLOT(processSession(Address, QByteArray)));
    }
    
    session.setState(SessionData::CONNECTING);
    QByteArray message("make session");
    server->sendDatagram(message, session.externalAddress().port, session.externalAddress().host);
}

void RudpSessionServer::stopSession(SessionData session){

}

void RudpSessionServer::update(){
    for(int i=0; i<sessionMap.keys().length(); ++i){
        Address address = sessionMap.keys()[i];
        SessionData *session = sessionMap.value(address);
        if(session->state() == SessionData::CONNECTED){
            //keep alive check
            if(session->needKeepAlive()){
                //keep alive
                keepAlive(*session);
            }
        }
    }
}

void RudpSessionServer::receiveMessage(Address address, QByteArray byteArray){
    for(int i=0; i<sessionMap.keys().length(); ++i){
         Address address = sessionMap.keys()[i];
         SessionData session = *sessionMap.value(address);
         processSession(session, byteArray);
     }

}

void RudpSessionServer::processSession(SessionData session, QByteArray byteArray){
    SessionMessage sessionMessage = SessionMessage::parseMessage(byteArray);
    
     
    switch(session.state()){
    case SessionData::DISCONNECTED:
        
        QByteArray message("repply message");
        server->sendDatagram(message, session.externalAddress().port, session.externalAddress().host);
        break;
        
    /*case SessionData::CONNECTING:
        break;
    case SessionData::CONNECTED:
        break;
        
    default:
        break*/
    } 
}

void RudpSessionServer::keepAlive(SessionData session){

}
