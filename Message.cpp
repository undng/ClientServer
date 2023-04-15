#include <QApplication>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


class Message
{
public:
    QString sender;
    QString message;
    QString datetime;

    Message(QString jsonStr)
    {
        QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8());
        QJsonObject json = doc.object();

        sender = json["sender"].toString();
        message = json["message"].toString();
        datetime = json["datetime"].toString();

    }

};






