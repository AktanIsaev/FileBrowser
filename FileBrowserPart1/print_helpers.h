#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include <QTextStream>
#include "item_info.h"

// Объявление функции для форматирования размера
QString formatSize(qint64 size);

// Объявление функции для вывода информации о файлах в заданный поток
void Print(QTextStream &out, const QList<ItemInfo> &itemList);

#endif // PRINT_HELPERS_H
