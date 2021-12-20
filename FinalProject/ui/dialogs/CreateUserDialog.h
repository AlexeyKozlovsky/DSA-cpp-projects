#ifndef FINALPROJECT_CREATEUSERDIALOG_H
#define FINALPROJECT_CREATEUSERDIALOG_H

#include <QDialog>


class CreateUserDialog: public QDialog {
    Q_OBJECT
private:
    void initUI();
public:
    CreateUserDialog(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_CREATEUSERDIALOG_H
