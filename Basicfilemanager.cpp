#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>
namespace fs=std::filesystem;
void listDirectory(const std::string &path){
    for(const auto& entry: fs::directory_iterator(path)){
        std::cout<<entry.path().filename().string()<<std::endl;

    }
}
void viewfile(const std::string& filePath){
    std::ifstream file(filePath);
    if(file.is_open()){
        std::string line;
        while (std::getline(file,line)){
            std::cout<<line<<std::endl;

        }
        file.close();
        }
        else{
            std::cerr<<"Unable to open file:"<<filePath<<std::endl;

        }
}

void createDirectory(const std::string& dirPath){
    if(!fs::create_directory(dirPath)){
        std::cerr<<"Failed to create directoy: "<<dirPath<<std::endl;

    }
}

void copyFile(const std::string&  source, const std::string& designation){
    fs::copy(source,designation, fs::copy_options::overwrite_existing);
}

void movefile(const std::string& source, std::string& designation){
    fs::rename(source,designation);
}
int main(){
    std:: string command;
    std::cout<<"*************WELCOME TO FILE MANAGER:*************"<<std::endl;
    while(true){
        std::cout<<"Enter a command(list,view<filename>,create<dirname>,copy<source><designation>,move<source><designatipon>)"<<std::endl;
        std::getline(std::cin,command);

        std::istringstream iss(command);
        std::string action;
        iss>>action;
        
        if(action=="list"){
            std::string path;
            iss>>path;
            listDirectory(path);
        }
        else if(action=="view"){
            std::string filename;
            iss>>filename;
            viewfile(filename);
        }
        else if(action=="create"){
            std::string dirname;
            iss>>dirname;
            createDirectory(dirname);
        }
        else if(action=="copy"){
            std::string source,designation;
            iss>>source>>designation;
            copyFile(source,designation);
        }
        else if(action=="move"){
            std::string source,designation;
            iss>>source>>designation;
            movefile(source,designation);
        }
        else if(action=="exit"){
            break;
        }
        else{
            std::cerr<<"INVALID COMMAND!"<<std::endl;

        }

    }
    std::cout<<"EXISTING BASIC FILE MANAGER! . goodbye"<<std::endl;
    return 0;

}