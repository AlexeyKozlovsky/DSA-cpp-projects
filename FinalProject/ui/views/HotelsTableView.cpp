#include <vector>

#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "HotelsTableView.h"

HotelsTableView::HotelsTableView(QWidget *parent) : QWidget(parent) {
    this->initUI();
}

void HotelsTableView::setModel(QAbstractTableModel *model) {
    this->tableView->setModel(model);
}

void HotelsTableView::initUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *btnLayout = new QHBoxLayout;

    QPushButton *addButton = new QPushButton("Добавить");
    QPushButton *deleteButton = new QPushButton("Удалить");

    this->tableView = new QTableView;

    btnLayout->addWidget(addButton);
    btnLayout->addWidget(deleteButton);

    mainLayout->addWidget(this->tableView);
    mainLayout->addLayout(btnLayout);

    this->setLayout(mainLayout);
}
