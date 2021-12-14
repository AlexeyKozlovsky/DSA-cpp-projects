#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

#include "TabBarPage.h"
#include "UsersTableModel.h"
#include "PlacesTableModel.h"
#include "HotelsTableModel.h"
#include "BaseTableView.h"


TabBarPage::TabBarPage(QWidget *parent): QWidget(parent) {
    this->initUI();
}

void TabBarPage::initUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    this->tabWidget = new QTabWidget;

    UsersTableModel *users = new UsersTableModel;
    PlacesTableModel *places = new PlacesTableModel;
    HotelsTableModel *hotels = new HotelsTableModel;

    BaseTableView *usersView = new BaseTableView("Пользователи");
    BaseTableView *placesView = new BaseTableView("Места");
    BaseTableView *hotelsView = new BaseTableView("Отели");

    usersView->setModel(users);
    placesView->setModel(places);
    hotelsView->setModel(hotels);

    tabWidget->addTab(usersView, "Пользователи");
    tabWidget->addTab(placesView, "Места");
    tabWidget->addTab(hotelsView, "Отели");

    mainLayout->addWidget(tabWidget);
    this->setLayout(mainLayout);
}
