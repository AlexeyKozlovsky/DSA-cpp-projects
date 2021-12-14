#ifndef FINALPROJECT_BASETABLEVIEW_H
#define FINALPROJECT_BASETABLEVIEW_H

#include <QObject>
#include <QString>
#include <QWidget>
#include <QTableView>
#include <QAbstractTableModel>


class BaseTableView: public QWidget {
    Q_OBJECT
private:
    QString name;
    QTableView *tableView;

    void initUI();
public:
    BaseTableView(QString name, QWidget *parent = nullptr);

    void setModel(QAbstractTableModel *model);
};


#endif //FINALPROJECT_BASETABLEVIEW_H
