#ifndef FINALPROJECT_PLACESFILTERWIDGET_H
#define FINALPROJECT_PLACESFILTERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QRadioButton>
#include <QCheckBox>
#include <QSlider>
#include <QLineEdit>


class PlacesFilterWidget: public QWidget {
    Q_OBJECT
private:
    void initUI();
public:
    QLineEdit *searchLineEdit;
    QRadioButton *nameRb, *descriptionRb, *placeRb;
    QCheckBox *useRadiusSlider;
    QSlider *radiusSlider;

    PlacesFilterWidget(QWidget *parent = nullptr);
};


#endif //FINALPROJECT_PLACESFILTERWIDGET_H
