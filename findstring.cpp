#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "findstring.h"
#include "ui_findstring.h"

FindString::FindString(QWidget *parent) : QWidget(parent), ui(new Ui::FindString)
{
    ui->setupUi(this); //sets up the UI
    getTextFile();  //reads the text file
}

FindString::~FindString()
{
    delete ui;
}

void FindString::on_btnGo_clicked()
{
    QString word = ui->lineEdit->text();
    ui->textEdit->find(word, QTextDocument::FindWholeWords);
}

void FindString::getTextFile()
{
    QFile myFile(":/myText.txt"); //creates the myFile object
    myFile.open(QIODevice::ReadOnly); //opens the file to read-only

    QTextStream textStream(&myFile);
    QString line = textStream.readAll();
    myFile.close();

    ui->textEdit->setPlainText(line); //displays the textfile in plain text
    QTextCursor textCursor = ui->textEdit->textCursor();
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1); //Moves the cursor one postion


}
