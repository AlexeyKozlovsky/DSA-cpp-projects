#include <QString>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QSortFilterProxyModel>

#include "BaseTableView.h"


BaseTableView::BaseTableView(QString name, QWidget *parent) {
    this->name = name;
    this->initUI();
}

void BaseTableView::initUI() {
    this->setWindowTitle(this->name);

    this->mainLayout = new QHBoxLayout;
    QVBoxLayout *tableLayout = new QVBoxLayout;
    QHBoxLayout *btnLayout = new QHBoxLayout;

    this->tableView = new QTableView;
    this->tableView->setSortingEnabled(true);

    QPushButton *addButton = new QPushButton("Добавить");
    QPushButton *deleteButton = new QPushButton("Удалить");

    tableLayout->addWidget(this->tableView);
    tableLayout->addLayout(btnLayout);

    btnLayout->addWidget(addButton);
    btnLayout->addWidget(deleteButton);

    this->mainLayout->addLayout(tableLayout);
    this->setLayout(this->mainLayout);
}

void BaseTableView::setModel(QAbstractItemModel *model) {
    this->tableView->setModel(model);
}
