#include <QSortFilterProxyModel>
#include <QDataWidgetMapper>
#include <QDebug>
#include <QLineEdit>

#include "HotelProxyModel.h"
#include "BaseTableView.h"
#include "HotelTableView.h"


HotelTableView::HotelTableView(QWidget *parent): BaseTableView("Hotels", parent) {
    this->initUI();

    this->hotelsFilterWidget->nameRb->setProperty(FILTER_KIND_PROP, HotelProxyModel::NAME);
    this->hotelsFilterWidget->descriptionRb->setProperty(FILTER_KIND_PROP, HotelProxyModel::DESCRIPTION);
    this->hotelsFilterWidget->placeRb->setProperty(FILTER_KIND_PROP, HotelProxyModel::PLACE);

    connect(this->hotelsFilterWidget->nameRb, SIGNAL(toggled(bool)),
            this, SLOT(onRbButtonToggled(bool)));
    connect(this->hotelsFilterWidget->descriptionRb, SIGNAL(toggled(bool)),
            this, SLOT(onRbButtonToggled(bool)));
    connect(this->hotelsFilterWidget->placeRb, SIGNAL(toggled(bool)),
            this, SLOT(onRbButtonToggled(bool)));
}

void HotelTableView::setModel(QAbstractItemModel *model) {
    proxyModel = new HotelProxyModel;
    proxyModel->setSourceModel(model);
    this->tableView->setModel(proxyModel);

    connect(this->hotelsFilterWidget->searchLineEdit, &QLineEdit::textEdited,
            proxyModel, &HotelProxyModel::updateSearchQuery);
}

void HotelTableView::initUI() {
    this->hotelsFilterWidget = new HotelsFilterWidget;
    this->mainLayout->addWidget(this->hotelsFilterWidget);
}

void HotelTableView::onRbButtonToggled(bool checked) {
    if (checked) {
        QRadioButton *rbButton = (QRadioButton *)sender();
        int intKind = rbButton->property(FILTER_KIND_PROP).toInt();
        this->proxyModel->setFilterKind((HotelProxyModel::FilterKind)intKind);

        qDebug() << intKind;
    }
}


