#ifndef FINALPROJECT_BASETABLEVIEW_H
#define FINALPROJECT_BASETABLEVIEW_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QTableView>
#include <QHBoxLayout>
#include <QAbstractTableModel>


class BaseTableView: public QWidget {
    Q_OBJECT
protected:
    QString name;
    QTableView *tableView;

    virtual void initUI();

    QHBoxLayout *mainLayout;

public:
    BaseTableView(QString name, QWidget *parent = nullptr);

    virtual void setModel(QAbstractItemModel *model);
};


#endif //FINALPROJECT_BASETABLEVIEW_H
