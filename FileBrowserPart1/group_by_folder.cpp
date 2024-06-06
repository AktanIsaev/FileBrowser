#include "group_by_folder.h"
#include <QDir>
#include <QDirIterator>
#include <QHash>

// Метод Explore класса GroupByFolder реализует стратегию группировки файлов по папкам
QList<ItemInfo> GroupByFolder::Explore(const QString &path) const
{
    QDir directory(path);  // Создаем объект QDir для работы с указанной директорией

    // Проверка существования директории
    if (!directory.exists())
    {
        // Если директория не существует, выбрасываем исключение с соответствующим сообщением
        throw std::runtime_error("Directory does not exist: " + path.toStdString());
    }

    QList<ItemInfo> itemList;  // Создаем список для хранения информации о файлах и папках

    qint64 totalSize = 0;  // Переменная для хранения общего размера всех файлов
    QHash<QString, qint64> folderSizes;  // Хэш для хранения размеров поддиректорий

    // Считаем размеры файлов в текущей директории
    for (const QFileInfo &fileInfo : directory.entryInfoList(QDir::Files))
    {
        totalSize += fileInfo.size();  // Добавляем размер каждого файла к общему размеру
    }

    // Добавляем размер текущей директории в itemList сразу
    itemList.append(ItemInfo("(Current Directory)", totalSize, 0));  // Временно ставим totalSize 0

    // Считаем размеры поддиректорий и добавляем их в хэш
    for (const QFileInfo &fileInfo : directory.entryInfoList(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDir::Name))
    {
        qint64 size = 0;  // Переменная для хранения размера текущей поддиректории
        QDirIterator it(fileInfo.absoluteFilePath(), QDir::Files, QDirIterator::Subdirectories);  // Итератор для обхода всех файлов в поддиректории
        while (it.hasNext())
        {
            it.next();  // Переходим к следующему файлу
            size += it.fileInfo().size();  // Добавляем размер файла к размеру поддиректории
        }
        folderSizes.insert(fileInfo.fileName(), size);  // Сохраняем размер поддиректории в хэш
        totalSize += size;  // Обновляем общий размер
    }

    // Обновляем общий размер текущей директории
    itemList[0] = ItemInfo("(Current Directory)", itemList[0].size(), totalSize);  // Обновляем элемент с текущей директорией, добавляя общий размер

    // Теперь добавляем все элементы в itemList с корректным общим размером
    for (auto it = folderSizes.begin(); it != folderSizes.end(); ++it)
    {
        itemList.append(ItemInfo(it.key(), it.value(), totalSize));  // Добавляем информацию о поддиректории в список
    }

    return itemList;  // Возвращаем список информации о файлах и папках
}
