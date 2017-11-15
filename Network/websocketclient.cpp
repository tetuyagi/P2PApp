#include "websocketclient.h"

//#include <stdio.h>


QT_USE_NAMESPACE

WebSocketClient::WebSocketClient(const QUrl url, bool debug, QObject *parent) :
    QObject(parent),
    m_url(url),
    m_debug(debug)
{
    if (m_debug)
        qDebug() << "WebSocket server:" << url;

    QString origin("test connection");
    m_webSocket = new QWebSocket(origin, QWebSocketProtocol::VersionLatest, this);
    connect(m_webSocket, &QWebSocket::connected, this, &WebSocketClient::onConnected);
    connect(m_webSocket, &QWebSocket::disconnected, this, &WebSocketClient::onDisConnected);

    //system("ls");
/*
    char buf[81];
    FILE *fp = popen("/usr/local/bin/node /Users/tyagi/Documents/nodejs/express-app/github/jankolkmeier/node-upd-hole-punching/client.js", "r");
    while(fgets(buf, 80, fp) != NULL){
        qDebug() << buf;
    }
    pclose(fp);
    */
    typedef void (QWebSocket:: *sslErrorsSignal)(const QList<QSslError> &);
    connect(m_webSocket, static_cast<sslErrorsSignal>(&QWebSocket::sslErrors), this, &WebSocketClient::onSslErrors);


}

WebSocketClient::~WebSocketClient(){
    delete m_webSocket;
}

void WebSocketClient::open(){
    qDebug() << "oepn";
    m_webSocket->open(m_url);
}

void WebSocketClient::close(){
    m_webSocket->close(QWebSocketProtocol::CloseCodeNormal);
}

void WebSocketClient::onConnected()
{
    if (m_debug)
        qDebug() << "WebSocket connected";
    connect(m_webSocket, &QWebSocket::textMessageReceived,
            this, &WebSocketClient::onTextMessageReceived);

}

void WebSocketClient::onDisConnected(){
    if(m_debug){
        qDebug() << "WebSocket disconnected";
    }

    emit closed();
}

void WebSocketClient::onTextMessageReceived(QString message)
{
    if (m_debug)
        qDebug() << "Message received:" << message;

    emit messageReceived(message);
}

void WebSocketClient::onSslErrors(const QList<QSslError> &errors)
{
    Q_UNUSED(errors);

    // WARNING: Never ignore SSL errors in production code.
    // The proper way to handle self-signed certificates is to add a custom root
    // to the CA store.

    qDebug() << "occur ssl errors :" << errors;
    m_webSocket->ignoreSslErrors();
}
