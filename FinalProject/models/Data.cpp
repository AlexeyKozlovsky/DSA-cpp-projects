#include "Data.h"
#include <QStringList>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <QDebug>


bool Data::parseFromJson(QString jsonPath) {
    QFile file;
    file.setFileName(jsonPath);
    qDebug() << QFileInfo(jsonPath).absoluteFilePath();
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    qDebug() << file.exists();

    QStringList propertyNames;
    QStringList propertyKeys;
    QString strReply = file.readAll();
    file.close();
    qDebug() << strReply;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["appDesc"].toArray();
    QJsonValue testValue = jsonObject.value(QString("appDesc"));
    QJsonObject obj2 = testValue.toObject();
    qDebug() << testValue;
    qDebug() << obj2;
    qDebug() << obj2.value(QString("description")).toString();

    QJsonValue subValue = obj2["description"];
    qDebug() << subValue.toString();

    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        propertyNames.append(obj["PropertyName"].toString());
        propertyKeys.append(obj["key"].toString());
    }

    return false;
}

