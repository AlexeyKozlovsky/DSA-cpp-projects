#include <QGridLayout>
#include <QPushButton>

#include "UsersFilterWidget.h"


UsersFilterWidget::UsersFilterWidget(QWidget *parent) {
    this->initUI();
}

void UsersFilterWidget::initUI() {
    QGridLayout *mainLayout = new QGridLayout(this);

    this->searchLineEdit = new QLineEdit(this);
    QPushButton *searchButton = new QPushButton("Искать", this);

    this->searchLineEdit->setPlaceholderText("Поисковый запрос");

    mainLayout->addWidget(this->searchLineEdit, 0, 0, 1, 5);
    mainLayout->addWidget(searchButton, 0, 5, 1, 1);
}
