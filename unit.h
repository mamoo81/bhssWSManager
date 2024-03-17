#ifndef UNIT_H
#define UNIT_H

#include <QObject>

class Unit: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
public:
    Unit(QObject *parent = nullptr);
    Unit(const int p_id, const QString p_name, QObject *parent = nullptr);

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

#endif // UNIT_H
