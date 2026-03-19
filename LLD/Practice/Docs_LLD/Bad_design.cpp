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
/*
    ===================== DESIGN ANALYSIS =====================

    This is an example of BAD DESIGN in LLD.

    --------------------- WHAT IT DOES ------------------------
    - Stores both text and image paths in a single vector<string>
    - Uses string parsing (.png/.jpg) to detect type
    - Renders content to console
    - Writes content to file (document.txt)

    ---------------------- ISSUES -----------------------------

    1. Single Responsibility Principle (SRP) ❌
       Docs class is handling multiple responsibilities:
       - Data storage
       - Type detection (text vs image)
       - Rendering to console
       - Writing to file

       -> One class = multiple jobs = bad design

    ----------------------------------------------------------

    2. Open/Closed Principle (OCP) ❌
       - Adding new types (gif, video, pdf) requires modifying render()
       - Adding new output formats (PDF, HTML) requires modifying class

       -> Not closed for modification

    ----------------------------------------------------------

    3. Code Duplication ❌
       Same logic repeated in:
       - render()
       - printDocs()

       -> Violates DRY (Don't Repeat Yourself)

    ----------------------------------------------------------

    4. Weak Abstraction ❌
       - Everything stored as string
       - No distinction between Text and Image objects

       -> No type safety
       -> Hard to extend

    ----------------------------------------------------------

    5. Tight Coupling ❌
       - Logic depends on file extensions (.png, .jpg)
       - Changing image representation breaks system

    ----------------------------------------------------------

    6. Hardcoded Output ❌
       - File name "document.txt" is fixed
       - No flexibility to change output destination

    ----------------------------------------------------------

    7. Poor Extensibility ❌
       To support:
       - Video
       - Tables
       - Rich text

       -> Requires modifying existing code everywhere

    ----------------------------------------------------------

    8. Memory Management Issue ❌
       - Using raw pointer (new Docs())
       - No delete → memory leak

    ----------------------------------------------------------

    ------------------- KEY DESIGN FLAW -----------------------

    Data is controlling behavior:
        -> Type is inferred from string

    Instead, behavior should be owned by objects:
        -> Use polymorphism (TextElement, ImageElement)

    ----------------------------------------------------------

    -------------------- INTERVIEW LINE -----------------------

    "This design relies on type-checking instead of polymorphism,
     making it non-scalable and violating multiple SOLID principles."

    ----------------------------------------------------------

    ------------------- HOW TO IMPROVE ------------------------

    1. Use abstraction:
       - Create base class: Element
       - Derived: TextElement, ImageElement

    2. Use polymorphism:
       - Each element handles its own render()

    3. Separate concerns:
       - Docs → only stores elements
       - Renderer → handles output (console/file)

    4. Use smart pointers:
       - vector<unique_ptr<Element>>

    ----------------------------------------------------------

    ---------------------- SUMMARY ----------------------------

    Current Design:
        Simple but rigid and not scalable

    Better Design:
        Slightly complex but flexible, extensible, maintainable

    ==========================================================
*/