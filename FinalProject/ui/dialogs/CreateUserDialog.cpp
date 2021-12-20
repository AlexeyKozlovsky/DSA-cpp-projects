#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include "AddressCreatorWidget.h"
#include "CreateUserDialog.h"


CreateUserDialog::CreateUserDialog(QWidget *parent): QDialog(parent) {
    this->initUI();
}

void CreateUserDialog::initUI() {
    QGridLayout *mainLayout = new QGridLayout(this);

    QLineEdit *firstNameLineEdit = new QLineEdit(this);
    QLineEdit *secondNameLineEdit = new QLineEdit(this);
    QLineEdit *patronymicLineEdit = new QLineEdit(this);
    QLineEdit *emailLineEdit = new QLineEdit(this);
    QLineEdit *phoneLineEdit = new QLineEdit(this);
    AddressCreatorWidget *addressCreatorWidget = new AddressCreatorWidget(this);
    QPushButton *acceptButton = new QPushButton("Создать", this);
    QPushButton *cancelButton = new QPushButton("Отмена", this);

    firstNameLineEdit->setPlaceholderText("Имя");
    secondNameLineEdit->setPlaceholderText("Фамилия");
    patronymicLineEdit->setPlaceholderText("Отчество");
    emailLineEdit->setPlaceholderText("Электронная почта");
    phoneLineEdit->setPlaceholderText("Телефон");

    mainLayout->addWidget(new QLabel("Имя", this), 0, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Фамилия", this), 1, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Отчество", this), 2, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Электронная почта", this), 3, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Телефон", this), 4, 0, 1, 1);
    mainLayout->addWidget(new QLabel("Адрес", this), 5, 0, 1, 1);
    mainLayout->addWidget(firstNameLineEdit, 0, 1, 1, 3);
    mainLayout->addWidget(secondNameLineEdit, 1, 1, 1, 3);
    mainLayout->addWidget(patronymicLineEdit, 2, 1, 1, 3);
    mainLayout->addWidget(emailLineEdit, 3, 1, 1, 3);
    mainLayout->addWidget(phoneLineEdit, 4, 1, 1, 3);
    mainLayout->addWidget(addressCreatorWidget, 5, 1, 1, 3);
    mainLayout->addWidget(acceptButton, 6, 0, 1, 3);
    mainLayout->addWidget(cancelButton, 6, 3, 1, 1);
}
