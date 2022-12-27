#include <iostream>
#include <dirent.h>
#include <deque>
using namespace std;
struct Find_files
{
deque<string> file_finds;
string file_name_search;

Find_files(string file_name_search):file_name_search(file_name_search){}
};
void filefind(const char* path_name,Find_files& f_files);
void project();
