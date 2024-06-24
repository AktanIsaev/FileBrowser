#ifndef CONTEXT_H
#define CONTEXT_H

#include <QString>  // Подключаем заголовочный файл QString из библиотеки Qt
#include <memory>   // Подключаем заголовочный файл memory для использования std::unique_ptr
#include "group_by_strategy.h"  // Подключаем заголовочный файл для базового класса стратегии группировки

// Определение класса Context, который будет использовать различные стратегии для исследования файловой системы
class Context
{
public:
    // Конструктор класса Context принимает уникальный указатель на объект класса GroupByStrategy
    Context(std::unique_ptr<GroupByStrategy> strategy)
        : strategy_(std::move(strategy)) {}  // Инициализируем поле strategy_ перемещением переданного указателя

    // Метод для изменения стратегии
    void setStrategy(std::unique_ptr<GroupByStrategy> strategy)
    {
        strategy_ = std::move(strategy);  // Изменяем стратегию путем перемещения нового указателя
    }

    // Метод для исследования директории, который возвращает список элементов ItemInfo
    QList<ItemInfo> explore(const QString &path) const;

private:
    std::unique_ptr<GroupByStrategy> strategy_;  // Уникальный указатель на объект стратегии группировки
};

#endif // CONTEXT_H
