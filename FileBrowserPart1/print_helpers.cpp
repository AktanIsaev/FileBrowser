#include "print_helpers.h"
#include <cmath>

// Функция для форматирования размера в удобочитаемый вид (байты, КБ, МБ и т.д.)
QString formatSize(qint64 size)
{
    // Список суффиксов для разных единиц измерения размера файла
    static QStringList suffixes = {"bytes", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};

    // Если размер равен нулю, возвращаем "0 bytes"
    if (size == 0) return "0 bytes";

    const qint64 base = 1024;  // Базовая величина для перевода в КБ, МБ и т.д.
    // Определяем индекс для суффикса, используя логарифмическую функцию
    qint64 i = static_cast<qint64>(std::log(size) / std::log(base));
    // Вычисляем размер с учетом суффикса
    double num = size / std::pow(base, i);

    // Формируем строку с размером и соответствующим суффиксом, округляя до двух знаков после запятой
    return QString("%1 %2").arg(num, 0, 'f', 2).arg(suffixes.at(i));
}

// Функция для вывода информации о файлах в заданный поток
void Print(QTextStream &out, const QList<ItemInfo> &itemList)
{
    // Вывод заголовков таблицы
    out << "  Name" << QString(50 - 4, ' ') << "Size" << QString(15 - 4, ' ') << "Percentage" << Qt::endl;
    // Вывод разделителя
    out << QString(50 + 15 + 10, '-') << Qt::endl;

    // Перебор всех элементов списка itemList
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
