#pragma once
#include "mainwindow.h"
#include "question.hpp"
#include <qcontainerfwd.h>

inline void MainWindow::initializeFullPage()
{
    m_fabricQuest->push_back(0, 
        "Проверка 1",
        "Question #1",
        "#include <iostream>\n\nclass MyClass\n{\npublic:\n    MyClass() :\n        value(1)\n    {\n        value = 2;\n    }\n\npublic:\n    int value = 3;\n};\n\nint main(int, char**)\n{\n    MyClass myObject;\n    std::cout << myObject.value << std::endl;\n    return 0;\n}",
        "Правильный ответ",
        "<code>value</code> сначала инициализируется в списке инициализации (<code>value(1)</code>), поэтому in-class инициализатор <code>= 3</code> игнорируется — он применяется только если конструктор сам не проинициализировал поле явно. Затем тело конструктора присваивает <code>value = 2</code>. Итог: выводится <strong>2</strong>. Два блока <code>public:</code> подряд — это не ошибка, модификатор доступа можно указывать сколько угодно раз.",
        QVector<AnswerOption>{
            {"Он не скомпилируется", false},
            {"Выведется 1", false},
            {"Выведется 2", true},
            {"Выведется 3", false}
        }
    );
        m_fabricQuest->push_back(0, 
        "Проверка 2",
        "Question #1",
        "#include <iostream>\n\nclass MyClass\n{\npublic:\n    MyClass() :\n        value(1)\n    {\n        value = 2;\n    }\n\npublic:\n    int value = 3;\n};\n\nint main(int, char**)\n{\n    MyClass myObject;\n    std::cout << myObject.value << std::endl;\n    return 0;\n}",
        "Правильный ответ",
        "<code>value</code> сначала инициализируется в списке инициализации (<code>value(1)</code>), поэтому in-class инициализатор <code>= 3</code> игнорируется — он применяется только если конструктор сам не проинициализировал поле явно. Затем тело конструктора присваивает <code>value = 2</code>. Итог: выводится <strong>2</strong>. Два блока <code>public:</code> подряд — это не ошибка, модификатор доступа можно указывать сколько угодно раз.",
        QVector<AnswerOption>{
            {"Он не скомпилируется", false},
            {"Выведется 1", false},
            {"Выведется 2", true},
            {"Выведется 3", false}
        }
    );
        m_fabricQuest->push_back(0, 
        "Проверка 3",
        "Question #1",
        "#include <iostream>\n\nclass MyClass\n{\npublic:\n    MyClass() :\n        value(1)\n    {\n        value = 2;\n    }\n\npublic:\n    int value = 3;\n};\n\nint main(int, char**)\n{\n    MyClass myObject;\n    std::cout << myObject.value << std::endl;\n    return 0;\n}",
        "Правильный ответ",
        "<code>value</code> сначала инициализируется в списке инициализации (<code>value(1)</code>), поэтому in-class инициализатор <code>= 3</code> игнорируется — он применяется только если конструктор сам не проинициализировал поле явно. Затем тело конструктора присваивает <code>value = 2</code>. Итог: выводится <strong>2</strong>. Два блока <code>public:</code> подряд — это не ошибка, модификатор доступа можно указывать сколько угодно раз.",
        QVector<AnswerOption>{
            {"Он не скомпилируется", false},
            {"Выведется 1", false},
            {"Выведется 2", true},
            {"Выведется 3", false}
        }
    );
}

//     // Вопрос 2 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(1, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Он не скомпилируется", true},
//             {"Выведется 5", false},
//             {"Выведется 42", false},
//             {"Выведется другое число", false}
//         },
//         "Причин две, и любой из них достаточно: 1) метода <code>test</code> в классе не существует — есть только <code>set</code>; 2) даже если исправить вызов на <code>set(42)</code>, метод <code>set</code> помечен <code>const</code>, но изменяет <code>_value</code> — это тоже ошибка компиляции. Кстати, <code>void main</code> вместо <code>int main</code> на некоторых компиляторах допускается как расширение и не является причиной ошибки.",
//         "ВОПРОС 2 ИЗ 40",
//         "#include <iostream>\n\nclass MyClass\n{\npublic:\n    MyClass() = default;\n\n    void set(const int newValue) const {\n        _value = newValue;\n    }\n\n    void print() const {\n        std::cout << _value << std::endl;\n    }\n\nprivate:\n    int _value = 5;\n};\n\nvoid main(int, char**)\n{\n    MyClass myObject;\n    myObject.test(42);\n    myObject.print();\n}"
//     ));

//     // Вопрос 3 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(2, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Он не скомпилируется", false},
//             {"Выведется 5", false},
//             {"Выведется 15", true},
//             {"Выведется 25", false},
//             {"Выведется 50", false}
//         },
//         "<code>static int counter</code> инициализируется один раз и сохраняет значение между вызовами. Цикл выполняется 10 раз, каждый раз <code>++counter</code> увеличивает значение на 1: 5 → 6 → ... → 15. Итоговое значение <code>result</code> после 10-го вызова — <strong>15</strong>.",
//         "ВОПРОС 3 ИЗ 40",
//         "#include <iostream>\n\nint func()\n{\n    static int counter = 5;\n    return ++counter;\n}\n\nint main(int, char**)\n{\n    int result = 0;\n    for (int i = 0; i < 10; ++i) {\n        result = func();\n    }\n\n    std::cout << result << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 4 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(3, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"4242", false},
//             {"3455", true},
//             {"3444", false},
//             {"3242", false}
//         },
//         "С C++17 все побочные эффекты вычисления аргумента гарантированно завершаются до вызова функции. <code>func(value++)</code>: <code>arg=3</code>, но глобальная <code>value</code> уже стала 4 к моменту вызова → печатает «34». <code>func(++value)</code>: <code>value</code> становится 5 до вызова, <code>arg=5</code> → печатает «55». Итог: <strong>3455</strong>. До C++17 порядок был не определён, и на практике часто получали «3444».",
//         "ВОПРОС 4 ИЗ 40",
//         "#include <iostream>\n\nint value = 2;\n\nvoid func(const int arg)\n{\n    std::cout << arg << value;\n}\n\nint main(int, char**)\n{\n    value = 3;\n    func(value++);\n    func(++value);\n    return 0;\n}"
//     ));

