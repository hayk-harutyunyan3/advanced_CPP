#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <string>
#include <memory>
#include <vector>

class Directory;

class FileSystemNode {
public:
    explicit FileSystemNode(const std::string name);
    virtual ~FileSystemNode() = default;

    std::string get_name() const;
    virtual size_t get_size() const = 0;
    virtual void display() const = 0;
protected:
    std::string m_name;
};

class File : public FileSystemNode {
public:
    File(const std::string &name, const std::shared_ptr<Directory> &dir);
    File(const std::string &name, const std::string &content, const std::shared_ptr<Directory> &dir);
    ~File() = default;

    size_t get_size() const override;
    void display() const override;
    std::string get_content() const;    
    void add_content(const std::string &content);
    void add_content(std::string &&content);
    void chage_content(const std::string &content);
    void chage_content(std::string &&content);
    void truncate();
    void change_directory(const std::shared_ptr<Directory> &dir);
    std::shared_ptr<Directory> get_current_directory() const;
private:
    std::string m_content;
    std::weak_ptr<Directory> m_dir;
};

class Directory : public FileSystemNode {
public:
    explicit Directory(const std::string &name);
    ~Directory() = default;

    size_t get_size() const override;
    size_t get_file_count() const;
    void display() const override;
    void add_file(const std::shared_ptr<FileSystemNode> &file);
    void remove_file(const std::shared_ptr<FileSystemNode> &file);
private:
    std::vector<std::shared_ptr<FileSystemNode>> m_files;
};

#endif /* FILESYSTEM_HPP */