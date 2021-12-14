#include <QString>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableView>

#include "BaseTableView.h"


BaseTableView::BaseTableView(QString name, QWidget *parent) {
    this->name = name;
    this->initUI();
}

void BaseTableView::initUI() {
    this->setWindowTitle(this->name);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *btnLayout = new QHBoxLayout;

    this->tableView = new QTableView;

    QPushButton *addButton = new QPushButton("Добавить");
    QPushButton *deleteButton = new QPushButton("Удалить");

    mainLayout->addWidget(this->tableView);
    mainLayout->addLayout(btnLayout);

    btnLayout->addWidget(addButton);
    btnLayout->addWidget(deleteButton);

    this->setLayout(mainLayout);
}

void BaseTableView::setModel(QAbstractTableModel *model) {
    this->tableView->setModel(model);
}