//     // Вопрос 5 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(4, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Он не скомпилируется", false},
//             {"Выведется 111", false},
//             {"Выведется 222", false},
//             {"Выведется 333", true},
//             {"Выведется 123", false},
//             {"Выведется 666", false}
//         },
//         "<code>b</code> — это ссылка на <code>a</code> (то же самое место в памяти), а <code>c</code> хранит адрес <code>b</code>, то есть фактически адрес <code>a</code>. Все три записи — <code>a</code>, <code>b</code>, <code>*c</code> — обращаются к одной и той же ячейке памяти. После <code>*c = 3</code> все три выведут <strong>3</strong>, итог: «333».",
//         "ВОПРОС 5 ИЗ 40",
//         "#include <iostream>\n\nint main(int, char**)\n{\n    int a = 1;\n    int &b = a;\n    b = 2;\n    int *c = &b;\n    *c = 3;\n    std::cout << a << b << *c << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 6 — множественный выбор без кода
//     m_factory.addQuestionToPage(5, std::make_shared<QuestPageThree>(
//         "Выберите верные утверждения.",
//         std::vector<Option>{
//             {"Поток может содержать в себе несколько процессов", false},
//             {"Процесс может содержать в себе несколько потоков", true},
//             {"Потоки одного процесса имеют доступ к общей памяти", true},
//             {"Процессы одного потока имеют доступ к общей памяти", false}
//         },
//         "Процесс — единица выделения ресурсов, внутри него может выполняться один или несколько потоков (верно). Все потоки одного процесса разделяют общее адресное пространство — глобальные переменные, кучу, файловые дескрипторы (верно), поэтому нужна синхронизация. Обратное — «поток содержит процессы» — бессмысленно: поток это единица исполнения внутри процесса, а не наоборот. Разные процессы по умолчанию изолированы друг от друга.",
//         "ВОПРОС 6 ИЗ 40 (ВЫБЕРИТЕ НЕСКОЛЬКО ВАРИАНТОВ)"
//     ));

//     // Вопрос 7 — множественный выбор без кода
//     m_factory.addQuestionToPage(6, std::make_shared<QuestPageThree>(
//         "Что в C++17 НЕ может быть virtual?",
//         std::vector<Option>{
//             {"Конструктор", true},
//             {"Деструктор", false},
//             {"Метод", false},
//             {"Статический метод", true},
//             {"Шаблонный метод", true},
//             {"Поле класса", true},
//             {"Аргумент функции", true}
//         },
//         "Конструктор не может быть virtual — у не полностью созданного объекта ещё нет vtable. Статический метод не привязан к экземпляру, поэтому динамическая диспетчеризация неприменима. Шаблонный метод инстанцируется только в момент использования, а vtable фиксируется на этапе компиляции. Поля и аргументы функций — это не функции-члены, к ним <code>virtual</code> вообще неприменимо по смыслу языка. А вот <strong>деструктор</strong> и обычный <strong>метод</strong> — как раз основной случай применения <code>virtual</code>.",
//         "ВОПРОС 7 ИЗ 40 (ВЫБЕРИТЕ НЕСКОЛЬКО ВАРИАНТОВ)"
//     ));

//     // Вопрос 8 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(7, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Выведется «base»", true},
//             {"Выведется «derived»", false},
//             {"Он не скомпилируется", false},
//             {"Сработает std::terminate", false}
//         },
//         "Во время выполнения конструктора <code>BaseClass()</code> объект ещё не стал полноценным <code>DerivedClass</code> — часть, специфичная для наследника, ещё не сконструирована. Поэтому вызов <code>print()</code> внутри базового конструктора разрешается статически, в рамках <code>BaseClass</code>, а не через динамическую диспетчеризацию. Правило: виртуальные вызовы внутри конструкторов/деструкторов ведут себя как невиртуальные. Итог: печатается только <strong>«base»</strong>.",
//         "ВОПРОС 8 ИЗ 40",
//         "#include <iostream>\n\nclass BaseClass\n{\npublic:\n    BaseClass()\n    {\n        print();\n    }\n    virtual ~BaseClass() = default;\n\n    virtual void print()\n    {\n        std::cout << \"base\" << std::endl;\n    }\n};\n\nclass DerivedClass : public BaseClass\n{\npublic:\n    DerivedClass() : BaseClass()\n    {\n    }\n\n    void print() override\n    {\n        std::cout << \"derived\" << std::endl;\n    }\n};\n\nint main(int, char**)\n{\n    BaseClass * ptr = new DerivedClass;\n    delete ptr;\n    return 0;\n}"
//     ));

//     // Вопрос 9 — множественный выбор без кода
//     m_factory.addQuestionToPage(8, std::make_shared<QuestPageThree>(
//         "Какой контейнер наиболее оптимально подойдёт под следующие условия?\n\n• Данные могут добавляться и удаляться.\n• Данные должны сохраняться в отсортированном виде.\n• Доступ к минимальному и максимальному элементам должен осуществляться за константное время O(1).\n• Поиск элемента с нужным значением должен отрабатывать за логарифмическое время O(log(n)).",
//         std::vector<Option>{
//             {"std::array", false},
//             {"std::list", false},
//             {"std::vector", false},
//             {"std::set", true},
//             {"std::forward_list", false},
//             {"std::queue", false},
//             {"std::stack", false}
//         },
//         "<code>std::array</code> — фиксированного размера, вставка/удаление невозможны. <code>std::vector</code> не сортируется автоматически, а вставка/удаление в середину — O(n). <code>std::list</code>/<code>forward_list</code> не сортируются и ищут за O(n). <code>queue</code>/<code>stack</code> — это адаптеры с ограниченным доступом. Только <strong>std::set</strong> (сбалансированное дерево) даёт одновременно: автосортировку, O(1) доступ к min/max через <code>begin()</code>/<code>rbegin()</code>, и O(log n) на поиск, вставку и удаление.",
//         "ВОПРОС 9 ИЗ 40 (ВЫБЕРИТЕ НЕСКОЛЬКО ВАРИАНТОВ)"
//     ));

