#include <QCoreApplication>
#include <QTextStream>
#include <memory>
#include <vector>
#include <cmath>
#include "group_by_folder.h"
#include "group_by_type.h"

QString formatSize(qint64 size)
{
    static QStringList suffixes = {"bytes", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
    if (size == 0) return "0 bytes";

    const qint64 base = 1024;
    qint64 i = static_cast<qint64>(std::log(size) / std::log(base));
    double num = size / std::pow(base, i);
    return QString("%1 %2").arg(num, 0, 'f', 2).arg(suffixes.at(i));
}

void Print(QTextStream &out, const QList<ItemInfo> &itemList)
{
    out << "  Name" << QString(50 - 4, ' ') << "Size" << QString(15 - 4, ' ') << "Percentage" << Qt::endl;
    out << QString(50 + 15 + 10, '-') << Qt::endl;

    for (const auto &item : itemList)
    {
        out << "  " << item.name().leftJustified(50, ' ');
        qint64 size = item.size();
        QString sizeString = formatSize(size);
        out << sizeString.leftJustified(15, ' ');
        out << item.percentage().rightJustified(10, ' ') << Qt::endl;
    }

    out << Qt::endl;
}

void PrintExample(QTextStream &out, const std::unique_ptr<GroupByStrategy> &strategy, const QString &path)
{
    out << "Exploring directory: " << path << Qt::endl;
    try
    {
        Print(out, strategy->Explore(path));
    }
    catch (const std::runtime_error &error)
    {
        out << "Error: " << error.what() << Qt::endl;
    }
}

void PrintExamples(QTextStream &out, const std::unique_ptr<GroupByStrategy> &strategy, const std::vector<QString> &paths)
{
    for (const auto &path : paths)
    {
        PrintExample(out, strategy, path);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream cout(stdout);

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

    cout << "Grouping by Folder:" << Qt::endl;
    PrintExamples(cout, std::make_unique<GroupByFolder>(), paths);

    cout << "Grouping by Type:" << Qt::endl;
    PrintExamples(cout, std::make_unique<GroupByType>(), paths);

    return app.exec();
}
