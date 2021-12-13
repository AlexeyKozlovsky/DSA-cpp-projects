#ifndef FINALPROJECT_HOTELSTABLEVIEW_H
#define FINALPROJECT_HOTELSTABLEVIEW_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QAbstractTableModel>


class HotelsTableView: public QWidget {
    Q_OBJECT
private:
    QTableView *tableView;

    void initUI();
public:
    HotelsTableView(QWidget *parent = nullptr);

    void setModel(QAbstractTableModel *model);
};


#endif //FINALPROJECT_HOTELSTABLEVIEW_H
