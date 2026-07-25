// core/cppsyntaxhighlighter.hpp
#pragma once

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
#include <QVector>

class CppSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit CppSyntaxHighlighter(QTextDocument *parent = nullptr)
        : QSyntaxHighlighter(parent)
    {
        HighlightRule rule;

        // управляющие конструкции — синий (VS Code: #569CD6)
        controlFormat.setForeground(QColor(0x56, 0x9C, 0xD6));
        const QStringList controlKeywords = {
            "\\bif\\b", "\\belse\\b", "\\bfor\\b", "\\bwhile\\b", "\\bdo\\b",
            "\\bswitch\\b", "\\bcase\\b", "\\bdefault\\b", "\\bbreak\\b",
            "\\bcontinue\\b", "\\breturn\\b", "\\bgoto\\b", "\\btry\\b",
            "\\bcatch\\b", "\\bthrow\\b", "\\bclass\\b", "\\bstruct\\b",
            "\\bpublic\\b", "\\bprivate\\b", "\\bprotected\\b",
            "\\bnamespace\\b", "\\busing\\b", "\\btemplate\\b",
            "\\btypename\\b", "\\bconst\\b", "\\bstatic\\b", "\\bvirtual\\b",
            "\\boverride\\b", "\\bexplicit\\b", "\\bfriend\\b",
            "\\benum\\b", "\\btypedef\\b", "\\bnew\\b", "\\bdelete\\b",
            "\\bsizeof\\b", "\\boperator\\b", "\\bthis\\b", "\\binline\\b",
            "\\bconstexpr\\b", "\\bdecltype\\b", "\\bnoexcept\\b",
            "\\bmutable\\b"
        };
        for (const QString &pattern : controlKeywords) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = controlFormat;
            rules.append(rule);
        }

        // встроенные типы — тоже синий, как в VS Code
        const QStringList typeKeywords = {
            "\\bvoid\\b", "\\bint\\b", "\\bchar\\b", "\\bbool\\b",
            "\\bfloat\\b", "\\bdouble\\b", "\\blong\\b", "\\bshort\\b",
            "\\bunsigned\\b", "\\bsigned\\b", "\\bauto\\b", "\\bwchar_t\\b",
            "\\bsize_t\\b"
        };
        for (const QString &pattern : typeKeywords) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = controlFormat;
            rules.append(rule);
        }

        // литералы true/false/nullptr — синий
        const QStringList literalKeywords = {
            "\\btrue\\b", "\\bfalse\\b", "\\bnullptr\\b"
        };
        for (const QString &pattern : literalKeywords) {
            rule.pattern = QRegularExpression(pattern);
            rule.format = controlFormat;
            rules.append(rule);
        }

        // имена пользовательских типов (Vector, MyClass) — бирюзовый (#4EC9B0)
        // эвристика: слово с большой буквы, не являющееся ключевым словом
        typeNameFormat.setForeground(QColor(0x4E, 0xC9, 0xB0));
        rule.pattern = QRegularExpression("\\b[A-Z][A-Za-z0-9_]*\\b");
        rule.format = typeNameFormat;
        rules.append(rule);

        // вызовы функций foo( — жёлтый (#DCDCAA)
        functionFormat.setForeground(QColor(0xDC, 0xDC, 0xAA));
        rule.pattern = QRegularExpression("\\b[a-z_][A-Za-z0-9_]*(?=\\s*\\()");
        rule.format = functionFormat;
        rules.append(rule);

        // строки "..." и символы '...' — оранжевый (#CE9178)
        stringFormat.setForeground(QColor(0xCE, 0x91, 0x78));
        rule.pattern = QRegularExpression("\".*\"|'.*'");
        rule.format = stringFormat;
        rules.append(rule);

        // числа — светло-зелёный (#B5CEA8)
        numberFormat.setForeground(QColor(0xB5, 0xCE, 0xA8));
        rule.pattern = QRegularExpression("\\b[0-9]+\\.?[0-9]*[fFuUlL]*\\b");
        rule.format = numberFormat;
        rules.append(rule);

        // директивы препроцессора #include, #define — пурпурный (#C586C0)
        preprocessorFormat.setForeground(QColor(0xC5, 0x86, 0xC0));
        rule.pattern = QRegularExpression("^\\s*#\\s*\\w+");
        rule.format = preprocessorFormat;
        rules.append(rule);

        // <iostream> / "file.h" после #include — оранжевый, как строки
        rule.pattern = QRegularExpression("<[^>]+>");
        rule.format = stringFormat;
        rules.append(rule);

        // однострочные комментарии // — зелёный (#6A9955)
        commentFormat.setForeground(QColor(0x6A, 0x99, 0x55));
        rule.pattern = QRegularExpression("//[^\n]*");
        rule.format = commentFormat;
        rules.append(rule);
    }

protected:
    void highlightBlock(const QString &text) override
    {
        for (const HighlightRule &rule : rules) {
            QRegularExpressionMatchIterator it = rule.pattern.globalMatch(text);
            while (it.hasNext()) {
                QRegularExpressionMatch match = it.next();
                setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            }
        }
    }

private:
    struct HighlightRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    QVector<HighlightRule> rules;
    QTextCharFormat controlFormat;
    QTextCharFormat typeNameFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat stringFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat commentFormat;
    QTextCharFormat preprocessorFormat;
};