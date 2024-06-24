#include "context.h"  // Подключаем заголовочный файл с определением класса Context

// Реализация метода explore класса Context
QList<ItemInfo> Context::explore(const QString &path) const
{
    // Вызов метода Explore текущей стратегии для исследования директории по указанному пути
    // и возврат результата в виде списка элементов ItemInfo
    return strategy_->Explore(path);
}
