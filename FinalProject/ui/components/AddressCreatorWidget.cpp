#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QSpinBox>
#include <QGridLayout>

#include "AddressCreatorWidget.h"


AddressCreatorWidget::AddressCreatorWidget(QWidget *parent): QWidget(parent) {
    this->initUI();
}

void AddressCreatorWidget::initUI() {
    QGridLayout *mainLayout = new QGridLayout(this);

    QLineEdit *countryLineEdit = new QLineEdit(this);
    QLineEdit *cityLineEdit = new QLineEdit(this);
    QLineEdit *streetLineEdit = new QLineEdit(this);
    QSpinBox *houseSpinBox = new QSpinBox(this);

    countryLineEdit->setPlaceholderText("Название страны");
    cityLineEdit->setPlaceholderText("Название города");
    streetLineEdit->setPlaceholderText("Название улицы");
    houseSpinBox->setRange(1, 10000);

    mainLayout->addWidget(new QLabel("Страна", this), 0, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Город", this), 1, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Улица", this), 2, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Дом", this), 3, 0, 1, 1);
    mainLayout->addWidget(countryLineEdit, 0, 1, 1, 1);
    mainLayout->addWidget(cityLineEdit, 1, 1, 1, 1);
    mainLayout->addWidget(streetLineEdit, 2, 1, 1, 1);
    mainLayout->addWidget(houseSpinBox, 3, 1, 1, 1);
}
