#ifndef QPGROUPBOX_H
#define QPGROUPBOX_H

#include <QGroupBox>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QString;
class QLabel;
QT_END_NAMESPACE

class QpGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    QpGroupBox(QWidget *parent = 0);
    QpGroupBox(QString text, QWidget *parent = 0);
    ~QpGroupBox();

    QLabel* label;

signals:

public slots:

};

#endif // QPGROUPBOX_H
