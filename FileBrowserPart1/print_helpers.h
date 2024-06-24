#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include <QTextStream>  // Подключаем заголовочный файл QTextStream из библиотеки Qt для работы с текстовыми потоками
#include "item_info.h"  // Подключаем заголовочный файл item_info.h для работы с классом ItemInfo
#include "context.h"    // Подключаем заголовочный файл context.h для работы с классом Context

// Объявление функции для форматирования размера файла в удобочитаемый вид
QString formatSize(qint64 size);

// Объявление функции для вывода информации о файлах и их размере в указанный поток
void Print(QTextStream &out, const QList<ItemInfo> &itemList);

// Объявление функции для исследования директории с использованием заданного контекста и вывода результатов в поток
void exploreAndPrint(QTextStream &out, Context &context, const QString &path);

#endif // PRINT_HELPERS_H
