#include "../include/fileSystem.hpp"
#include <gtest/gtest.h>

TEST(fileTest, test1) {
    auto dir1 = std::make_shared<Directory>("dir1");
    std::string file1_content = "Hello. This is the content of 'file1'.";
    std::string file1_name = "file1";
    auto file1 = std::make_shared<File>(file1_name, file1_content, dir1);

    // get_dir test
    EXPECT_EQ(file1->get_current_directory(), dir1);
    
    // name test
    EXPECT_EQ(file1->name(), file1_name);
    
    // get_content test
    EXPECT_EQ(file1->get_content(), file1_content); 

    // add_content test
    std::string addition_content = "This is the addition content of 'file1'.";
    file1_content += addition_content;
    file1->add_content(addition_content);
    EXPECT_EQ(file1->get_content(), file1_content);
    EXPECT_EQ(file1->get_size(), file1_content.size());

    // change_content test
    file1_content = "This is changed content of 'file1'";
    file1->chage_content(file1_content);
    EXPECT_EQ(file1->get_content(), file1_content);
    EXPECT_EQ(file1->get_size(), file1_content.size());

    // truncate test
    file1->truncate();
    EXPECT_EQ(file1->get_content(), "");
    EXPECT_EQ(file1->get_size(), 0ul); 

    // change_dir test
    auto dir2 = std::make_shared<Directory>("dir2");
    file1->change_directory(dir2);
    EXPECT_EQ(file1->get_current_directory(), dir2);
}

TEST(directoryTest, test2) {
    auto dir1 = std::make_shared<Directory>("dir1");
    
    std::string file1_content = "file1 content";
    std::string file2_content = "file2 content, but this one is long";
    auto file1 = std::make_shared<File>("file1", file1_content, dir1);
    auto file2 = std::make_shared<File>("file2", file2_content, dir1);

    // name test
    EXPECT_EQ(dir1->name(), "dir1");

    // empty dir
    EXPECT_EQ(dir1->get_size(), 0ul);

    // add_file test
    dir1->add_file(file1);
    EXPECT_EQ(dir1->get_file_count(), 1ul);
    EXPECT_EQ(dir1->get_size(), file1->get_size());

    dir1->add_file(file2);
    EXPECT_EQ(dir1->get_file_count(), 2ul);
    EXPECT_EQ(dir1->get_size(), file1->get_size() + file2->get_size());
    
    // remove_file test
    dir1->remove_file(file2);
    EXPECT_EQ(dir1->get_file_count(), 1ul);
    EXPECT_EQ(dir1->get_size(), file1->get_size());
}