#include "category.h"

Category::Category() {}

Category::Category(int p_id, QString p_name, QList<SubCategory *> p_subcategories, QObject *parent) :
    QObject(parent),
    m_id(p_id),
    m_name(p_name),
    m_subCategories(p_subcategories)
{

}

int Category::id() const
{
    return m_id;
}

void Category::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString Category::name() const
{
    return m_name;
}

void Category::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

QList<SubCategory *> Category::subCategories() const
{
    return m_subCategories;
}

void Category::setSubCategories(const QList<SubCategory *> &newSubCategories)
{
    if (m_subCategories == newSubCategories)
        return;
    m_subCategories = newSubCategories;
    emit subCategoriesChanged();
}


