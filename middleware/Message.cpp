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

    QString ToString() // преобразует объект для отображения в сообщениях
    {                 //формат: (дата)юзер> сообщение
        return QString("(%1)%2> %3").arg(datetime, sender, message);
    }

    QString ToJSON() //возвращает строку в формате JSON
    {
        return QString("{\"sender\":\"%1\","
                       "\"message\":\"%2\","
                       "\"datetime\":\"%3\"}").arg(sender, message, datetime);
    }
};






