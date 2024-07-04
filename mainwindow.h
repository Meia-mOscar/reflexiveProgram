#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datastore.h"

#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QCheckBox>
#include <QPushButton>


#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QDebug>
#include <QObject>
#include <QDialog>
#include <QMetaObject>
#include <QMetaProperty>

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //getter / setter / functions

public slots:
    //Actions
    void consoleClicked();
    void guiClicked();
    void addClicked();
    void updateRecommendedState(int state);

private:
    //elements
    QLabel *instruction = new QLabel("Fill in the data and click add");
    QLabel *programNameLabel = new QLabel("Name");
    QLineEdit *programName = new QLineEdit;
    QLabel *dateLabel = new QLabel("Date");
    QDateEdit *date = new QDateEdit;
    QCheckBox *recommendCheckBox = new QCheckBox("Recommend");
    QPushButton *add = new QPushButton("Add");
    QPushButton *consoleDisplay = new QPushButton("Console display");
    QPushButton *guiDisplay = new QPushButton("GUI display");
    DataStore inputData;
    bool recommendedState;
    int noPrograms;

    //Layout elements
    QWidget *mainWindow = new QWidget();
    QWidget *nameWindow = new QWidget();
    QWidget *dateWindow = new QWidget();
    QWidget *buttonWindow = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *dateLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    //Clear the UI after every click of a button
    void clearFields();

};

#endif MAINWINDOW_H
