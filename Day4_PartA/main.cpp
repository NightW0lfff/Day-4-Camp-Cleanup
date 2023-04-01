#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* assignmentAssigned(string section1, string section2){
    int* arr = new int[100];
    int pos1 = section1.find("-");
    int pos2 = section2.find("-");
    
    arr[0] = stoi(section1.substr(0, pos1));
    arr[1] = stoi(section1.substr(pos1 + 1 , -1));
    arr[2] = stoi(section2.substr(0, pos2));
    arr[3] = stoi(section2.substr(pos2 + 1 , -1));
    
    return arr;
}

int* sectionAssigned(string pair, int index){
    int* arr = assignmentAssigned(pair.substr(0, index), pair.substr(index + 1, -1));
    return arr;
}



bool isFullyOverlap(int firstAssignment1, int lastAssignment1, int firstAssignment2, int lastAssignment2){
    
    if (((firstAssignment1 <= firstAssignment2) and (lastAssignment1 >= lastAssignment2)) or ((firstAssignment1 >= firstAssignment2) and (lastAssignment1 <= lastAssignment2))){

        return true;
    }else return false;
}


int main() {
    ifstream data("input.txt");
    string line, elf1, elf2;
    int result = 0;
    
    while(getline(data, line)){
        int index = line.find(",");
        int* ptr = sectionAssigned(line, index);

        if(isFullyOverlap(ptr[0], ptr[1], ptr[2], ptr[3])){
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}