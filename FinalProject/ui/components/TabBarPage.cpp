#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>

#include "TabBarPage.h"
#include "UsersTableModel.h"
#include "PlacesTableModel.h"
#include "HotelsTableModel.h"
#include "HotelTableView.h"
#include "BaseTableView.h"


TabBarPage::TabBarPage(QWidget *parent): QWidget(parent) {
    this->initUI();
}

void TabBarPage::initUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    this->tabWidget = new QTabWidget;

    UsersTableModel *users = new UsersTableModel(this);
    PlacesTableModel *places = new PlacesTableModel(this);
    HotelsTableModel *hotels = new HotelsTableModel(this);

    QSortFilterProxyModel *usersProxy = new QSortFilterProxyModel(this);
    QSortFilterProxyModel *placesProxy = new QSortFilterProxyModel(this);
    QSortFilterProxyModel *hotelsProxy = new QSortFilterProxyModel(this);

    usersProxy->setSourceModel(users);
    placesProxy->setSourceModel(places);
    hotelsProxy->setSourceModel(hotels);

    BaseTableView *usersView = new BaseTableView("Пользователи");
    BaseTableView *placesView = new BaseTableView("Места");
    HotelTableView *hotelsView = new HotelTableView;

    usersView->setModel(usersProxy);
    placesView->setModel(placesProxy);
    hotelsView->setModel(hotels);

    tabWidget->addTab(usersView, "Пользователи");
    tabWidget->addTab(placesView, "Места");
    tabWidget->addTab(hotelsView, "Отели");

    mainLayout->addWidget(tabWidget);
    this->setLayout(mainLayout);
}