//     // Вопрос 10 — одиночный выбор без кода
//     m_factory.addQuestionToPage(9, std::make_shared<QuestPageTwo>(
//         "Что будет, если кинуть исключение в деструкторе класса (C++17)?",
//         std::vector<Option>{
//             {"Оно поймается ближайшим catch'ем", false},
//             {"Оно поймается ближайшим catch'ем с типом catch(...) или catch(const std::destroy &)", false},
//             {"Программа не скомпилируется т.к. нельзя кидать исключения в деструкторе", false},
//             {"Сработает std::terminate т.к. деструктор по умолчанию noexcept", true},
//             {"Сработает std::terminate т.к. исключение не будет поймано т.к. объект уничтожается после выхода из области try {...}", false}
//         },
//         "Начиная с C++11 деструкторы неявно объявлены <code>noexcept(true)</code>, если явно не указано иное. Любой <code>throw</code> из noexcept-функции немедленно вызывает <code>std::terminate</code>, минуя все <code>catch</code>-блоки — они просто не успевают сработать. Это защита от неопределённого поведения при одновременной раскрутке двух исключений. <code>std::destroy</code> как тип исключения вообще не существует в стандартной библиотеке.",
//         "ВОПРОС 10 ИЗ 40"
//     ));

//     // Вопрос 11 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(10, std::make_shared<QuestPageOne>(
//         "Как проверить наличие флага (C++17)?",
//         std::vector<Option>{
//             {"&", true},
//             {"|", false},
//             {"^", false},
//             {"?", false},
//             {"~", false},
//             {"&&", false}
//         },
//         "<code>flags & Write</code> = <code>101 & 010</code> = <code>000</code> = 0 (флаг Write отсутствует — корректный результат, т.к. flags=5 содержит только Execute и Read). Побитовое <code>&</code> «вырезает» нужный бит. Оператор <code>|</code> здесь непригоден: <code>flags | Write</code> = <code>101 | 010</code> = <code>111</code> = 7, что почти всегда истинно независимо от реального наличия флага — бессмысленная проверка.",
//         "ВОПРОС 11 ИЗ 40",
//         "enum Flags\n{\n    Execute = 1,\n    Write   = 2,\n    Read    = 4\n};\n\nint main(int, char**)\n{\n    const int flags = 5;\n    if (flags ??? Flags::Write) {\n        // ...\n    }\n    return 0;\n}"
//     ));

//     // Вопрос 12 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(11, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"aabbAB", false},
//             {"acabBA", true},
//             {"abacAB", false},
//             {"aabcBA", false}
//         },
//         "1-й <code>foo()</code>: строится член <code>a</code> внутри <code>B</code>, печатает 'a', x становится 1, исключение брошено — конструктор B не достроен, статический <code>b</code> считается неинициализированным. 2-й <code>foo()</code> (в catch, после печати 'c'): снова строится <code>a</code> ('a'), x=2, исключения нет, достраивается <code>B</code> ('b'). При выходе из main статический <code>b</code> уничтожается: '~B' затем '~A'. Итог: a·c·a·b·B·A = <strong>«acabBA»</strong>.",
//         "ВОПРОС 12 ИЗ 40",
//         "#include <iostream>\n#include <exception>\n\nstatic int x = 0;\n\nclass A\n{\npublic:\n    A() {\n        std::cout << 'a';\n        if (x++ == 0) {\n            throw std::exception();\n        }\n    }\n    ~A() { std::cout << 'A'; }\n};\n\nclass B\n{\npublic:\n    B() { std::cout << 'b'; }\n    ~B() { std::cout << 'B'; }\n\n    A a;\n};\n\nvoid foo() { static B b; }\n\nint main(int, char**)\n{\n    try {\n        foo();\n    } catch (std::exception &) {\n        std::cout << 'c';\n        foo();\n    }\n    return 0;\n}"
//     ));

//     // Вопрос 13 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(12, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"aaa", false},
//             {"bbb", true},
//             {"ccc", false},
//             {"abc", false},
//             {"aab", false},
//             {"abb", false},
//             {"acb", false}
//         },
//         "<code>decltype(c1)</code> — просто имя переменной, тип <code>char</code>, <code>c2</code> независимая копия. <code>decltype((c1))</code> — выражение в дополнительных скобках трактуется как lvalue, тип становится <code>char&</code>, значит <code>c3</code> это ссылка на <code>c1</code>! <code>++c2</code> меняет только c2 → 'b'. <code>++c3</code> меняет саму <code>c1</code> → 'b'. К выводу: c1='b', c2='b', c3=c1='b'. Итог: <strong>«bbb»</strong>.",
//         "ВОПРОС 13 ИЗ 40",
//         "#include <iostream>\n\nint main(int, char**)\n{\n    char c1 = 'a';\n    decltype(c1) c2 = c1;\n    ++c2;\n    decltype((c1)) c3 = c1;\n    ++c3;\n\n    std::cout << c1 << c2 << c3 << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 14 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(13, std::make_shared<QuestPageOne>(
//         "Нужен ли в следующем коде thread.join()?",
//         std::vector<Option>{
//             {"Да, т.к. иначе программа не скомпилируется", false},
//             {"Да, т.к. иначе программа упадёт с std::terminate", true},
//             {"Да, т.к. иначе поток не завершится и будет утечка памяти, но программа завершится корректно", false},
//             {"Нет, т.к. std::thread это класс и в деструкторе всё будет корректно завершено", false},
//             {"Нет, т.к. поток завершается раньше своего уничтожения и программа завершится корректно", false}
//         },
//         "<code>joinable()</code> проверяет, был ли вызван <code>join()</code>/<code>detach()</code> — и это никак не связано с тем, закончил ли реальный поток ОС свою работу. Даже если дочерний поток физически завершился раньше (2с < 5с), <code>joinable()</code> всё равно вернёт <code>true</code>. Деструктор <code>std::thread</code> видит это и вызывает <code>std::terminate</code>, независимо от фактического состояния потока.",
//         "ВОПРОС 14 ИЗ 40",
//         "#include <thread>\n\nint main(int, char**)\n{\n    std::thread thread([]() {\n        std::this_thread::sleep_for(std::chrono::seconds(2));\n    });\n    std::this_thread::sleep_for(std::chrono::seconds(5));\n    // thread.join(); ?\n    return 0;\n}"
//     ));

