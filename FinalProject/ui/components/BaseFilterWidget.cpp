#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>

#include "BaseFilterWidget.h"


BaseFilterWidget::BaseFilterWidget(QWidget *parent): QWidget(parent) {
    if (parent) this->setParent(parent, Qt::Window);
    this->initUI();
}


void BaseFilterWidget::initUI() {
    this->filterGridLayout = new QGridLayout;

    QLineEdit *searchLineEdit = new QLineEdit;
    QPushButton *searchButton = new QPushButton("Искать");


    this->setLayout(this->filterGridLayout);
}

