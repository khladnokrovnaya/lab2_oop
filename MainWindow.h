#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Text.h"
#include "Correct.h"
#include "StackHistory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PasteTextButton_clicked();

    void on_posEdit_textEdited(const QString &arg1);

    void on_textEdit_textEdited(const QString &arg1);

    void on_DeleteCheckBox_toggled(bool checked);

    void on_ApllyButton_clicked();

    void on_DeleteHistoryBox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Text myText;
    StackHistory historyAdd, historyDelete;
    QString editPos = "0", editText = "";
    bool typeOperation = true;
};
#endif // MAINWINDOW_H
