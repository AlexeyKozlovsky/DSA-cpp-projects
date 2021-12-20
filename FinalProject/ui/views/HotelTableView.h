#ifndef FINALPROJECT_HOTELTABLEVIEW_H
#define FINALPROJECT_HOTELTABLEVIEW_H

#include <QObject>
#include <QWidget>

#include "BaseTableView.h"
#include "HotelsFilterWidget.h"
#include "HotelProxyModel.h"

#define FILTER_KIND_PROP "filterKind"


class HotelTableView: public BaseTableView {
    Q_OBJECT
private:
    HotelsFilterWidget *hotelsFilterWidget;
    HotelProxyModel *proxyModel;
protected:
    void initUI() override;
public:
    HotelTableView(QWidget *parent = nullptr);

    virtual void setModel(QAbstractItemModel *model) override;

public slots:
    void onRbButtonToggled(bool checked);
};


#endif //FINALPROJECT_HOTELTABLEVIEW_H
