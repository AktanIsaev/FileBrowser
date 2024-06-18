#include <QCoreApplication>
#include <QTextStream>

#include "context.h"
#include "group_by_folder.h"
#include "group_by_type.h"
#include "print_helpers.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);  // Создание объекта приложения Qt
    QTextStream cout(stdout);          // Создание текстового потока, связанного со стандартным выводом (консолью)

    // Список путей к тестовым директориям
    std::vector<QString> paths = {
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

    // Создание объекта Context с начальной стратегией группировки по папкам
    Context context(std::make_unique<GroupByFolder>());

    // Вывод заголовка для группировки по папкам
    cout << "Grouping by Folder:" << Qt::endl;

    // Вызов метода exploreAndPrint для вывода информации о содержимом директорий
    // с использованием стратегии группировки по папкам
    context.exploreAndPrint(cout, paths);

    // Смена стратегии на группировку по типам файлов
    context.setStrategy(std::make_unique<GroupByType>());

    // Вывод заголовка для группировки по типам файлов
    cout << "Grouping by Type:" << Qt::endl;

    // Вызов метода exploreAndPrint для вывода информации о содержимом директорий
    // с использованием стратегии группировки по типам файлов
    context.exploreAndPrint(cout, paths);

    // Запуск главного цикла обработки событий приложения
    return app.exec();
}
