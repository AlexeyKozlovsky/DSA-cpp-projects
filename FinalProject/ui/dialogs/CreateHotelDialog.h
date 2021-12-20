#ifndef FINALPROJECT_CREATEHOTELDIALOG_H
#define FINALPROJECT_CREATEHOTELDIALOG_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>


class CreateHotelDialog: public QWidget {
    Q_OBJECT
private:
    void initUI();
public:
    QLineEdit *hotelNameLineEdit;
    QTextEdit *hotelDescriptionTextEdit;
    QSpinBox *hotelRoomsCountSpinBox;

    CreateHotelDialog(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_CREATEHOTELDIALOG_H
