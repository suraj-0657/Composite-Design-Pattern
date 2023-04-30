//Composite Design Pattern: Implement File System

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class FileSystem
{
    protected:
    string name;
    
    public:
    FileSystem(string namePassed) : name(namePassed)
    {}
    
    string getName() {
        return name;
    }
    virtual void ls() = 0;
};

class File : public FileSystem
{
    public:
    File(string fileName) : FileSystem(fileName)
    {}
    
    void ls() {
        cout << "FileName: " << name <<" ";
    }
};

class Directory : public FileSystem
{
    vector<FileSystem*> dirList{};
    
    public:
    Directory(string dirName) : FileSystem(dirName)
    {}
    
    void add(FileSystem *obj) {
        dirList.push_back(obj);
    }
    
    void ls() {
        for(auto &objPtr: dirList) {
            if(typeid(*objPtr).name() == typeid(Directory).name())
                cout << "DirectoryName: " << objPtr->getName() << " ";
            objPtr->ls();
        }
    }
};

int main() {
    
	Directory *rootDir = new Directory("Movie");
	File *movie = new File("DJ");
	rootDir->add(movie);
	
	Directory *movieDir = new Directory("SuspanceMovie");
	movie = new File("Drisyam");
	movieDir->add(movie);
	
	rootDir->add(movieDir);
	cout << "RootDirName: " <<  rootDir->getName() << " ";
	rootDir->ls();
	
	return 0;
}