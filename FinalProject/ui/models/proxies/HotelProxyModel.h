#ifndef FINALPROJECT_HOTELPROXYMODEL_H
#define FINALPROJECT_HOTELPROXYMODEL_H

#include <QString>
#include <QObject>
#include <QSortFilterProxyModel>


class HotelProxyModel: public QSortFilterProxyModel {
    Q_OBJECT
public:
    enum FilterKind {
        NAME, DESCRIPTION, PLACE
    };

    inline void setFilterKind(FilterKind filterKind) {this->filterKind = filterKind; invalidateFilter();};

    HotelProxyModel(QObject *parent = nullptr);

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    FilterKind filterKind = FilterKind::NAME;
    QString searchQuery = "";

public slots:
    inline void updateSearchQuery(QString searchQuery) {this->searchQuery = searchQuery; invalidateFilter();};
};


#endif //FINALPROJECT_HOTELPROXYMODEL_H
