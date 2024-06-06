#ifndef GROUP_BY_TYPE_H
#define GROUP_BY_TYPE_H

#include "group_by_strategy.h"

// Класс GroupByType, реализующий конкретную стратегию группировки файлов по типам,
// наследуется от абстрактного базового класса GroupByStrategy
class GroupByType : public GroupByStrategy
{
public:
    // Переопределение виртуального метода Explore() из базового класса.
    // Метод осуществляет группировку файлов в указанной директории по типам.
    // Возвращает список элементов ItemInfo.
    QList<ItemInfo> Explore(const QString &path) const override;
};

#endif // GROUP_BY_TYPE_H

