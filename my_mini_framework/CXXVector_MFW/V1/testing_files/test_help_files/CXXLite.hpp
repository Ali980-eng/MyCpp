#pragma once
#ifndef PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXL_HPP
#define PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXL_HPP
// BOMF: Basic Operation Mini-Framework
#include "CXXIO.hpp"
#include "CXXTesting.hpp"
#include "function_stream.hpp"
#include "CXXBenchmark.hpp"
#include <fstream>
#include <filesystem>
#include <unordered_map>
/// @brief A simple text file manager class for creating, reading, appending, checking existence, and removing text files in a specified directory.
class txtfile_manager
{
private:
    std::filesystem::path directory;

public:
    /**
     * @brief Constructs a txtfile_manager for managing text files in a specified directory.
     * @param dirPath The path to the directory where text files will be managed.
     */
    txtfile_manager(const std::string &dirPath)
    {
        directory = dirPath;
        if (!std::filesystem::exists(directory))
            std::filesystem::create_directories(directory);
    }
    /**
     * @brief Creates a new text file.
     * @param filename The name of the file to create.
     */
    void create(const std::string &filename)
    {
        std::ofstream file(directory / filename);
        if (!file.is_open())
            throw std::runtime_error("Failed to create file: " + filename);
        file.close();
    }
    /**
     * @brief Appends content to an existing text file.
     * @param filename The name of the file to append to.
     * @param content The content to append.
     */
    void append(const std::string &filename, const std::string &content)
    {
        std::ofstream file(directory / filename, std::ios::app);
        if (!file.is_open())
            throw std::runtime_error("Failed to open file for appending: " + filename);
        file << content << '\n';
        file.close();
    }
    /**
     * @brief Reads the contents of a text file.
     * @param filename The name of the file to read.
     * @return The contents of the file.
     */
    std::string read(const std::string &filename)
    {
        std::ifstream file(directory / filename);
        if (!file.is_open())
            throw std::runtime_error("Failed to open file for reading: " + filename);
        std::string content, line;
        while (std::getline(file, line))
            content += line + '\n';
        file.close();
        return content;
    }
    /**
     * @brief Checks if a text file exists.
     * @param filename The name of the file to check.
     * @return True if the file exists, false otherwise.
     */
    bool exists(const std::string &filename)
    {
        return std::filesystem::exists(directory / filename);
    }
    /**
     * @brief Removes a text file.
     * @brief Removes a text file.
     * @param filename The name of the file to remove.
     */
    void remove(const std::string &filename)
    {
        if (!std::filesystem::remove(directory / filename))
            throw std::runtime_error("Failed to remove file (maybe it doesn't exist): " + filename);
    }
};
#endif // PROGRAMING_C___PROGRAMMINGLIBRARYS_MYLIBRARYS_LAB_CXXL_HPP