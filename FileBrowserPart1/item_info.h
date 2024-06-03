#ifndef ITEM_INFO_H
#define ITEM_INFO_H

#include <QString>

class ItemInfo
{
public:
    ItemInfo(const QString &name, qint64 size, qint64 totalSize);

    const QString &name() const { return name_; }
    qint64 size() const { return size_; }
    QString percentage() const;

private:
    QString name_;
    qint64 size_;
    qint64 totalSize_;
};

#endif // ITEM_INFO_H
