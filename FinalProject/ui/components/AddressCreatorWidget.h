#ifndef FINALPROJECT_ADDRESSCREATORWIDGET_H
#define FINALPROJECT_ADDRESSCREATORWIDGET_H

#include <QWidget>


class AddressCreatorWidget: public QWidget {
    Q_OBJECT
private:
    void initUI();
public:
    AddressCreatorWidget(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_ADDRESSCREATORWIDGET_H
