#include <QGridLayout>
#include <QPushButton>

#include "PlacesFilterWidget.h"


PlacesFilterWidget::PlacesFilterWidget(QWidget *parent) {
    this->initUI();
}

void PlacesFilterWidget::initUI() {
    QGridLayout *mainLayout = new QGridLayout(this);

    this->nameRb = new QRadioButton("По имени", this);
    this->descriptionRb = new QRadioButton("По описанию",this);
    this->placeRb = new QRadioButton("По месту",this);
    this->searchLineEdit = new QLineEdit(this);
    this->useRadiusSlider = new QCheckBox("Использовать радиус поиска", this);
    this->radiusSlider = new QSlider(this);
    QPushButton *searchButton = new QPushButton("Искать", this);

    this->nameRb->setChecked(true);
    this->searchLineEdit->setPlaceholderText("Поисковый запрос");
    this->radiusSlider->setOrientation(Qt::Horizontal);

    mainLayout->addWidget(this->searchLineEdit, 0, 0, 1, 5);
    mainLayout->addWidget(searchButton, 0, 5, 1, 1);
    mainLayout->addWidget(this->nameRb, 1, 0, 1, 5);
    mainLayout->addWidget(this->descriptionRb, 2, 0, 1, 5);
    mainLayout->addWidget(this->placeRb, 3, 0, 1, 5);
    mainLayout->addWidget(this->radiusSlider, 4, 0, 1, 4);
    mainLayout->addWidget(this->useRadiusSlider, 4, 5, 1, 1);
}
