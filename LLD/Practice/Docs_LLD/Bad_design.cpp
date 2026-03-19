#include<bits/stdc++.h>
using namespace std;

class Docs {
private:
    vector<string> elements;

public:
    void addText(string text) {
        elements.push_back(text);
    }

    void addImage(string path) {
        elements.push_back(path);
    }

    void render() {
        for(string ele: elements) {
            if(ele.length() > 4 && 
               (ele.substr(ele.length()-4) == ".png" || 
                ele.substr(ele.length()-4) == ".jpg")) {
                cout << "Image: " << ele << endl;
            } else {
                cout << ele << endl;
            }
        }
    }

    void printDocs() {
        ofstream file("document.txt");

        for(string ele: elements) {
            if(ele.length() > 4 && 
               (ele.substr(ele.length()-4) == ".png" || 
                ele.substr(ele.length()-4) == ".jpg")) {
                file << "Image: " << ele << endl;
            } else {
                file << ele << endl;
            }
        }

        file.close();
    }
};

int main() {
    Docs* myDocs = new Docs();

    myDocs->addText("Text1");
    myDocs->addImage("image.png");

    myDocs->render();      // console output
    myDocs->printDocs();   // file output

    return 0;
}