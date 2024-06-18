#include "context.h"
#include "print_helpers.h"

// Реализация метода exploreAndPrint для одной директории
void Context::exploreAndPrint(QTextStream &out, const QString &path) const
{
    // Вывод сообщения о начале исследования директории
    out << "Exploring directory: " << path << Qt::endl;
    try
    {
        // Попытка исследовать директорию с помощью текущей стратегии и вывести результаты
        Print(out, strategy_->Explore(path));
    }
    catch (const std::runtime_error &error)
    {
        // В случае возникновения ошибки, выводим сообщение об ошибке
        out << "Error: " << error.what() << Qt::endl;
    }
}

// Реализация метода exploreAndPrint для нескольких директорий
void Context::exploreAndPrint(QTextStream &out, const std::vector<QString> &paths) const
{
    // Для каждой директории из списка paths
    for (const auto &path : paths)
    {
        // Вызываем метод exploreAndPrint для одной директории
        exploreAndPrint(out, path);
    }
}
