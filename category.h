#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include "subcategory.h"

class Category : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QList<SubCategory *> subCategories READ subCategories WRITE setSubCategories NOTIFY subCategoriesChanged FINAL)

public:
    Category();
    Category(int p_id, QString p_name, QList<SubCategory*> p_subcategories, QObject *parent = nullptr);

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

    QList<SubCategory *> subCategories() const;
    void setSubCategories(const QList<SubCategory *> &newSubCategories);

signals:
    void idChanged();

    void nameChanged();

    void subCategoriesChanged();

private:
    int m_id;
    QString m_name;
    QList<SubCategory*> m_subCategories;
};

#endif // CATEGORY_H
