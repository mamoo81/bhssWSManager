#include "subcategory.h"

SubCategory::SubCategory() {}

SubCategory::SubCategory(int p_id, int p_parent, QString p_name, QObject *parent) :
    QObject(parent),
    m_id(p_id),
    m_parent(p_parent),
    m_name(p_name)
{

}

int SubCategory::id() const
{
    return m_id;
}

void SubCategory::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

int SubCategory::parent() const
{
    return m_parent;
}

void SubCategory::setParent(int newParent)
{
    if (m_parent == newParent)
        return;
    m_parent = newParent;
    emit parentChanged();
}

QString SubCategory::name() const
{
    return m_name;
}

void SubCategory::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
