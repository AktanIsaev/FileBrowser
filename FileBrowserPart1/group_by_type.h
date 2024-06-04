#ifndef GROUP_BY_TYPE_H
#define GROUP_BY_TYPE_H

#include "group_by_strategy.h"

class GroupByType : public GroupByStrategy
{
public:
    QList<ItemInfo> Explore(const QString &path) const override;
};

#endif // GROUP_BY_TYPE_H