//     // Вопрос 15 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(14, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Выведется 1", false},
//             {"Выведется 2", true},
//             {"Сработает std::terminate", false}
//         },
//         "Работает принцип SFINAE (Substitution Failure Is Not An Error). Первая перегрузка требует <code>typename T::info</code> как тип возврата — у <code>int</code> нет вложенного типа <code>info</code>, подстановка проваливается. Так как ошибка возникает именно в подстановке шаблонных параметров, компилятор молча исключает эту перегрузку, а не выдаёт ошибку. Остаётся только вариативная <code>foo(...)</code>, которая печатает <strong>2</strong>.",
//         "ВОПРОС 15 ИЗ 40",
//         "#include <iostream>\n\ntemplate <typename T>\ntypename T::info foo(T t)\n{\n    std::cout << 1 << std::endl;\n    return static_cast<typename T::Info>(t);\n}\n\ntemplate <typename ...>\nvoid foo(...)\n{\n    std::cout << 2 << std::endl;\n}\n\nint main(int, char**)\n{\n    int a = 322;\n    foo(a);\n    return 0;\n}"
//     ));

//     // Вопрос 16 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(15, std::make_shared<QuestPageOne>(
//         "Какую идиому описывает следующий код (C++17)?",
//         std::vector<Option>{
//             {"SFINAE", false},
//             {"PIMPL", false},
//             {"CRTP", true},
//             {"COW", false},
//             {"RAII", false}
//         },
//         "Производный класс наследуется от шаблонного базового класса, передавая самого себя как параметр шаблона: <code>Derived : public Base&lt;Derived&gt;</code>. Это и есть CRTP (Curiously Recurring Template Pattern). Базовый класс делает <code>static_cast&lt;T*&gt;(this)</code>, получая доступ к методам наследника без единой виртуальной функции — статический полиморфизм без накладных расходов на vtable.",
//         "ВОПРОС 16 ИЗ 40",
//         "#include <iostream>\n\ntemplate <class T>\nstruct Base\n{\n    void doJob()\n    {\n        static_cast<T*>(this)->impl();\n    }\n};\n\nstruct Derived : public Base<Derived>\n{\n    void impl()\n    {\n        std::cout << \"Derived\" << std::endl;\n    }\n};\n\nint main(int, char**)\n{\n    Derived object;\n    object.doJob();\n    return 0;\n}"
//     ));

//     // Вопрос 17 — множественный выбор с кодом
//     m_factory.addQuestionToPage(16, std::make_shared<QuestPageThree>(
//         "Какие варианты можно подставить вместо знаков вопроса в следующем коде (C++17)? Сигнатура функции fclose указана в комментарии.",
//         std::vector<Option>{
//             {"decltype(&fclose)", true},
//             {"int(*)(FILE*)", true},
//             {"std::function<int(FILE*)>", true},
//             {"void(*)(FILE*)", false}
//         },
//         "<code>decltype(&fclose)</code> — компилятор сам выводит точный тип указателя на функцию, самый идиоматичный вариант. <code>int(*)(FILE*)</code> — явно прописанный тип, совпадающий с реальной сигнатурой. <code>std::function&lt;int(FILE*)&gt;</code> — тоже подходит, хотя добавляет накладные расходы. А вот <code>void(*)(FILE*)</code> <strong>не компилируется</strong>: реальная сигнатура <code>fclose</code> возвращает <code>int</code>, а не <code>void</code> — указатели на функции требуют точного совпадения сигнатуры, включая тип возврата.",
//         "ВОПРОС 17 ИЗ 40 (ВЫБЕРИТЕ НЕСКОЛЬКО ВАРИАНТОВ)",
//         "#include <stdio.h>\n#include <memory>\n#include <functional>\n\nvoid read()\n{\n    // int __cdecl fclose(FILE *_File);\n    std::unique_ptr<FILE, ???> file(fopen(\"some_file.txt\", \"r\"), &fclose);\n    if (!file) {\n        return;\n    }\n\n    if (fgetc(file.get()) == '\\n') {\n        return;\n    }\n\n    // ...\n}"
//     ));

//     // Вопрос 18 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(17, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Он не скомпилируется", false},
//             {"Выведется «1-0», затем «2-0», затем «3.3-0»", false},
//             {"Выведется «1-0», затем «2-1», затем «3.3-0»", true},
//             {"Выведется «1-0», затем «2-1», затем «3.3-2»", false},
//             {"Выведется «1-2», затем «2-3», затем «3.3-4»", false}
//         },
//         "Шаблон генерирует отдельную функцию для каждой инстанциации типа. <code>test&lt;int&gt;</code> и <code>test&lt;double&gt;</code> — это две разные функции в бинарном коде, у каждой своя независимая статическая <code>count</code>. Вызовы <code>test&lt;int&gt;(1)</code> и <code>test&lt;int&gt;(2)</code> используют общий счётчик (0, затем 1), а <code>test&lt;double&gt;(3.3)</code> начинает со своего собственного счётчика с нуля. Итог: <strong>«1-0», «2-1», «3.3-0»</strong>.",
//         "ВОПРОС 18 ИЗ 40",
//         "#include <iostream>\n\ntemplate <typename T>\nvoid test(const T & value)\n{\n    static int count = 0;\n    std::cout << value << \"-\" << count << std::endl;\n    ++count;\n}\n\nint main(int, char**)\n{\n    test<int>(1);\n    test<int>(2);\n    test<double>(3.3);\n    return 0;\n}"
//     ));

//     // Вопрос 19 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(18, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)? Данный код будет компилироваться на разных компиляторах с разными соглашениями о вызовах.",
//         std::vector<Option>{
//             {"Программа не скомпилируется т.к. конструкция return ++a; не имеет смысла.", false},
//             {"Программа скомпилируется и будет работать корректно. Сначала выведется «live», затем «catch».", false},
//             {"Выведется «catch», но возможна утечка памяти.", false},
//             {"Выведется «catch», программа работает корректно, утечки памяти нет.", true},
//             {"Сработает std::terminate, программа упадёт в процессе выполнения, возможна утечка памяти.", false},
//             {"Сработает std::terminate, программа упадёт в процессе выполнения, утечки памяти нет.", false}
//         },
//         "До C++17 порядок вычисления аргументов функции мог чередоваться, что теоретически позволяло утечку: выделить <code>new int</code>, затем упасть в <code>foo(4)</code> до того, как указатель окажется под защитой <code>unique_ptr</code>. С C++17 (P0145) вычисление каждого аргумента гарантированно неделимо относительно других — если начали конструировать <code>unique_ptr</code>, оно будет завершено целиком до перехода к следующему аргументу. Поэтому независимо от порядка (который всё ещё зависит от компилятора/ABI), утечка невозможна: <code>foo(4)</code> бросает исключение, печатается «catch», утечки нет — проверено valgrind.",
//         "ВОПРОС 19 ИЗ 40",
//         "#include <memory>\n#include <iostream>\n#include <exception>\n\nint foo(int a)\n{\n    if (a > 3) {\n        throw std::exception();\n    }\n    return ++a;\n}\n\nvoid bar(std::unique_ptr<int> ptr, int value)\n{\n    std::cout << \"live\" << std::endl;\n}\n\nint main(int, char**)\n{\n    try {\n        bar(std::unique_ptr<int>(new int), foo(4));\n    } catch (...) {\n        std::cout << \"catch\" << std::endl;\n    }\n    return 0;\n}"
//     ));

