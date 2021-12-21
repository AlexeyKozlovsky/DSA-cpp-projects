#ifndef FINALPROJECT_TREEITEM_H
#define FINALPROJECT_TREEITEM_H

#include <QVariant>
#include <QVector>

#include "Data.h"

class TreeItem {
private:
    QVector<TreeItem*> childItems;
    Data *itemData;
    TreeItem *parentItem;
public:
    explicit TreeItem();
    explicit TreeItem(Data *data, TreeItem *parent = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();
};


#endif //FINALPROJECT_TREEITEM_H
