#include <QCoreApplication>  // Для основного приложения Qt
#include <QTextStream>  // Для работы с текстовыми потоками
#include <iostream>  // Для стандартного ввода-вывода
#include <vector>  // Для работы с векторами
#include "context.h"  // Заголовочный файл класса Context
#include "group_by_folder.h"  // Заголовочный файл класса GroupByFolder
#include "group_by_type.h"  // Заголовочный файл класса GroupByType
#include "print_helpers.h"  // Заголовочный файл функций печати и вывода

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);  // Инициализация приложения Qt
    QTextStream cout(stdout);  // Создание текстового потока для вывода в консоль

    // Список путей к директориям, которые необходимо исследовать
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

    // Создание контекста с начальной стратегией группировки по папкам
    Context context(std::make_unique<GroupByFolder>());

    cout << "Grouping by Folder:" << Qt::endl;  // Вывод сообщения о начале группировки по папкам
    for (const auto &path : paths)  // Перебор всех путей
    {
        exploreAndPrint(cout, context, path);  // Исследование и вывод результатов для каждого пути
    }

    // Смена стратегии на группировку по типу файлов
    context.setStrategy(std::make_unique<GroupByType>());

    cout << "Grouping by Type:" << Qt::endl;  // Вывод сообщения о начале группировки по типу файлов
    for (const auto &path : paths)  // Перебор всех путей
    {
        exploreAndPrint(cout, context, path);  // Исследование и вывод результатов для каждого пути
    }

    return app.exec();  // Запуск цикла обработки событий Qt
}