//     // Вопрос 20 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(19, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"A ~A", true},
//             {"A A& ~A ~A", false},
//             {"A A& =A& ~A ~A", false},
//             {"Он не скомпилируется", false}
//         },
//         "Это NRVO (Named Return Value Optimization). Локальный объект <code>a</code> внутри <code>createA()</code> конструируется сразу в том месте памяти, куда должен попасть результат в <code>main</code> — они физически один и тот же объект, копирования не происходит вовсе. Все современные компиляторы применяют эту оптимизацию (проверено флагом <code>-fno-elide-constructors</code>, который показывает «наивный» вариант «A A& ~A ~A»). Итог с оптимизацией: <strong>«A ~A»</strong> — один конструктор, один деструктор.",
//         "ВОПРОС 20 ИЗ 40",
//         "#include <iostream>\n#include <type_traits>\n\nstruct A\n{\n    A() {\n        std::cout << \"A \";\n    }\n    A(const A&) {\n        std::cout << \"A& \";\n    }\n    A& operator= (const A&) {\n        std::cout << \"=A& \";\n        return *this;\n    }\n    ~A() {\n        std::cout << \"~A \";\n    }\n};\n\nA createA()\n{\n    A a;\n    return a;\n}\n\nint main(int, char**)\n{\n    A a = createA();\n    return 0;\n}"
//     ));

//     // Вопрос 21 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(20, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"Выведется «ctor»", false},
//             {"Выведется «ctor move»", true},
//             {"Выведется «ctor copy»", false},
//             {"Выведется «ctor move copy»", false}
//         },
//         "Классическая ловушка: оборачивание возвращаемой переменной в <code>std::move()</code> отключает NRVO! Компилятор больше не может считать <code>a</code> тем же объектом, что и результат функции, — он видит явное приведение к rvalue-ссылке и обязан вызвать конструктор перемещения. Итог: конструктор по умолчанию печатает «ctor», затем move-конструктор печатает «move». Правило: <strong>никогда не оборачивайте return в std::move</strong> — это делает код медленнее, а не быстрее.",
//         "ВОПРОС 21 ИЗ 40",
//         "#include <iostream>\n#include <utility>\n\nstruct A {\n    A() { std::cout << \"ctor \"; }\n    A(const A&) { std::cout << \"copy \"; }\n    A(A&&) noexcept { std::cout << \"move \"; }\n};\n\nA createA() {\n    A a;\n    return std::move(a);\n}\n\nint main() {\n    A a = createA();\n    return 0;\n}"
//     ));

//     // Вопрос 22 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(21, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Выведется 11", false},
//             {"Выведется 10", false},
//             {"Программа не скомпилируется", false},
//             {"Неопределённое поведение (undefined behavior)", true}
//         },
//         "Лямбда захватывает <code>x</code> по ссылке (<code>[&x]</code>). Но <code>x</code> — локальная переменная <code>makeCounter()</code>, которая уничтожается сразу после выхода из функции. Возвращаемая лямбда хранит dangling-ссылку на уже не существующий объект. При вызове <code>counter()</code> происходит обращение к освобождённой памяти стека — классический пример UB, на практике часто приводит к segfault или произвольному «мусорному» значению.",
//         "ВОПРОС 22 ИЗ 40",
//         "#include <iostream>\n#include <functional>\n\nstd::function<int()> makeCounter() {\n    int x = 10;\n    return [&x]() { return ++x; };\n}\n\nint main() {\n    auto counter = makeCounter();\n    std::cout << counter() << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 23 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(22, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"42 -1", true},
//             {"42 0", false},
//             {"0 -1", false},
//             {"Программа не скомпилируется", false}
//         },
//         "<code>std::optional&lt;T&gt;</code> — обёртка, которая может либо содержать значение, либо быть пустой (<code>std::nullopt</code>), без использования специальных «магических» значений вроде -1 или nullptr. <code>value_or(x)</code> возвращает хранимое значение, если оно есть, иначе — переданное значение по умолчанию. <code>r1</code> содержит 42, <code>r2</code> пуст → возвращает -1. Итог: <strong>«42 -1»</strong>.",
//         "ВОПРОС 23 ИЗ 40",
//         "#include <iostream>\n#include <optional>\n\nstd::optional<int> find(bool ok) {\n    if (ok) return 42;\n    return std::nullopt;\n}\n\nint main() {\n    auto r1 = find(true);\n    auto r2 = find(false);\n    std::cout << r1.value_or(-1) << \" \" << r2.value_or(-1) << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 24 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(23, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"100 2 3", true},
//             {"1 2 3", false},
//             {"100 100 100", false},
//             {"Программа не скомпилируется", false}
//         },
//         "Structured bindings (<code>auto [a, b, c]</code>) — фича C++17 — распаковывают <code>std::tuple</code> в независимые именованные переменные-копии. <code>a</code>, <code>b</code>, <code>c</code> — это отдельные объекты, изменение одного не влияет на другие. После <code>a = 100</code>: <strong>«100 2 3»</strong>.",
//         "ВОПРОС 24 ИЗ 40",
//         "#include <iostream>\n#include <tuple>\n\nstd::tuple<int, int, int> getValues() {\n    return {1, 2, 3};\n}\n\nint main() {\n    auto [a, b, c] = getValues();\n    a = 100;\n    std::cout << a << \" \" << b << \" \" << c << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 25 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(24, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"«value: 5» затем «pointer: 5»", true},
//             {"Программа не скомпилируется, т.к. *value невалидно для int", false},
//             {"Сработает std::terminate", false},
//             {"«pointer: 5» затем «value: 5»", false}
//         },
//         "<code>if constexpr</code> (фича C++17) отбрасывает неиспользуемую ветвь на этапе компиляции — код внутри неё даже не компилируется для конкретной инстанциации. Для <code>T=int</code> ветка с <code>*value</code> просто не компилируется — компилятор её не видит. Поэтому <code>print(x)</code> печатает «value: 5», а <code>print(&x)</code> (T=int*) печатает «pointer: 5», разыменовывая указатель без ошибок.",
//         "ВОПРОС 25 ИЗ 40",
//         "#include <iostream>\n#include <type_traits>\n\ntemplate <typename T>\nvoid print(T value) {\n    if constexpr (std::is_pointer_v<T>) {\n        std::cout << \"pointer: \" << *value << std::endl;\n    } else {\n        std::cout << \"value: \" << value << std::endl;\n    }\n}\n\nint main() {\n    int x = 5;\n    print(x);\n    print(&x);\n    return 0;\n}"
//     ));

