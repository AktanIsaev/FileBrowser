#include "item_info.h"
#include <QLocale>
#include <cmath>

ItemInfo::ItemInfo(const QString &name, qint64 size, qint64 totalSize)
    : name_(name), size_(size), totalSize_(totalSize)
{
}

QString ItemInfo::percentage() const
{
    if (totalSize_ == 0)
        return "0.00 %";

    qreal ratio = static_cast<qreal>(size_) / totalSize_;
    if (ratio == 0)
        return "0.00 %";
    if (ratio < 0.01)
        return "< 0.01 %";
    return QString::number(std::floor(ratio * 10000) / 100, 'f', 2) + " %";
}

