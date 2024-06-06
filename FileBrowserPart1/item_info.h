#ifndef ITEM_INFO_H
#define ITEM_INFO_H

#include <QString>

class ItemInfo
{
public:
    ItemInfo(const QString &name, qint64 size, qint64 totalSize);  // Объявление конструктора класса.

    const QString &name() const { return name_; }  // Метод для получения имени элемента.
    qint64 size() const { return size_; }  // Метод для получения размера элемента.
    QString percentage() const;  // Объявление метода для вычисления процентного соотношения.

private:
    QString name_;  // Приватное поле для хранения имени элемента.
    qint64 size_;  // Приватное поле для хранения размера элемента.
    qint64 totalSize_;  // Приватное поле для хранения общего размера.
};

#endif // ITEM_INFO_H
