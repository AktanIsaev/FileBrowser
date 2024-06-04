#ifndef GROUP_BY_FOLDER_H
#define GROUP_BY_FOLDER_H

#include "group_by_strategy.h"

class GroupByFolder : public GroupByStrategy
{
public:
    QList<ItemInfo> Explore(const QString &path) const override;
};

#endif // GROUP_BY_FOLDER_H

