#include "item_info.h"
#include <QLocale>
#include <cmath>

// Конструктор класса ItemInfo, инициализирует поля объекта значениями переданными в аргументах
ItemInfo::ItemInfo(const QString &name, qint64 size, qint64 totalSize)
    : name_(name), size_(size), totalSize_(totalSize)
{
}

// Метод percentage() возвращает процентное значение размера текущего элемента относительно общего размера
QString ItemInfo::percentage() const
{
    // Если общий размер равен нулю, возвращается строка "0.00 %"
    if (totalSize_ == 0)
        return "0.00 %";

    // Вычисление отношения размера текущего элемента к общему размеру
    qreal ratio = static_cast<qreal>(size_) / totalSize_;

    // Если отношение равно нулю, возвращается строка "0.00 %"
    if (ratio == 0)
        return "0.00 %";

    // Если отношение меньше 0.01, возвращается строка "< 0.01 %"
    if (ratio < 0.01)
        return "< 0.01 %";

    // В остальных случаях возвращается процентное значение,
    // округленное до двух знаков после запятой
    return QString::number(std::floor(ratio * 10000) / 100, 'f', 2) + " %";
}

