#include <QString>
#include <QGroupBox>
#include <QLabel>
#include "qpgroupbox.h"

QpGroupBox::QpGroupBox(QWidget *parent) :
    QGroupBox(parent)
{
    label = new QLabel(this);
}

QpGroupBox::QpGroupBox(QString text, QWidget* parent) :
    QGroupBox(parent)

{
    label = new QLabel(text, this);
}

QpGroupBox::~QpGroupBox()
{
    delete label;
}
