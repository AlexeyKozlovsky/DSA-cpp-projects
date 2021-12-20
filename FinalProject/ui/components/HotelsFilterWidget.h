#ifndef FINALPROJECT_HOTELSFILTERWIDGET_H
#define FINALPROJECT_HOTELSFILTERWIDGET_H

#include <QString>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QList>

class HotelsFilterWidget: public QWidget{
    Q_OBJECT
private:
    void initUI();

public:
    QRadioButton *nameRb, *descriptionRb, *placeRb;
    QPushButton *searchButton;
    QLineEdit *searchLineEdit;

    HotelsFilterWidget(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_HOTELSFILTERWIDGET_H
