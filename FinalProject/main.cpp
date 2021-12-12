#include <QApplication>
#include <QPushButton>
#include <vector>

#include "Data.h"
#include "UserManager.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();

    std::vector<Data*> dataVector;

    UserManager *userManager = (UserManager *) UserManager::GetInstance();
    auto *user1 = userManager->createUser("Alex", "Keks", "efdsfd@agd.com", "12321sdgfdsf3");
    auto *user2 = userManager->createUser("Ivan", "Ivanov", "fff@afd.com", "12dgfdsf3");
    auto *user3 = userManager->createUser("Alex", "Piters", "e123@a22.com", "12sdfdsf3");


    std::vector<Data *> users = userManager->getResources();

    return QApplication::exec();
}
