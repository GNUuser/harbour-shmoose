#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include <QStringList>
#include <Swiften/Swiften.h>
#include "Settings.h"

class DownloadManager;
class Persistence;
class ChatMarkers;
class RosterController;

class MessageHandler : public QObject
{
    Q_OBJECT
public:
    MessageHandler(Persistence* persistence, Settings * settings, RosterController* rosterController, QObject *parent = 0);

    void setupWithClient(Swift::Client* client);

    void sendMessage(QString const &toJid, QString const &message, QString const &type, bool isGroup);
    void sendDisplayedForJid(const QString &jid);

signals:

public slots:
    void slotAppGetsActive(bool active);

private:
    Swift::Client* client_;
    Persistence* persistence_;
    Settings* settings_;

    DownloadManager* downloadManager_;
    ChatMarkers* chatMarkers_;

    bool appIsActive_;
    QStringList unAckedMessageIds_;

    void handleMessageReceived(Swift::Message::ref message);
    void handleStanzaAcked(Swift::Stanza::ref stanza);
    void handleDataReceived(Swift::SafeByteArray data);
};

#endif // MESSAGEHANDLER_H
