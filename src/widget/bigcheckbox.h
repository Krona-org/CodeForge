#pragma once

#include <QCheckBox>

class BigCheckBox : public QCheckBox
{
    Q_OBJECT

public:
    explicit BigCheckBox(QWidget *parent = nullptr)
        : QCheckBox(parent)
    {
    }

protected:
    bool hitButton(const QPoint &) const override
    {
        return true;
    }
};