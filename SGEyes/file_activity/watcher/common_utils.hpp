#pragma once

#include "define.hpp"
#include <string>
#include <vector>

SAIGON_NAMESPACE_BEGIN

std::vector<std::wstring> enumerate_drives();
bool fileIsProcessing(const std::wstring& filePath, int& error);

SAIGON_NAMESPACE_END