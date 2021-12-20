#ifndef FINALPROJECT_USERSFILTERWIDGET_H
#define FINALPROJECT_USERSFILTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>


class UsersFilterWidget: public QWidget {
    Q_OBJECT
private:
    void initUI();
public:
    QLineEdit *searchLineEdit;

    UsersFilterWidget(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_USERSFILTERWIDGET_H
