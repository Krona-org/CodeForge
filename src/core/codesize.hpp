#pragma once

#include <QPlainTextEdit>
#include <QFontMetrics>
#include <QScrollBar>

class CodeSize{ 
public:
    CodeSize() {};
    ~CodeSize() {};
    static void fitCodeEditHeight(QPlainTextEdit *edit);
};

inline void CodeSize::fitCodeEditHeight(QPlainTextEdit *edit) {
    QFontMetrics fm(edit->font());
    int lineCount = edit->document()->blockCount();

    int docMargin = edit->document()->documentMargin();
    int contentHeight = fm.lineSpacing() * lineCount
                         + docMargin * 2
                         + edit->frameWidth() * 2
                         + 10; // доп. запас

    edit->setFixedHeight(contentHeight);

    // жёстко фиксируем: скроллить некуда
    edit->verticalScrollBar()->setRange(0, 0);
    edit->verticalScrollBar()->setValue(0);
}