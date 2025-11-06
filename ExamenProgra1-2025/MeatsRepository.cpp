#include "CheaseRepository.h"
#include <stdexcept>


MeatsRepository::MeatsRepository() {
    auto data = DataLoader::LoadFromFile("meats.txt");
    data_ = std::move(data);
}

int MeatsRepository::GetAvailableQuantity(const std::string& CheaseType) const {
    auto it = data_.find(MeatsType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown Meats type: " + CheaseType);
    }
    return std::stoi(it->second[0]);
}

