#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

class MeatsRepository {
public:
    MeatsRepository();

    int GetAvailableQuantity(const std::string& MeatsType) const;
    void UpdateQuantity(const std::string& MeatsType, int newQuantity);

private:
    mutable std::unordered_map<std::string, std::vector<std::string>> data_;
};
