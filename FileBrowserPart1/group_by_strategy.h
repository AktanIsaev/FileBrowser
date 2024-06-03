#ifndef GROUP_BY_STRATEGY_H
#define GROUP_BY_STRATEGY_H

#include <QString>
#include <QList>
#include "item_info.h"

class GroupByStrategy
{
public:
    virtual ~GroupByStrategy() = default;
    virtual QList<ItemInfo> Explore(const QString &path) const = 0;
};

#endif // GROUP_BY_STRATEGY_H
