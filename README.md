# FileBrowser
# Часть 1
В первой части отдельным консольным приложением реализуем основную функцию –  вычисление размера, в зависимости от стратегии.

Общий принцип работы следующий: пользователь указывает директорию, для которой требуется вычислить размер содержимого.
Функция, в зависимости от выбранной стратегии, проводит вычисление, где результатом является набор соответствующих данных, вида

список файлов и папок (только верхнего уровня) / список типов файлов, содержащихся в директории, а также занимаемый ими объём в процентах (точность два знака после запятой; если точности не хватает, а размер элемента не равен нулю, требуется это показать - например, в виде "< 0.01%").

Основная цель – проработка всевозможных условий. С целью доказательства того факта, что всевозможные условия обработаны, требуется подготовить тесты (примеры), на которых будете демонстрировать состоятельность вашей функции.
