#include "group_by_type.h"
#include <QDir>
#include <QDirIterator>
#include <QHash>

// Метод Explore класса GroupByType реализует стратегию группировки файлов по типам
QList<ItemInfo> GroupByType::Explore(const QString &path) const
{
    QDir directory(path);  // Создаем объект QDir для работы с указанной директорией

    // Проверка существования директории
    if (!directory.exists())
    {
        // Если директория не существует, выбрасываем исключение с соответствующим сообщением
        throw std::runtime_error("Directory does not exist: " + path.toStdString());
    }

    QList<ItemInfo> itemList;  // Создаем список для хранения информации о файлах и их типах

    qint64 totalSize = 0;  // Переменная для хранения общего размера всех файлов
    QHash<QString, qint64> hash;  // Хэш для хранения размеров файлов по их типам

    // Итератор для обхода всех файлов в указанной директории и поддиректориях
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();  // Переходим к следующему файлу
        const QFileInfo &fileInfo = it.fileInfo();  // Получаем информацию о файле
        qint64 size = fileInfo.size();  // Получаем размер файла
        hash[fileInfo.suffix()] += size;  // Добавляем размер файла к соответствующему типу в хэш
        totalSize += size;  // Обновляем общий размер
    }

    // Итератор для обхода элементов хэша
    QHashIterator<QString, qint64> hashIt(hash);
    while (hashIt.hasNext())
    {
        hashIt.next();  // Переходим к следующему элементу хэша
        // Добавляем информацию о типе файла в список itemList
        itemList.append(ItemInfo("*." + hashIt.key(), hashIt.value(), totalSize));
    }

    return itemList;  // Возвращаем список информации о файлах и их типах
}
