#include <bits/stdc++.h>
using namespace std;

class DocElement {
public:
    virtual string render() = 0;
    virtual ~DocElement() {}
};

class TextElement : public DocElement {
    string text;
public:
    TextElement(string t) : text(t) {}

    string render() override {
        return text;
    }
};

class ImageElement : public DocElement {
    string path;
public:
    ImageElement(string p) : path(p) {}

    string render() override {
        return "[Image: " + path + "]";
    }
};

class Document {
    vector<DocElement*> elements;

public:
    void addElement(DocElement* ele) {
        elements.push_back(ele);
    }

    string render() {
        string res;
        for (auto ele : elements) {
            res += ele->render() + "\n";
        }
        return res;
    }
};

class Persistance {
public:
    virtual void save(const string& data) = 0;
};

class FileStorage : public Persistance {
public:
    void save(const string& data) override {
        ofstream outFile("document.txt");
        outFile << data;
    }
};

class DocumentEditor {
    Document* doc;
    Persistance* storage;

public:
    DocumentEditor(Document* d, Persistance* s)
        : doc(d), storage(s) {}

    void addText(string text) {
        doc->addElement(new TextElement(text));
    }

    void addImage(string path) {
        doc->addElement(new ImageElement(path));
    }

    void save() {
        string data = doc->render();
        storage->save(data);
    }
};

int main() {
    cout << "🚀 Starting Document Editor...\n\n";

    // Step 1: Create objects
    Document* doc = new Document();
    Persistance* storage = new FileStorage();

    cout << "📄 Document created\n";
    cout << "💾 File storage initialized\n\n";

    // Step 2: Editor setup
    DocumentEditor editor(doc, storage);
    cout << "🛠️ Editor ready\n\n";

    // Step 3: Add elements
    cout << "✍️ Adding text...\n";
    editor.addText("Hello, this is a sample document.");

    cout << "🖼️ Adding image...\n";
    editor.addImage("image1.png");

    cout << "✍️ Adding more text...\n";
    editor.addText("This is another line.\n");

    // Step 4: Render document
    cout << "\n📢 Rendering Document...\n\n";
    string output = doc->render();

    cout << "========== DOCUMENT ==========\n";
    cout << output;
    cout << "==============================\n\n";

    // Step 5: Save
    cout << "💾 Saving document to file...\n";
    editor.save();

    cout << "✅ Done! Check 'document.txt'\n";

    return 0;
}