//     // Вопрос 26 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(25, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Выведется 42", true},
//             {"Выведется 1", false},
//             {"Он не скомпилируется (неоднозначность доступа к value)", false}
//         },
//         "Ключевое слово <code>virtual</code> перед <code>Base</code> решает классическую «проблему ромба»: <code>Left</code> и <code>Right</code> разделяют один общий подобъект <code>Base</code>, а не два независимых. Поэтому <code>b.value</code> однозначен и присваивание работает корректно — <strong>42</strong>. Если убрать оба <code>virtual</code>, у <code>Bottom</code> окажется два разных подобъекта <code>Base</code> (по одному от каждого родителя), и обращение <code>b.value</code> станет неоднозначным — компиляция упадёт с ошибкой «request for member is ambiguous» (проверено).",
//         "ВОПРОС 26 ИЗ 40",
//         "#include <iostream>\n\nstruct Base {\n    int value = 1;\n};\n\nstruct Left : virtual Base {};\nstruct Right : virtual Base {};\nstruct Bottom : Left, Right {};\n\nint main() {\n    Bottom b;\n    b.value = 42;\n    std::cout << b.value << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 27 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(26, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"Он не скомпилируется", false},
//             {"Выведется 0", false},
//             {"Выведется 3", true},
//             {"Выведется 42", false}
//         },
//         "Ключевое слово <code>mutable</code> позволяет изменять поле даже внутри <code>const</code>-метода и даже у <code>const</code>-объекта. Несмотря на то что <code>c</code> объявлен <code>const Cache</code>, каждый вызов <code>get()</code> увеличивает <code>accessCount</code> — он специально помечен <code>mutable</code> именно для таких случаев (счётчики обращений, кэширование, ленивая инициализация). После трёх вызовов: <strong>3</strong>.",
//         "ВОПРОС 27 ИЗ 40",
//         "#include <iostream>\n\nclass Cache {\npublic:\n    int get() const {\n        ++accessCount;\n        return value;\n    }\nprivate:\n    int value = 42;\n    mutable int accessCount = 0;\npublic:\n    int getAccessCount() const { return accessCount; }\n};\n\nint main() {\n    const Cache c;\n    c.get();\n    c.get();\n    c.get();\n    std::cout << c.getAccessCount() << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 28 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(27, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"«template T&&» затем «template T&&»", false},
//             {"«template T&&» затем «int&&»", true},
//             {"«int&&» затем «int&&»", false},
//             {"Программа не скомпилируется", false}
//         },
//         "<code>func(x)</code>: <code>x</code> — lvalue, для него подходит только шаблонная перегрузка с универсальной ссылкой (<code>T&&</code> выводится как <code>T=int&</code>), обычная <code>func(int&&)</code> не может принять lvalue. <code>func(10)</code>: <code>10</code> — rvalue, и здесь уже конкурируют обе перегрузки, но нешаблонная <code>func(int&&)</code> побеждает, так как при равном соответствии компилятор предпочитает не-шаблонную функцию. Итог: <strong>«template T&&» затем «int&&»</strong>.",
//         "ВОПРОС 28 ИЗ 40",
//         "#include <iostream>\n\ntemplate <typename T>\nvoid func(T&& arg) {\n    std::cout << \"template T&&\" << std::endl;\n}\n\nvoid func(int&& arg) {\n    std::cout << \"int&&\" << std::endl;\n}\n\nint main() {\n    int x = 5;\n    func(x);\n    func(10);\n    return 0;\n}"
//     ));

//     // Вопрос 29 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(28, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"Выведется 10", false},
//             {"Выведется 100", false},
//             {"Выведется 200", true},
//             {"Он не скомпилируется", false}
//         },
//         "<code>auto</code> отбрасывает ссылочность типа возврата — <code>a</code> становится независимой копией <code>int</code>, и <code>a = 100</code> не влияет на <code>x</code>. <code>decltype(auto)</code>, напротив, сохраняет точный тип выражения — здесь это <code>int&</code>, так что <code>b</code> реально является ссылкой на <code>x</code>. <code>b = 200</code> меняет саму глобальную <code>x</code>. Итог: <strong>200</strong>.",
//         "ВОПРОС 29 ИЗ 40",
//         "#include <iostream>\n\nint x = 10;\n\nint& getRef() {\n    return x;\n}\n\nint main() {\n    auto a = getRef();\n    decltype(auto) b = getRef();\n\n    a = 100;\n    b = 200;\n\n    std::cout << x << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 30 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(29, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"v1 size: 5, v2 size: 5", false},
//             {"v1 size: 5, v2 size: 2", true},
//             {"v1 size: 2, v2 size: 5", false},
//             {"Он не скомпилируется", false}
//         },
//         "<code>v1(5, 10)</code> — вызов через круглые скобки однозначно выбирает конструктор «размер, значение»: 5 элементов, каждый равен 10. <code>v2{5, 10}</code> — фигурные скобки предпочитают конструктор от <code>std::initializer_list</code>, если он существует и подходит: получаются ровно 2 элемента со значениями 5 и 10. Итог: <strong>v1 size: 5, v2 size: 2</strong> — классическая ловушка `()` vs `{}` при создании контейнеров.",
//         "ВОПРОС 30 ИЗ 40",
//         "#include <iostream>\n#include <vector>\n\nint main() {\n    std::vector<int> v1(5, 10);\n    std::vector<int> v2{5, 10};\n\n    std::cout << \"v1 size: \" << v1.size() << std::endl;\n    std::cout << \"v2 size: \" << v2.size() << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 31 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(30, std::make_shared<QuestPageOne>(
//         "Почему при добавлении третьего элемента в std::vector (вызывающего рост capacity) элементы перемещаются (move), а не копируются (copy)?",
//         std::vector<Option>{
//             {"Потому что move всегда быстрее copy", false},
//             {"Потому что move-конструктор помечен noexcept, а vector использует move только если это безопасно (не бросает исключений), иначе используется copy", true},
//             {"Потому что vector всегда использует move, если он определён, независимо от noexcept", false},
//             {"Программа не скомпилируется", false}
//         },
//         "При росте <code>capacity</code> vector переносит уже хранящиеся элементы в новый, больший блок памяти. Если бы копирование прервалось исключением на середине — старые элементы уже разрушены, новые не достроены, состояние было бы невосстановимо. Поэтому <code>std::vector</code> использует move только если move-конструктор помечен <code>noexcept</code> (гарантия, что перенос не бросит исключение) — иначе, ради строгой гарантии безопасности исключений, используется <em>copy</em>, даже если move определён.",
//         "ВОПРОС 31 ИЗ 40",
//         "#include <iostream>\n#include <vector>\n\nstruct A {\n    int id;\n    A(int i) : id(i) {}\n    A(const A& other) : id(other.id) {\n        std::cout << \"copy(\" << id << \") \";\n    }\n    A(A&& other) noexcept : id(other.id) {\n        std::cout << \"move(\" << id << \") \";\n    }\n};\n\nint main() {\n    std::vector<A> v;\n    v.emplace_back(1);\n    v.emplace_back(2);\n    v.emplace_back(3); // здесь происходит рост capacity\n    return 0;\n}"
//     ));

