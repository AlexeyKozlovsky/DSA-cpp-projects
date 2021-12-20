#ifndef FINALPROJECT_PLACEPROXYMODEL_H
#define FINALPROJECT_PLACEPROXYMODEL_H

#include <QObject>
#include <QString>
#include <QSortFilterProxyModel>

#define FILTER_KIND_PROP "filterKind"


class PlaceProxyModel: public QSortFilterProxyModel {
    Q_OBJECT
private:
    QString filterKind;
    QString searchQuery;
public:
    enum FilterKind {
        NAME, DESCRIPTION, LOCATION, PLACE_TYPE
    };

    PlaceProxyModel(QObject *parent = nullptr);

    inline void setFilterKind(FilterKind filterKind) {this->filterKind = filterKind;};

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

public slots:
    inline void updateSearchQuery(QString searchQuery) {this->searchQuery = searchQuery;};
};


#endif //FINALPROJECT_PLACEPROXYMODEL_H
