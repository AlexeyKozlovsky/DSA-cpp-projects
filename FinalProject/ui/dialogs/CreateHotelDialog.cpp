#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

#include "AddressCreatorWidget.h"
#include "CreateHotelDialog.h"


CreateHotelDialog::CreateHotelDialog(QWidget *parent): QWidget(parent) {
    this->initUI();
}

void CreateHotelDialog::initUI() {
    QGridLayout *mainLayout = new QGridLayout(this);

    this->hotelNameLineEdit = new QLineEdit(this);
    this->hotelDescriptionTextEdit = new QTextEdit(this);
    this->hotelRoomsCountSpinBox = new QSpinBox(this);
    AddressCreatorWidget *addressCreatorWidget = new AddressCreatorWidget(this);
    QPushButton *acceptButton = new QPushButton("Создать", this);
    QPushButton *cancelButton = new QPushButton("Отмена", this);

    this->hotelNameLineEdit->setPlaceholderText("Название отеля");
    this->hotelDescriptionTextEdit->setPlaceholderText("Описание отеля");
    this->hotelRoomsCountSpinBox->setRange(5, 10000);

    mainLayout->addWidget(new QLabel("Название", this), 0, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Описание", this), 1, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Количество комнат", this), 2, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Адрес", this), 3, 0, 1, 1);
    mainLayout->addWidget(this->hotelNameLineEdit, 0, 1, 1, 3);
    mainLayout->addWidget(this->hotelDescriptionTextEdit, 1, 1, 1, 3);
    mainLayout->addWidget(this->hotelRoomsCountSpinBox, 2, 1, 1, 3);
    mainLayout->addWidget(addressCreatorWidget, 3, 1, 1, 3);
    mainLayout->addWidget(acceptButton, 4, 0, 1, 3);
    mainLayout->addWidget(cancelButton, 4, 3, 1, 1);
}