//     // Вопрос 32 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(31, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"1 1 2", true},
//             {"0 1 2", false},
//             {"1 2 2", false},
//             {"0 0 1", false}
//         },
//         "Префиксный <code>++c</code>: увеличивает value до 1 и возвращает ссылку на текущий объект → <code>a.value = 1</code>. Постфиксный <code>c++</code>: сохраняет копию <em>до</em> инкремента (value=1), затем увеличивает c.value до 2, возвращает сохранённую копию → <code>b.value = 1</code>, <code>c.value = 2</code>. Итог: <strong>«1 1 2»</strong>.",
//         "ВОПРОС 32 ИЗ 40",
//         "#include <iostream>\n\nclass Counter {\npublic:\n    Counter& operator++() {\n        ++value;\n        return *this;\n    }\n    Counter operator++(int) {\n        Counter temp = *this;\n        ++value;\n        return temp;\n    }\n    int value = 0;\n};\n\nint main() {\n    Counter c;\n    Counter a = ++c;\n    Counter b = c++;\n    std::cout << a.value << \" \" << b.value << \" \" << c.value << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 33 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(32, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Выведется «~Derived ~Base», утечки нет", false},
//             {"Выведется «~Base», а деструктор Derived не вызовется — утечка памяти (неопределённое поведение)", true},
//             {"Программа не скомпилируется", false},
//             {"Сработает std::terminate", false}
//         },
//         "Деструктор <code>~Base()</code> не объявлен <code>virtual</code>. При <code>delete</code> через указатель на базовый класс компилятор вызывает деструктор именно того типа, который статически известен указателю — то есть только <code>~Base()</code>. Деструктор <code>~Derived()</code> не вызывается вообще, поэтому <code>delete[] data</code> не выполняется — массив на 10 int утекает. Правило: если класс может использоваться полиморфно через указатель на базу, деструктор базового класса обязан быть <code>virtual</code>.",
//         "ВОПРОС 33 ИЗ 40",
//         "#include <iostream>\n\nclass Base {\npublic:\n    ~Base() { std::cout << \"~Base \"; }\n};\n\nclass Derived : public Base {\npublic:\n    ~Derived() { std::cout << \"~Derived \"; delete[] data; }\n    int* data = new int[10];\n};\n\nint main() {\n    Base* b = new Derived();\n    delete b;\n    return 0;\n}"
//     ));

//     // Вопрос 34 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(33, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Выведется «hello world»", false},
//             {"Программа не скомпилируется", false},
//             {"Неопределённое поведение — string_view ссылается на уже уничтоженный временный std::string", true},
//             {"Сработает std::terminate", false}
//         },
//         "<code>std::string_view</code> — это лишь невладеющая пара (указатель, длина), она не продлевает время жизни данных, на которые ссылается. Локальная <code>std::string s</code> уничтожается при выходе из <code>getView()</code>, а возвращаемый <code>string_view</code> продолжает указывать на уже освобождённую память. Обращение к <code>v</code> в <code>main</code> — неопределённое поведение (на практике часто печатает «мусор», проверено компиляцией).",
//         "ВОПРОС 34 ИЗ 40",
//         "#include <iostream>\n#include <string_view>\n#include <string>\n\nstd::string_view getView() {\n    std::string s = \"hello world\";\n    return s;\n}\n\nint main() {\n    std::string_view v = getView();\n    std::cout << v << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 35 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(34, std::make_shared<QuestPageOne>(
//         "Что произойдёт со следующим кодом (C++17)?",
//         std::vector<Option>{
//             {"Гарантированно выведется 1", false},
//             {"Неопределённое поведение — push_back может вызвать реаллокацию и инвалидировать итератор it", true},
//             {"Программа не скомпилируется", false},
//             {"Гарантированно выведется 4", false}
//         },
//         "Если <code>push_back</code> превышает текущую <code>capacity()</code>, вектор выделяет новый, больший блок памяти и переносит туда все элементы, а старый блок освобождается. Итератор <code>it</code>, полученный до <code>push_back</code>, продолжает указывать на уже освобождённую память — это неопределённое поведение, вне зависимости от того, произошла ли реаллокация в конкретном случае. Полагаться на конкретный вывод здесь нельзя.",
//         "ВОПРОС 35 ИЗ 40",
//         "#include <iostream>\n#include <vector>\n\nint main() {\n    std::vector<int> v = {1, 2, 3};\n    auto it = v.begin();\n    v.push_back(4);\n    std::cout << *it << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 36 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(35, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"«logic_error: oops»", true},
//             {"«exception: oops»", false},
//             {"Ни один catch не сработает, программа упадёт", false},
//             {"Сработают оба catch подряд", false}
//         },
//         "<code>std::out_of_range</code> наследуется от <code>std::logic_error</code>, который, в свою очередь, наследуется от <code>std::exception</code>. Блоки <code>catch</code> проверяются по порядку сверху вниз, и срабатывает <strong>первый подходящий</strong> — здесь это <code>catch (const std::logic_error&)</code>, потому что <code>out_of_range</code> IS-A <code>logic_error</code>. Второй <code>catch</code> вообще не выполняется — сработавший catch перехватывает исключение целиком.",
//         "ВОПРОС 36 ИЗ 40",
//         "#include <iostream>\n#include <stdexcept>\n\nint main() {\n    try {\n        throw std::out_of_range(\"oops\");\n    } catch (const std::logic_error& e) {\n        std::cout << \"logic_error: \" << e.what() << std::endl;\n    } catch (const std::exception& e) {\n        std::cout << \"exception: \" << e.what() << std::endl;\n    }\n    return 0;\n}"
//     ));

