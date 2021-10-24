#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;


/**
 * @brief Verifies if str starts with subst
 * 
 * @param str 
 * @param substr 
 * @return true 
 * @return false 
 */
bool startsWith (std::string str, std::string substr);


/**
 * @brief Split str into a vector, using delimiter as separator
 * 
 * @param str 
 * @param delimiter 
 * @return std::vector< std::string> 
 */
std::vector<std::string> split(std::string const &str, const char delimiter);


/**
 * @brief List all directories/files in the specified path
 * 
 * @param path 
 * @return std::vector< std::string> 
 */
std::vector<std::string> listdir(std::string path);
