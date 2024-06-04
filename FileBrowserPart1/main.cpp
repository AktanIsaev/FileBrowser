#include <QCoreApplication>
#include <QTextStream>
#include <memory>
#include "group_by_folder.h"
#include "group_by_type.h"

void Print(QTextStream &out, const QList<ItemInfo> &itemList)
{
    out << "  Name" << QString(50 - 4, ' ') << "Size" << QString(10 - 4, ' ') << "Percentage" << Qt::endl;
    out << QString(50 + 10 + 10, '-') << Qt::endl;

    for (const auto &item : itemList)
    {
        out << "  " << item.name().leftJustified(50, ' ');
        out << QLocale().formattedDataSize(item.size()).rightJustified(10, ' ');
        out << item.percentage().rightJustified(10, ' ') << Qt::endl;
    }

    out << Qt::endl;
}

void PrintExample(QTextStream &out, const std::unique_ptr<GroupByStrategy> &strategy, const QString &path)
{
    out << "Exploring directory: " << path << Qt::endl;
    Print(out, strategy->Explore(path));
}

void PrintExamples(QTextStream &out, const std::unique_ptr<GroupByStrategy> &strategy)
{
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/X/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/1/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/2/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/3/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/4/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/5/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/6/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/7/");
    PrintExample(out, strategy, "C:/Users/Aktan/Desktop/test/8/");
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream cout(stdout);

    cout << "Grouping by Folder:" << Qt::endl;
    try
    {
        PrintExamples(cout, std::make_unique<GroupByFolder>());
    }
    catch (const std::runtime_error &error)
    {
        cout << "Error: " << error.what() << Qt::endl;
    }

    cout << "Grouping by Type:" << Qt::endl;
    try
    {
        PrintExamples(cout, std::make_unique<GroupByType>());
    }
    catch (const std::runtime_error &error)
    {
        cout << "Error: " << error.what() << Qt::endl;
    }

    return app.exec();
}
