#include "restapihelper.h"

RestApiHelper::RestApiHelper(QObject *parent) {
    nam = new QNetworkAccessManager(this);

    connect(nam, &QNetworkAccessManager::finished, this, &RestApiHelper::replyFinished);

    setApiBasatURL(QUrl("https://api.basat.dev/"));
    setImgBasatURL(QUrl("https://img.basat.dev/"));

    getUnits();
    getCatsandSubCats();
    getApiProducers();
}

void RestApiHelper::getProduct(QString barcode)
{
    QUrl apiAddress(apiBasatURL().url() + QString("bhss/get/product/%1").arg(barcode));
    request.setUrl(apiAddress);

    nam->get(request);
}

void RestApiHelper::getCatsandSubCats()
{
    QUrl apiAddress(apiBasatURL().url() + QString("bhss/get/categoriesandsubcategories"));
    request.setUrl(apiAddress);

    nam->get(request);
}

void RestApiHelper::getUnits()
{
    QUrl apiAddress(apiBasatURL().url() + QString("bhss/get/units"));
    request.setUrl(apiAddress);

    nam->get(request);
}

void RestApiHelper::getApiProducers()
{
    QUrl apiAddress(apiBasatURL().url() + QString("bhss/get/producers"));
    request.setUrl(apiAddress);

    nam->get(request);
}

void RestApiHelper::replyFinished(QNetworkReply *reply)
{
    const QByteArray json = reply->readAll();
    QJsonDocument jsonReply = QJsonDocument::fromJson(json);

    if(jsonReply.object().contains("getProduct")){

        if(!jsonReply["getProduct"].isNull()){

            QJsonObject jsonProduct = jsonReply["getProduct"].toObject();

            product product;
            product.setId(jsonProduct["id"].toInt());
            product.setBarcode(jsonProduct["barcode"].toString());
            product.setName(jsonProduct["name"].toString());
            product.setFullname(jsonProduct["fullname"].toString());
            product.setUnit(jsonProduct["unit"].toInt());
            product.setPrice(jsonProduct["price"].toDouble());
            product.setCategory(jsonProduct["category"].toInt());
            product.setSubcategory(jsonProduct["subcategory"].toInt());
            product.setKdv(jsonProduct["kdv"].toInt());
            product.setOtv(jsonProduct["otv"].toInt());
            product.setProducer(jsonProduct["producer"].toInt());
            product.setImageHASH(jsonProduct["image-hash"].toString());

            emit productFind(&product);
        }
        else{
            emit productNotFind();
        }
    }
    else if(jsonReply.object().contains("categoriesandsubcategories")){
        QJsonArray jsonCategories = jsonReply["categoriesandsubcategories"].toArray();

        foreach (auto cat, jsonCategories) {
            QJsonObject jsonCategory = cat.toObject();
            QJsonArray jsonSubCategories = jsonCategory["subcategories"].toArray();

            QList<SubCategory*> subcategories;
            foreach (auto sub, jsonSubCategories) {
                QJsonObject jsonSubCategory = sub.toObject();

                subcategories.append(new SubCategory(jsonSubCategory["id"].toInt(), jsonSubCategory["parent"].toInt(), jsonSubCategory["name"].toString(), this));
            }
            m_categoriesANDsubcategories.append(new Category(jsonCategory["id"].toInt(), jsonCategory["name"].toString(), subcategories, this));
        }

        // QList<Category*> categories;
        // foreach (auto item, jsonCategories) {
        //     QJsonObject jsonCategory = item.toObject();

        //     Category category = Category();
        //     category.setId(jsonCategory["id"].toInt());
        //     category.setName(jsonCategory["name"].toString());
        //     QJsonArray jsonSubcategories = jsonCategory["subcategories"].toArray();

        //     QList<SubCategory*> subcategories;
        //     foreach (auto item, jsonSubcategories) {
        //         QJsonObject jsonSubCategory = item.toObject();

        //         SubCategory subcategory;
        //         subcategory.setId(jsonSubCategory["id"].toInt());
        //         subcategory.setParent(jsonSubCategory["parent"].toInt());
        //         subcategory.setName(jsonSubCategory["name"].toString());
        //         subcategories.append(&subcategory);
        //     }
        //     category.setSubCategories(subcategories);
        //     categories.append(&category);
        // }
        emit categoriesFind();
    }
    else if(jsonReply.object().contains("units")){
        QJsonArray jsonArray = jsonReply["units"].toArray();

        foreach (auto arrayItem, jsonArray) {
            QJsonObject obj = arrayItem.toObject();
            m_units.append(new Unit(obj["id"].toInt(), obj["name"].toString(), this));
        }
        emit unitsFind();
    }
    else if(jsonReply.object().contains("producers")){
        QJsonArray jsonArray = jsonReply["producers"].toArray();

        foreach (auto arrayItem, jsonArray) {
            QJsonObject obj = arrayItem.toObject();
            m_producers.append(new Producer(obj["id"].toInt(), obj["name"].toString()));
        }
        emit producersFind();
    }
}

QList<Producer *> RestApiHelper::producers() const
{
    return m_producers;
}

QUrl RestApiHelper::imgBasatURL() const
{
    return m_imgBasatURL;
}

void RestApiHelper::setImgBasatURL(const QUrl &newImgBasatURL)
{
    if (m_imgBasatURL == newImgBasatURL)
        return;
    m_imgBasatURL = newImgBasatURL;
    emit imgBasatURLChanged();
}

QUrl RestApiHelper::apiBasatURL() const
{
    return m_apiBasatURL;
}

void RestApiHelper::setApiBasatURL(const QUrl &newApiBasatURL)
{
    if (m_apiBasatURL == newApiBasatURL)
        return;
    m_apiBasatURL = newApiBasatURL;
    emit apiBasatURLChanged();
}

QList<Unit *> RestApiHelper::units() const
{
    return m_units;
}

QList<Category *> RestApiHelper::categoriesANDsubcategories() const
{
    return m_categoriesANDsubcategories;
}

