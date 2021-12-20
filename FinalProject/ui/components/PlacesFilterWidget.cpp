#include <QGridLayout>

#include "PlacesFilterWidget.h"


PlacesFilterWidget::PlacesFilterWidget(QWidget *parent) {
    this->initUI();
}

void PlacesFilterWidget::initUI() {
    QGridLayout *mainLayout = new QGridLayout;

    this->nameRb = new QRadioButton;
    this->descriptionRb = new QRadioButton;
    this->placeRb = new QRadioButton;
    this->searchLineEdit = new QLineEdit;
    this->useRadiusSlider = new QCheckBox;
}
