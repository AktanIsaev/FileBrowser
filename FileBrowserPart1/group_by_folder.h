#ifndef GROUP_BY_FOLDER_H
#define GROUP_BY_FOLDER_H

#include "group_by_strategy.h"

// Класс GroupByFolder, реализующий конкретную стратегию группировки файлов по папкам,
// наследуется от абстрактного базового класса GroupByStrategy
class GroupByFolder : public GroupByStrategy
{
public:
    // Переопределение виртуального метода Explore() из базового класса.
    // Метод осуществляет группировку файлов в указанной директории по папкам.
    // Возвращает список элементов ItemInfo.
    QList<ItemInfo> Explore(const QString &path) const override;
};
#endif // GROUP_BY_FOLDER_H

