#ifndef RESTAPIHELPER_H
#define RESTAPIHELPER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "producer.h"
#include "product.h"
#include "category.h"
#include "unit.h"

class RestApiHelper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Category *> categoriesANDsubcategories READ categoriesANDsubcategories NOTIFY categoriesANDsubcategoriesChanged FINAL)
    Q_PROPERTY(QList<Unit *> units READ units NOTIFY unitsChanged FINAL)
    Q_PROPERTY(QUrl apiBasatURL READ apiBasatURL WRITE setApiBasatURL NOTIFY apiBasatURLChanged FINAL)
    Q_PROPERTY(QUrl imgBasatURL READ imgBasatURL WRITE setImgBasatURL NOTIFY imgBasatURLChanged FINAL)
    Q_PROPERTY(QList<Producer *> producers READ producers NOTIFY producersChanged FINAL)

public:
    RestApiHelper(QObject *parent = nullptr);

    Q_INVOKABLE void getProduct(QString barcode);
    Q_INVOKABLE void getCatsandSubCats();
    void getUnits();
    void getApiProducers();

    QList<Category *> categoriesANDsubcategories() const;

    QList<Unit *> units() const;

    QUrl apiBasatURL() const;
    void setApiBasatURL(const QUrl &newApiBasatURL);

    QUrl imgBasatURL() const;
    void setImgBasatURL(const QUrl &newImgBasatURL);

    QList<Producer *> producers() const;

public slots:
    void replyFinished(QNetworkReply *reply);

signals:
    void productFind(product *product);
    void productNotFind();
    void unitsFind();
    void producersFind();
    void categoriesFind();

    void categoriesANDsubcategoriesChanged();

    void unitsChanged();

    void apiBasatURLChanged();

    void imgBasatURLChanged();

    void producersChanged();

private:
    QNetworkAccessManager *nam;
    QNetworkRequest request;
    QList<Category*> m_categoriesANDsubcategories;
    QList<Unit*> m_units;
    QList<Producer*> m_producers;

    QUrl m_apiBasatURL;
    QUrl m_imgBasatURL;
};

#endif // RESTAPIHELPER_H
