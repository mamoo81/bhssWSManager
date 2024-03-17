#include "producer.h"

Producer::Producer() {}

Producer::Producer(const int &p_id, const QString &p_name, QObject *parent) :
    QObject(parent),
    m_id(p_id),
    m_name(p_name)
{

}

int Producer::id() const
{
    return m_id;
}

void Producer::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

QString Producer::name() const
{
    return m_name;
}

void Producer::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
