#include "group_by_type.h"
#include "item_info.h"
#include <QDir>
#include <QDirIterator>
#include <QHash>

QList<ItemInfo> GroupByType::Explore(const QString &path) const
{
    QDir directory(path);
    QList<ItemInfo> itemList;

    qint64 totalSize = 0;
    QHash<QString, qint64> hash;

    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        const QFileInfo &fileInfo = it.fileInfo();
        qint64 size = fileInfo.size();
        hash[fileInfo.suffix()] += size;
        totalSize += size;
    }

    QHashIterator<QString, qint64> hashIt(hash);
    while (hashIt.hasNext())
    {
        hashIt.next();
        itemList.append(ItemInfo("*." + hashIt.key(), hashIt.value(), totalSize));
    }

    return itemList;
}
