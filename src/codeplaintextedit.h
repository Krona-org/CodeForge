#pragma once
#include <QPlainTextEdit>

class CodePlainTextEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit CodePlainTextEdit(QWidget *parent = nullptr) : QPlainTextEdit(parent) {
        connect(document(), &QTextDocument::contentsChanged, this, [this]() {
            updateGeometry(); // сообщаем layout'у: "пересчитай меня заново"
        });
    }

    QSize sizeHint() const override
    {
        document()->setTextWidth(viewport()->width() > 0 ? viewport()->width() : 300);
        int docHeight = static_cast<int>(document()->size().height());
        int frame = frameWidth() * 2;
        return QSize(QPlainTextEdit::sizeHint().width(), docHeight + frame + 28);
    }

    QSize minimumSizeHint() const override
    {
        return sizeHint();
    }
};