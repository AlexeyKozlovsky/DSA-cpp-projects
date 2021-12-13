#include "ResourceManager.h"


void ResourceManager::addResource(Data *resource) {
    this->resources.insert(resource);
}

void ResourceManager::removeResource(Data *resource) {
    this->resources.erase(resource);
}

std::set<Data*> ResourceManager::getResources() {
    return this->resources;
}
