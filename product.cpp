#include "product.h"

product::product(QObject *parent) {}

int product::id() const
{
    return m_id;
}

void product::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString product::barcode() const
{
    return m_barcode;
}

void product::setBarcode(const QString &newBarcode)
{
    if (m_barcode == newBarcode)
        return;
    m_barcode = newBarcode;
    emit barcodeChanged();
}

QString product::name() const
{
    return m_name;
}

void product::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QString product::fullname() const
{
    return m_fullname;
}

void product::setFullname(const QString &newFullname)
{
    if (m_fullname == newFullname)
        return;
    m_fullname = newFullname;
    emit fullnameChanged();
}

QString product::imageHASH() const
{
    return m_imageHASH;
}

void product::setImageHASH(const QString &newImageHASH)
{
    if (m_imageHASH == newImageHASH)
        return;
    m_imageHASH = newImageHASH;
    emit imageHASHChanged();
}

int product::unit() const
{
    return m_unit;
}

void product::setUnit(int newUnit)
{
    if (m_unit == newUnit)
        return;
    m_unit = newUnit;
    emit unitChanged();
}

double product::price() const
{
    return m_price;
}

void product::setPrice(double newPrice)
{
    if (qFuzzyCompare(m_price, newPrice))
        return;
    m_price = newPrice;
    emit priceChanged();
}

int product::category() const
{
    return m_category;
}

void product::setCategory(int newCategory)
{
    if (m_category == newCategory)
        return;
    m_category = newCategory;
    emit categoryChanged();
}

int product::subcategory() const
{
    return m_subcategory;
}

void product::setSubcategory(int newSubcategory)
{
    if (m_subcategory == newSubcategory)
        return;
    m_subcategory = newSubcategory;
    emit subcategoryChanged();
}

int product::otv() const
{
    return m_otv;
}

void product::setOtv(int newOtv)
{
    if (m_otv == newOtv)
        return;
    m_otv = newOtv;
    emit otvChanged();
}

int product::kdv() const
{
    return m_kdv;
}

void product::setKdv(int newKdv)
{
    if (m_kdv == newKdv)
        return;
    m_kdv = newKdv;
    emit kdvChanged();
}

int product::producer() const
{
    return m_producer;
}

void product::setProducer(int newProducer)
{
    if (m_producer == newProducer)
        return;
    m_producer = newProducer;
    emit producerChanged();
}
