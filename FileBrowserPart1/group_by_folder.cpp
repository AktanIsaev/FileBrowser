#include "group_by_folder.h"
#include <QDir>
#include <QDirIterator>
#include <QHash>

QList<ItemInfo> GroupByFolder::Explore(const QString &path) const
{
    QDir directory(path);

    // Проверка существования директории
    if (!directory.exists())
    {
        throw std::runtime_error("Directory does not exist: " + path.toStdString());
    }

    QList<ItemInfo> itemList;

    qint64 totalSize = 0;
    QHash<QString, qint64> folderSizes;

    // Считаем размеры файлов в текущей директории
    for (const QFileInfo &fileInfo : directory.entryInfoList(QDir::Files))
    {
        totalSize += fileInfo.size();
    }

    // Добавляем размер текущей директории в itemList сразу
    itemList.append(ItemInfo("(Current Directory)", totalSize, 0)); // Временно ставим totalSize 0

    // Считаем размеры поддиректорий и добавляем их в хэш
    for (const QFileInfo &fileInfo : directory.entryInfoList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDir::Name))
    {
        qint64 size = 0;
        QDirIterator it(fileInfo.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext())
        {
            it.next();
            size += it.fileInfo().size();
        }
        folderSizes.insert(fileInfo.fileName(), size);
        totalSize += size; // Обновляем общий размер
    }

    // Обновляем общий размер текущей директории
    itemList[0] = ItemInfo("(Current Directory)", itemList[0].size(), totalSize);

    // Теперь добавляем все элементы в itemList с корректным общим размером
    for (auto it = folderSizes.begin(); it != folderSizes.end(); ++it)
    {
        itemList.append(ItemInfo(it.key(), it.value(), totalSize));
    }

    return itemList;
}
