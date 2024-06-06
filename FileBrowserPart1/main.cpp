#include <QCoreApplication>
#include <QTextStream>
#include <memory>
#include <vector>
#include <cmath>
#include "group_by_folder.h"
#include "group_by_type.h"

// Функция для форматирования размера в удобочитаемый вид (байты, КБ, МБ и т.д.)
QString formatSize(qint64 size)
{
    // Список суффиксов для разных единиц измерения размера файла
    static QStringList suffixes = {"bytes", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};

    // Если размер равен нулю, возвращаем "0 bytes"
    if (size == 0) return "0 bytes";

    const qint64 base = 1024;  // Базовая величина для перевода в КБ, МБ и т.д.
    qint64 i = static_cast<qint64>(std::log(size) / std::log(base));  // Определяем индекс для суффикса
    double num = size / std::pow(base, i);  // Вычисляем размер с учетом суффикса

    // Формируем строку с размером и соответствующим суффиксом, округляя до двух знаков после запятой
    return QString("%1 %2").arg(num, 0, 'f', 2).arg(suffixes.at(i));
}

// Функция для вывода информации о файлах в заданный поток
void Print(QTextStream &out, const QList<ItemInfo> &itemList)
{
    // Заголовки таблицы
    out << "  Name" << QString(50 - 4, ' ') << "Size" << QString(15 - 4, ' ') << "Percentage" << Qt::endl;
    out << QString(50 + 15 + 10, '-') << Qt::endl;

    // Вывод информации о каждом элементе в itemList
    for (const auto &item : itemList)
    {
        // Вывод имени файла, выровненного по левому краю
        out << "  " << item.name().leftJustified(50, ' ');
        qint64 size = item.size();  // Получаем размер файла
        QString sizeString = formatSize(size);  // Форматируем размер в удобочитаемый вид
        out << sizeString.leftJustified(15, ' ');  // Выводим размер, выровненный по левому краю
        out << item.percentage().rightJustified(10, ' ') << Qt::endl;  // Выводим процент, выровненный по правому краю
    }

    out << Qt::endl;  // Пустая строка в конце вывода
}

// Функция для вывода информации о содержимом директории с использованием заданной стратегии
void PrintExample(QTextStream &out, const std::unique_ptr<GroupByStrategy> &strategy, const QString &path)
{
    out << "Exploring directory: " << path << Qt::endl;  // Сообщение о начале исследования директории
    try
    {
        Print(out, strategy->Explore(path));  // Вызываем функцию Print для вывода информации о файлах
    }
    catch (const std::runtime_error &error)
    {
        // В случае ошибки выводим сообщение об ошибке
        out << "Error: " << error.what() << Qt::endl;
    }
}

// Функция для вывода информации о содержимом нескольких директорий с использованием заданной стратегии
void PrintExamples(QTextStream &out, const std::unique_ptr<GroupByStrategy> &strategy, const std::vector<QString> &paths)
{
    // Для каждой директории в списке paths
    for (const auto &path : paths)
    {
        // Вызываем функцию PrintExample для вывода информации о содержимом директории
        PrintExample(out, strategy, path);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);  // Создаем объект приложения
    QTextStream cout(stdout);  // Создаем поток вывода, связанный с консолью

    // Список путей к тестовым директориям
    std::vector<QString> paths = {
        "C:/Users/Aktan/Desktop/test/X/",
        "C:/Users/Aktan/Desktop/test/1/",
        "C:/Users/Aktan/Desktop/test/2/",
        "C:/Users/Aktan/Desktop/test/3/",
        "C:/Users/Aktan/Desktop/test/4/",
        "C:/Users/Aktan/Desktop/test/5/",
        "C:/Users/Aktan/Desktop/test/6/",
        "C:/Users/Aktan/Desktop/test/7/",
        "C:/Users/Aktan/Desktop/test/8/",
        "C:/Users/Aktan/Desktop/test/9/"
    };

    // Вывод информации о файлах, сгруппированных по папкам
    cout << "Grouping by Folder:" << Qt::endl;
    PrintExamples(cout, std::make_unique<GroupByFolder>(), paths);

    // Вывод информации о файлах, сгруппированных по типам
    cout << "Grouping by Type:" << Qt::endl;
    PrintExamples(cout, std::make_unique<GroupByType>(), paths);

    return app.exec();  // Запускаем приложение
}
