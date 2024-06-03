#include "group_by_folder.h"
#include "item_info.h"
#include <QDir>
#include <QDirIterator>

QList<ItemInfo> GroupByFolder::Explore(const QString &path) const
{
    QDir directory(path);
    QList<ItemInfo> itemList;

    qint64 totalSize = 0;
    for (const QFileInfo &fileInfo : directory.entryInfoList(QDir::Files))
    {
        totalSize += fileInfo.size();
    }

    itemList.append(ItemInfo("(Current Directory)", totalSize, totalSize));

    for (const QFileInfo &fileInfo : directory.entryInfoList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDir::Name))
    {
        qint64 size = 0;
        QDirIterator it(fileInfo.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            it.next();
            size += it.fileInfo().size();
        }
        totalSize += size;
        itemList.append(ItemInfo(fileInfo.fileName(), size, totalSize));
    }

    for (auto &item : itemList)
    {
        item = ItemInfo(item.name(), item.size(), totalSize);
    }

    return itemList;
}
