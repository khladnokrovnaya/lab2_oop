#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->myText.setSometext("Hello World");
    ui->SomeText->setText(myText.getSometext().c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PasteTextButton_clicked()
{
    this->myText.redact(this->typeOperation,this->editText.toStdString(),this->editPos.toInt());
    if (this->typeOperation)
    {
        if (this->historyAdd.add(this->editPos.toInt(),this->editText.toStdString()) == 0){
            if (!ui->DeleteHistoryBox->isDown())
                ui->HistoryBox->addItem(this->editText);
        }

    }
    else if (!this->typeOperation && this->editText != ""){
        if (this->historyDelete.add(this->editPos.toInt(),this->editText.toStdString()) == 0){
            if (ui->DeleteHistoryBox->isDown())
                ui->HistoryBox->addItem(this->editText);
        }
    }
    ui->posEdit->setText("");
    ui->textEdit->setText("");

    on_posEdit_textEdited("");
    on_textEdit_textEdited("");
    ui->SomeText->setText(myText.getSometext().c_str());

}

void MainWindow::on_posEdit_textEdited(const QString &arg1)
{
    this->editPos = arg1;
}

void MainWindow::on_textEdit_textEdited(const QString &arg1)
{
    this->editText = arg1;
}

void MainWindow::on_DeleteCheckBox_toggled(bool checked)
{
    this->typeOperation = !checked;
}

void MainWindow::on_ApllyButton_clicked()
{
    //cout << "tyt" << endl;
    QString s = this->ui->HistoryBox->currentText();
    cout << ui->HistoryBox->currentIndex() << endl;
    if (ui->DeleteHistoryBox->isDown() && ui->HistoryBox->currentIndex() > -1)
    {
        this->historyDelete.setIteratorIndex(ui->HistoryBox->currentIndex());
        this->myText.unredact(true, this->historyDelete.getIteratorElement().second.second.getSometext(),this->historyDelete.getIteratorElement().second.first);
        this->historyDelete.remove(ui->HistoryBox->currentIndex());
        on_DeleteHistoryBox_toggled(true);
    }
    else if (ui->HistoryBox->currentIndex() > -1)
    {
        this->historyAdd.setIteratorIndex(ui->HistoryBox->currentIndex());
        this->myText.unredact(false, this->historyAdd.getIteratorElement().second.second.getSometext(),this->historyAdd.getIteratorElement().second.first);
        this->historyAdd.remove(ui->HistoryBox->currentIndex());
        on_DeleteHistoryBox_toggled(false);
    }
    ui->SomeText->setText(myText.getSometext().c_str());
}

void MainWindow::on_DeleteHistoryBox_toggled(bool checked)
{
    ui->HistoryBox->clear();
    if (checked)
    {
        historyDelete.setIteratorIndex(0);
        for (int i = 0; i < historyDelete.getLength(); i++){
            historyDelete.setIteratorIndex(i);
            ui->HistoryBox->addItem(QString(this->historyDelete.getIteratorElement().second.second.getSometext().c_str()));
        }
    }
    else {
        for (int i = 0; i < historyAdd.getLength(); i++){
            historyAdd.setIteratorIndex(i);
            ui->HistoryBox->addItem(QString::fromUtf8(this->historyAdd.getIteratorElement().second.second.getSometext().c_str()));
        }
    }
}
