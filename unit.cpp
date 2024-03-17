#include "unit.h"

Unit::Unit(QObject *parent) {}

Unit::Unit(const int p_id, const QString p_name, QObject *parent) :
    QObject(parent),
    m_id(p_id),
    m_name(p_name)
{

}

int Unit::id() const
{
    return m_id;
}

void Unit::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString Unit::name() const
{
    return m_name;
}

void Unit::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
