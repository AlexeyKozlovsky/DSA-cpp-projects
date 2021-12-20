#ifndef FINALPROJECT_TABBARPAGE_H
#define FINALPROJECT_TABBARPAGE_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>

class TabBarPage: public QWidget {
    Q_OBJECT
private:
    QTabWidget *tabWidget;

    void initUI();
public:
    TabBarPage(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_TABBARPAGE_H
