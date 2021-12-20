#ifndef FINALPROJECT_BASEFILTERWIDGET_H
#define FINALPROJECT_BASEFILTERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>


class BaseFilterWidget: public QWidget {
    Q_OBJECT
private:
    QGridLayout *filterGridLayout;

    void initUI();
public:
    BaseFilterWidget(QWidget *parent = nullptr);

};


#endif //FINALPROJECT_BASEFILTERWIDGET_H
