#include <iostream>

#include "WF.h"
#include "WFOpt.h"


int main(int argc, char *argv[]) {
//    WF wf("no", "ono");
//    std::cout << wf.getDistance() << std::endl;
//    wf.printMatrix();

    std::cout << getDistance("ono", "ono") << std::endl;
    return 0;
}