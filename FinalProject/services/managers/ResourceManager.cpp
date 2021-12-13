#include <algorithm>

#include "ResourceManager.h"


void ResourceManager::addResource(Data *resource) {
    this->resources.insert(resource);
}

void ResourceManager::removeResource(Data *resource) {
    this->resources.erase(resource);
}


std::set<Data*> ResourceManager::getResources() const {
    return this->resources;
}

//std::vector<Data *> ResourceManager::getResourcesVector() const {
//    std::vector<Data *> result;
//    std::copy(this->resources.begin(), this->resources.end(), std::back_inserter(result));
//    return result;
//}
