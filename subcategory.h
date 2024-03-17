#ifndef SUBCATEGORY_H
#define SUBCATEGORY_H

#include <QObject>

class SubCategory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(int parent READ parent WRITE setParent NOTIFY parentChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

public:
    SubCategory();
    SubCategory(int p_id, int p_parent, QString p_name, QObject *parent = nullptr);

    int id() const;
    void setId(int newId);

    int parent() const;
    void setParent(int newParent);

    QString name() const;
    void setName(const QString &newName);

signals:
    void idChanged();

    void parentChanged();

    void nameChanged();

private:
    int m_id;
    int m_parent;
    QString m_name;
};

#endif // SUBCATEGORY_H
