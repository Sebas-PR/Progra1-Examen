#include "CheaseRepository.h"
#include <stdexcept>


CheaseRepository::CheaseRepository() {
    auto data = DataLoader::LoadFromFile("cheese.txt");
    data_ = std::move(data);
}

int CheaseRepository::GetAvailableQuantity(const std::string& CheaseType) const {
    auto it = data_.find(CheaseType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown tomato type: " + CheaseType);
    }
    return std::stoi(it->second[0]);
}

void CheaseRepository::UpdateQuantity(const std::string& CheaseType, int newQuantity) {
    auto it = data_.find(CheaseType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown tomato type: " + CheaseType);
    }
    it->second[0] = std::to_string(newQuantity);
}