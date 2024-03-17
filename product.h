#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class product : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString barcode READ barcode WRITE setBarcode NOTIFY barcodeChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString fullname READ fullname WRITE setFullname NOTIFY fullnameChanged FINAL)
    Q_PROPERTY(QString imageHASH READ imageHASH WRITE setImageHASH NOTIFY imageHASHChanged FINAL)
    Q_PROPERTY(int unit READ unit WRITE setUnit NOTIFY unitChanged FINAL)
    Q_PROPERTY(double price READ price WRITE setPrice NOTIFY priceChanged FINAL)
    Q_PROPERTY(int category READ category WRITE setCategory NOTIFY categoryChanged FINAL)
    Q_PROPERTY(int subcategory READ subcategory WRITE setSubcategory NOTIFY subcategoryChanged FINAL)
    Q_PROPERTY(int otv READ otv WRITE setOtv NOTIFY otvChanged FINAL)
    Q_PROPERTY(int kdv READ kdv WRITE setKdv NOTIFY kdvChanged FINAL)
    Q_PROPERTY(int producer READ producer WRITE setProducer NOTIFY producerChanged FINAL)
public:
    product(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);

    QString barcode() const;
    void setBarcode(const QString &newBarcode);

    QString name() const;
    void setName(const QString &newName);

    QString fullname() const;
    void setFullname(const QString &newFullname);

    QString imageHASH() const;
    void setImageHASH(const QString &newImageHASH);

    int unit() const;
    void setUnit(int newUnit);

    double price() const;
    void setPrice(double newPrice);

    int category() const;
    void setCategory(int newCategory);

    int subcategory() const;
    void setSubcategory(int newSubcategory);

    int otv() const;
    void setOtv(int newOtv);

    int kdv() const;
    void setKdv(int newKdv);

    int producer() const;
    void setProducer(int newProducer);

signals:
    void idChanged();

    void barcodeChanged();

    void nameChanged();

    void fullnameChanged();

    void imageHASHChanged();

    void unitChanged();

    void priceChanged();

    void categoryChanged();

    void subcategoryChanged();

    void otvChanged();

    void kdvChanged();

    void producerChanged();

private:
    int m_id;
    QString m_barcode;
    QString m_name;
    QString m_fullname;
    QString m_imageHASH;
    int m_unit;
    double m_price;
    int m_category;
    int m_subcategory;
    int m_otv;
    int m_kdv;
    int m_producer;

};

#endif // PRODUCT_H