//     // Вопрос 37 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(36, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"Оба переполнения — корректно определённое поведение (wraparound), результат одинаково предсказуем", false},
//             {"Переполнение unsigned — корректно определённое поведение (wraparound до 0), переполнение signed int — неопределённое поведение", true},
//             {"Оба случая — неопределённое поведение", false},
//             {"Программа не скомпилируется", false}
//         },
//         "Для беззнаковых типов стандарт явно определяет арифметику по модулю 2ⁿ — переполнение <code>unsigned</code> корректно «заворачивается» в 0. А вот переполнение <strong>знакового</strong> целого — это неопределённое поведение по стандарту C++, даже если на практике большинство компиляторов без специальных флагов дают предсказуемый результат через дополнение до двух (например, <code>-2147483648</code>). Полагаться на это поведение нельзя — компилятор вправе оптимизировать код, исходя из предположения, что signed overflow never happens.",
//         "ВОПРОС 37 ИЗ 40",
//         "#include <iostream>\n#include <limits>\n\nint main() {\n    unsigned int u = std::numeric_limits<unsigned int>::max();\n    std::cout << \"unsigned max + 1 = \" << (u + 1) << std::endl;\n\n    int i = std::numeric_limits<int>::max();\n    std::cout << \"signed max + 1 = \" << (i + 1) << std::endl;\n    return 0;\n}"
//     ));

//     // Вопрос 38 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(37, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"«in main: 40», «in function: 40»", false},
//             {"«in main: 40», «in function: 8» (массив распадается в указатель при передаче в функцию)", true},
//             {"«in main: 10», «in function: 10»", false},
//             {"Программа не скомпилируется", false}
//         },
//         "Внутри <code>main</code> <code>arr</code> — настоящий массив из 10 <code>int</code>, <code>sizeof</code> честно даёт 40 байт (10×4). Но при передаче массива в функцию как параметра он «распадается» (decay) в обычный указатель <code>int*</code> — параметр <code>int arr[]</code> на самом деле эквивалентен <code>int* arr</code>. Внутри функции <code>sizeof(arr)</code> вернёт размер указателя — 8 байт на 64-битной платформе, а не размер исходного массива. Классическая ловушка передачи массивов в функции.",
//         "ВОПРОС 38 ИЗ 40",
//         "#include <iostream>\n\nvoid printSize(int arr[]) {\n    std::cout << \"in function: \" << sizeof(arr) << std::endl;\n}\n\nint main() {\n    int arr[10];\n    std::cout << \"in main: \" << sizeof(arr) << std::endl;\n    printSize(arr);\n    return 0;\n}"
//     ));

//     // Вопрос 39 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(38, std::make_shared<QuestPageOne>(
//         "Скомпилируется ли следующий код (C++17)?",
//         std::vector<Option>{
//             {"Да, скомпилируется, выведется 42", false},
//             {"Нет, не скомпилируется — explicit запрещает неявное преобразование int в Wrapper", true},
//             {"Скомпилируется, но с предупреждением, выведется 0", false},
//             {"Сработает std::terminate", false}
//         },
//         "Ключевое слово <code>explicit</code> перед конструктором запрещает компилятору неявно вызывать его для преобразования типов. Вызов <code>print(42)</code> требует неявного преобразования <code>int → Wrapper</code>, но <code>explicit</code> это блокирует. Компилятор выдаёт ошибку вида «could not convert '42' from int to Wrapper». Чтобы код заработал, нужно явно написать <code>print(Wrapper(42))</code>.",
//         "ВОПРОС 39 ИЗ 40",
//         "#include <iostream>\n\nclass Wrapper {\npublic:\n    explicit Wrapper(int v) : value(v) {}\n    int value;\n};\n\nvoid print(Wrapper w) {\n    std::cout << w.value << std::endl;\n}\n\nint main() {\n    print(42);\n    return 0;\n}"
//     ));

//     // Вопрос 40 — одиночный выбор с кодом
//     m_factory.addQuestionToPage(39, std::make_shared<QuestPageOne>(
//         "Что выведет следующий код (C++17)?",
//         std::vector<Option>{
//             {"«inside: 15», «inside: 20», «outside: 10»", true},
//             {"«inside: 15», «inside: 20», «outside: 20»", false},
//             {"Программа не скомпилируется без mutable", false},
//             {"«inside: 15», «inside: 15», «outside: 10»", false}
//         },
//         "Лямбда захватывает <code>x</code> <strong>по значению</strong> — внутри неё хранится независимая копия. Ключевое слово <code>mutable</code> лишь разрешает изменять эту копию между вызовами (без него лямбда была бы <code>const</code> по умолчанию, и <code>x += 5</code> не скомпилировался бы). Копия сохраняется между вызовами одного и того же объекта лямбды: 10→15→20. Но внешняя <code>x</code> в <code>main</code> никогда не затрагивается — она остаётся <strong>10</strong>.",
//         "ВОПРОС 40 ИЗ 40",
//         "#include <iostream>\n\nint main() {\n    int x = 10;\n    auto lambda = [x]() mutable {\n        x += 5;\n        std::cout << \"inside: \" << x << std::endl;\n    };\n    lambda();\n    lambda();\n    std::cout << \"outside: \" << x << std::endl;\n    return 0;\n}"
//     ));
// }