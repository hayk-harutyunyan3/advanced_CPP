#include "../include/fileSystem.hpp"
#include <iostream>

/* FileSystemNode methods*/

FileSystemNode::FileSystemNode(const std::string name) : m_name{name} { }

/* File methods*/

File::File(const std::string &name, const std::shared_ptr<Directory> &dir) : FileSystemNode{name}, m_content{ }, m_dir{dir} { }

File::File(const std::string &name, const std::string &content, const std::shared_ptr<Directory> &dir) : FileSystemNode{name}, m_content {content}, m_dir{dir} { }

std::string File::name() const {
    return "- " + m_name;
}

size_t File::get_size() const {
    return m_content.size();
}

void File::display(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << m_name << " (" << m_content.size() << " bytes)" << std::endl;
}

std::string File::get_content() const {
    return m_content;
}

void File::add_content(const std::string &content) {
    m_content += content;
}

void File::add_content(std::string &&content) {
    m_content += std::move(content);
}

void File::chage_content(const std::string &content) {
    m_content = content;
}

void File::chage_content(std::string &&content) {
    m_content = std::move(content);
}

void File::truncate() {
    m_content = { };
}

void File::change_directory(const std::shared_ptr<Directory> &dir) {
    m_dir = dir;
}

std::shared_ptr<Directory> File::get_current_directory() const {
    return m_dir.lock();
}

/* Directory methods*/

std::string Directory::name() const {
    return "d " + m_name;
}

Directory::Directory(const std::string &name) : FileSystemNode{name} { }

size_t Directory::get_size() const {
    size_t size = 0;
    for (const auto &file : m_files) {
        size += file->get_size();
    }
    return size;
}

size_t Directory::get_file_count() const {
    return m_files.size();
}

void Directory::display(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "[" << m_name << "]" << std::endl;
    for (const auto& child : m_files) {
        child->display(os, indent + 4);
    }
}

void Directory::add_file(const std::shared_ptr<FileSystemNode> &file) {
    m_files.push_back(file);
}

void Directory::remove_file(const std::shared_ptr<FileSystemNode> &file) {
    m_files.erase(std::find(m_files.begin(), m_files.end(), file));
}

/* Symlink methods */

Symlink::Symlink(const std::string &name, const std::shared_ptr<FileSystemNode> &node) : FileSystemNode{name}, m_node{node} { }

std::string Symlink::name() const {
    return "l " + m_name;
}

size_t Symlink::get_size() const {
    return m_node.lock()->get_size();
}

void Symlink::display(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << m_name << " -> " << m_node.lock()->name() << std::endl;
}

void Symlink::change_node(const std::shared_ptr<FileSystemNode> new_node) {
    m_node = new_node;
}