#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QtWebSockets/QWebSocket>
#include <QtNetwork/QSslError>

class WebSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketClient(const QUrl ＆url, bool debug = false, QObject *parent = Q_NULLPTR);
    ~WebSocketClient();

public slots:
    void open();
    void close();


Q_SIGNALS:
    void closed();
    void messageReceived(QString message);

private Q_SLOTS:
    void onConnected();
    void onDisConnected();
    void onTextMessageReceived(QString message);

    void onSslErrors(const QList<QSslError> &errors);

private:
    QWebSocket *m_webSocket;
    QUrl m_url;
    bool m_debug;
};


#endif // WEBSOCKETCLIENT_H
