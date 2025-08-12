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

    virtual std::string name() const = 0;
    virtual size_t get_size() const = 0;
    virtual void display(std::ostream& os, int indent = 0) const = 0;
protected:
    std::string m_name;
};

class File : public FileSystemNode {
public:
    File(const std::string &name, const std::shared_ptr<Directory> &dir);
    File(const std::string &name, const std::string &content, const std::shared_ptr<Directory> &dir);
    ~File() = default;

    std::string name() const override;
    size_t get_size() const override;
    void display(std::ostream& os, int indent = 0) const override;
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

    std::string name() const override;
    size_t get_size() const override;
    size_t get_file_count() const;
    void display(std::ostream& os, int indent = 0) const override;
    void add_file(const std::shared_ptr<FileSystemNode> &file);
    void remove_file(const std::shared_ptr<FileSystemNode> &file);
private:
    std::vector<std::shared_ptr<FileSystemNode>> m_files;
};

class Symlink : public FileSystemNode {
public:
    explicit Symlink(const std::string &name, const std::shared_ptr<FileSystemNode> &node);
    ~Symlink() = default;

    std::string name() const override;
    size_t get_size() const override;
    void display(std::ostream& os, int indent = 0) const override;
    void change_node(const std::shared_ptr<FileSystemNode> new_node);
private:
    std::weak_ptr<FileSystemNode> m_node;
};

#endif /* FILESYSTEM_HPP */