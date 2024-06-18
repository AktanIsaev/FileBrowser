#ifndef CONTEXT_H
#define CONTEXT_H

#include <QString>
#include <QTextStream>
#include <memory>
#include "group_by_strategy.h"

// Определение класса Context, который инкапсулирует стратегию группировки и предоставляет интерфейс для работы с ней
class Context
{
public:
    // Конструктор класса Context, принимающий уникальный указатель на объект класса GroupByStrategy
    Context(std::unique_ptr<GroupByStrategy> strategy)
        : strategy_(std::move(strategy)) {}  // Инициализация поля strategy_ с перемещением указателя

    // Метод для изменения стратегии
    void setStrategy(std::unique_ptr<GroupByStrategy> strategy)
    {
        strategy_ = std::move(strategy);  // Изменение стратегии путем перемещения нового указателя
    }

    // Метод для вывода информации о содержимом одной директории
    void exploreAndPrint(QTextStream &out, const QString &path) const;

    // Метод для вывода информации о содержимом нескольких директорий
    void exploreAndPrint(QTextStream &out, const std::vector<QString> &paths) const;

private:
    std::unique_ptr<GroupByStrategy> strategy_;  // Указатель на объект стратегии
};

#endif // CONTEXT_H
