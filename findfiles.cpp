#include "findfiles.h"
void filefind(const char* path_name,Find_files& f_files)
{
try
{
struct dirent* file;
DIR* path;
if((path=opendir(path_name))!=NULL)
{
while((file=readdir(path)))
{
if(string(file->d_name).find(f_files.file_name_search)!=std::string::npos)
{
f_files.file_finds.push_back(string(file->d_name));
}
string p=path_name;
p+=(string)file->d_name+"//";
if(p.find('.')==std::string::npos)
{
const char* new_path=p.c_str();
filefind(new_path,f_files);
}
}
}
}
catch(...)
{
cout<<"error"<<endl;
}
}
void project()
{
int choose = 0;
do
{
cout << "select from which disk to search for the file" << endl;
cout << "Click 1 to choose C"<<endl;
cout << "Click 2 to write path D/E etc." << endl;
cin >> choose;
system("cls");
}while(choose!=1&&choose!=2);
string file_name = "";
cout << "Write file name" << endl;
cin >> file_name;
Find_files f_f1(file_name);
system("cls");
if (choose == 1)
{
cout<<"wait"<<endl;
filefind("C://",f_f1);
}
else
{
string disc_name_string="";
cout<<"write disc name"<<endl;
cin>>disc_name_string;
system("cls");
cout<<"wait"<<endl;
disc_name_string+="://";
const char* disc_name=disc_name_string.c_str();
filefind(disc_name,f_f1);
}
system("cls");
for(auto i:f_f1.file_finds)cout<<i<<endl;
}
