#include <QString>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QGridLayout>

#include "HotelsFilterWidget.h"
#include "HotelProxyModel.h"


HotelsFilterWidget::HotelsFilterWidget(QWidget *parent) {
    this->initUI();
}

void HotelsFilterWidget::initUI() {
    QGridLayout *mainLayout = new QGridLayout;

    this->nameRb = new QRadioButton;
    this->descriptionRb = new QRadioButton;
    this->placeRb = new QRadioButton;
    this->searchButton = new QPushButton;
    this->searchLineEdit = new QLineEdit;

    this->nameRb->setText("По названию");
    this->descriptionRb->setText("По описанию");
    this->placeRb->setText("По месту");
    this->searchButton->setText("Поиск");
    this->searchLineEdit->setPlaceholderText("Поисковый запрос");

    this->nameRb->setChecked(true);


    mainLayout->addWidget(this->searchLineEdit, 0, 0, 1, 4);
    mainLayout->addWidget(this->searchButton, 0, 4, 1, 2);
    mainLayout->addWidget(this->nameRb, 1, 0, 1, 5);
    mainLayout->addWidget(this->descriptionRb, 2, 0, 1, 5);
    mainLayout->addWidget(this->placeRb, 3, 0, 1, 5);

    mainLayout->setRowStretch(4, 1);

    this->setLayout(mainLayout);
}
