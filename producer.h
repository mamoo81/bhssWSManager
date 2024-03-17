#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>

class Producer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

public:
    Producer();
    Producer(const int &p_id, const QString &p_name, QObject *parent = nullptr);

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

signals:
    void idChanged();

    void nameChanged();

private:
    int m_id;
    QString m_name;
};

#endif // PRODUCER_H
