#include "../include/fileSystem.hpp"
#include <iostream>

int main() {
    auto root = std::make_shared<Directory>("root");
    auto docs = std::make_shared<Directory>("docs");
    auto img = std::make_shared<Directory>("images");

    auto file1 = std::make_shared<File>("file1.txt", "Hello World", root);
    auto file2 = std::make_shared<File>("file2.txt", "C++ Programming", docs);
    auto file3 = std::make_shared<File>("photo.jpg", root);

    root->add_file(file1);
    root->add_file(docs);
    root->add_file(img);
    docs->add_file(file2);
    img->add_file(file3);

    auto link = std::make_shared<Symlink>("file1_link", file1);
    root->add_file(link);

    root->display(std::cout);
    
    return 0;
}