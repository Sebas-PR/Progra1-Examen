#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

class CheaseRepository {
public:
    CheaseRepository();

    int GetAvailableQuantity(const std::string& CheaseType) const;
    void UpdateQuantity(const std::string& CheaseType, int newQuantity);

private:
    mutable std::unordered_map<std::string, std::vector<std::string>> data_;
};