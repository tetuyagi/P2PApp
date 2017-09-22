#include "rudpsessionserver.h"

//SessionData class
SessionData::SessionData(QString name, Address address)
    :name(name), address(address)
{
    state = State::NONE;
}

const QString SessionData::name() const{
    return name;
}

const Address SessionData::address() const{
    return address;
}

const SessionData::State SessionData::state() const{
    return state;
}

void SessionData::setSate(State state){
    this->state = state;
}


//RudpSessionServer class
RudpSessionServer::RudpSessionServer(int port, QHostAddress host, QObject *parent)
    :QObject(parent)
{
    server = new RudpServer(port, host, this);
}

RudpSessionServer::~RudpSessionServer(){
    delete server;
}

const QString RudpSessionServer::name() const{
    return name;
}

void RudpSessionServer::startSession(SessionData session){
    session.setState(SessionData::CONNECTING);
    sessionMap.insert(session.address, &session);
    connect(server, SIGNAL(receivedData(Address, QByteArray)), this, SLOT(processSession(Address, QByteArray)));
}

void RudpSessionServer::stopSession(SessionData session){

}

void RudpSessionServer::update(){
    for(int i=0; i<sessionMap.keys().length(); ++i){
        Address address = sessionMap.keys()[i];
        SessionData session = sessionMap.value(address);
        if(session.state() == SessionData::CONNECTED){
            //keep alive check
            if(session.needKeepAlive()){
                //keep alive
                keepAlive(session);
            }
        }
    }
}

