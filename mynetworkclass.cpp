#include "mynetworkclass.h"
#include <QUrlQuery>
#include <qjsonobject.h>
MyNetworkClass::MyNetworkClass(QObject *parent) : QObject(parent)
{
    connect(qnam,SIGNAL(finished(QNetworkReply*)),this,SLOT(readyRead(QNetworkReply*)));
}

void MyNetworkClass::makeRequest(QString endPointRequest,QString mpn)
{
    QUrl url = endPointRequest;
    QUrlQuery query;
    QString mpn_completo = "[{\"mpn\":\"" + mpn + "\"}]";

    //-------------------------------------------------
    // Adiciona os itens solicitados a pesquisa (query)
    //-------------------------------------------------
    query.addQueryItem("include","specs");
    query.addQueryItem("apikey","12e227ea");
    query.addQueryItem("queries",mpn_completo);
    query.addQueryItem("pretty_print","true");
    url.setQuery(query.query());
    //-------------------------------------------------

    qnam->get(QNetworkRequest(url));
}

void MyNetworkClass::readyRead(QNetworkReply *reply)
{
    QByteArray myData;
    myData = reply->readAll();
    emit(dataReadyRead(myData));

}
