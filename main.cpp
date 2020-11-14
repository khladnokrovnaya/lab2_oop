//#include "MainWindow.h"
//#include <QApplication>
//#include "Correct.h"
#include "StackHistory.h"
#include "Text.h"
#include <assert.h>
using namespace std;

void TestText() {
    Text text("this_is");
    text.SetInsert("meaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 2);
    assert(text.GetNewText() == "thmeaaaaaaaaaaaaaaaaaaaaaaaaaaaaaais_is");
    text.Delete(1, 100);
    assert(text.GetNewText() == "t");
    cerr << "TestText OK\n";
}

void TestStackHistory() {
    StackHistory sh;
    sh.Add({"I am text", "nottext", 1, 5});
    sh.Add({"This is text", "nottext", 1, 8});
    sh.Add({"TEXT", 0, 2, 2});
    sh.Add({"testoftext", "set", 1, 6});
    assert(sh.Top().GetNewText() == "testoftext");
    sh.Pop();
    assert(sh.Top().GetNewText() == "TE");
    cerr << "TestStackHistory OK" << endl;
}

int main()
{
    TestText();
    TestStackHistory();
    StackHistory sh;
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();
}
