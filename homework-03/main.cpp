#include <cstdio>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using sensorFormatter = std::function<std::string(std::vector<int>)>;

class DataWriter
{
  public:
    virtual ~DataWriter() = default;

    virtual void write(const std::string &data) const = 0;
};

class FileManager final : public DataWriter
{
  public:
    explicit FileManager(const std::string &path);
    FileManager(const FileManager &fileManager) = delete;
    FileManager(FileManager &&fileManager) noexcept;
    ~FileManager() override;
    FileManager &operator=(const FileManager &fileManager) = delete;
    FileManager &operator=(FileManager &&fileManager) noexcept;
    void write(const std::string &data) const override;

  private:
    FILE *filePtr;
    std::string path_;
};

FileManager::FileManager(const std::string &path) : filePtr(fopen(path.c_str(), "w")), path_(path)
{
    std::cout << "FileManager(const std::string &path), path= '" << path << "'" << std::endl;
    if (!filePtr)
    {
        throw std::runtime_error("Open file failure");
    }
}

FileManager::FileManager(FileManager &&fileManager) noexcept : filePtr(fileManager.filePtr), path_(fileManager.path_)
{
    fileManager.filePtr = nullptr;
}

FileManager::~FileManager()
{
    std::cout << "~FileManager()";
    if (this->filePtr)
    {
        std::fclose(this->filePtr);
        this->filePtr = nullptr;
        std::cout << ", cleand resource, path='" << this->path_ << "'";
    }
    std::cout << std::endl;
}

FileManager &FileManager::operator=(FileManager &&fileManager) noexcept
{
    if (this != &fileManager)
    {
        if (this->filePtr)
        {
            std::fclose(this->filePtr);
            std::cout << "&FileManager::operator=(FileManager &&fileManager), cleand resource, path='" << this->path_
                      << "'" << std::endl;
        }

        this->filePtr = fileManager.filePtr;
        this->path_ = fileManager.path_;
        fileManager.filePtr = nullptr;
    }

    return *this;
};

void FileManager::write(const std::string &data) const
{
    if (!this->filePtr)
    {
        throw std::runtime_error("File is not opened");
    }
    if (EOF == std::fputs(data.c_str(), this->filePtr))
    {
        throw std::runtime_error("Write into file failure");
    }
};

class Sensor
{
  public:
    explicit Sensor(const std::shared_ptr<std::vector<int>> &collector);
    void record(int data) const;
    void print(const DataWriter *printer, const sensorFormatter &formatter) const;

  private:
    std::shared_ptr<std::vector<int>> collectorPtr;
};

Sensor::Sensor(const std::shared_ptr<std::vector<int>> &collector) : collectorPtr(collector)
{
}

void Sensor::record(const int data) const
{
    this->collectorPtr->push_back(data);
}

void Sensor::print(const DataWriter *printer, const sensorFormatter &formatter) const
{
    printer->write(formatter(*this->collectorPtr));
}

FileManager getFileManager(const std::string &path)
{
    FileManager fileManager(path);

    return fileManager;
}

sensorFormatter getFormatter(const std::string &title, const char delim)
{
    return [&title, delim](const std::vector<int> &vec) -> std::string {
        std::ostringstream oss;
        oss << title << ":\n";
        for (const auto &item : vec)
        {
            oss << " " << item << " " << delim;
        }
        oss << '\n';

        return oss.str();
    };
}

int main()
{
    try
    {
        const auto collector{std::make_shared<std::vector<int>>()};

        const Sensor firstSensor(collector);

        firstSensor.record(3);
        firstSensor.record(5);
        firstSensor.record(1);

        Sensor secondSensor(collector);

        secondSensor.record(13);
        secondSensor.record(15);
        secondSensor.record(11);

        FileManager fileManager("data-empty.txt");
        fileManager = getFileManager("sensor-1.txt");

        firstSensor.print(&fileManager, getFormatter("Printed by Sensor #1", '|'));

        fileManager = getFileManager("sensor-2.txt");
        secondSensor.print(&fileManager, getFormatter("Printed by Sensor #2", '-'));
    }
    catch (const std::runtime_error &err)
    {
        std::cout << "ERROR: " << err.what() << std::endl;
    }

    return 0;
}