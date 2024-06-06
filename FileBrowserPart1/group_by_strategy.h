#ifndef GROUP_BY_STRATEGY_H
#define GROUP_BY_STRATEGY_H

#include <QString>
#include <QList>
#include "item_info.h"

// Абстрактный базовый класс GroupByStrategy, определяющий интерфейс стратегий группировки файлов
class GroupByStrategy
{
public:
    // Виртуальный деструктор по умолчанию
    virtual ~GroupByStrategy() = default;

    // Виртуальный метод Explore(), который должен быть переопределен в производных классах.
    // Он принимает путь к директории и возвращает список элементов ItemInfo.
    virtual QList<ItemInfo> Explore(const QString &path) const = 0;
};
#endif // GROUP_BY_STRATEGY_H

