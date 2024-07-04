#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Component titles
    setWindowTitle("Software Review");
    //Layout
    mainLayout->addWidget(instruction);

    nameLayout->addWidget(programNameLabel);
    nameLayout->addWidget(programName);
    nameWindow->setLayout(nameLayout);
    mainLayout->addWidget(nameWindow);

    dateLayout->addWidget(dateLabel);
    dateLayout->addWidget(date);
    dateWindow->setLayout(dateLayout);
    mainLayout->addWidget(dateWindow);

    mainLayout->addWidget(recommendCheckBox);

    buttonLayout->addWidget(add);
    buttonLayout->addWidget(consoleDisplay);
    buttonLayout->addWidget(guiDisplay);
    buttonWindow->setLayout(buttonLayout);
    mainLayout->addWidget(buttonWindow);

    //Add window which will contain the layout
    setCentralWidget(mainWindow);
    mainWindow->setLayout(mainLayout);

    //Signals & slots
    connect(consoleDisplay, &QPushButton::clicked, this, &MainWindow::consoleClicked);
    connect(guiDisplay, &QPushButton::clicked, this, &MainWindow::guiClicked);
    connect(add, &QPushButton::clicked, this, &MainWindow::addClicked);
    connect(recommendCheckBox, &QCheckBox::stateChanged, this, &MainWindow::updateRecommendedState);

    //Initialise
    programName->clear();
    date->setDate(QDate::currentDate());
    recommendCheckBox->setChecked(false);
    recommendedState = false;
    noPrograms = 0;
}

MainWindow::~MainWindow()
{
    //delete programList
    //delete any other objects created
}

void MainWindow::clearFields(){
    programName->clear();
    date->setDate(QDate::currentDate());
    recommendCheckBox->setChecked(false);
}

void::MainWindow::updateRecommendedState(int state){
    recommendedState = (state == Qt::Checked);
}

void MainWindow::consoleClicked(){
    for(int i=0; i<noPrograms; i++){
        qDebug() << "Name: " << inputData.nameList.at(i);
        qDebug() << "Date: " << inputData.dateList.at(i);
        qDebug() << "Recommended: " << inputData.recommendList.at(i);
    }
}

/*When displaying the data to the application window,
 * you cannot assume that you know beforehand how many properties there are,
 * what they are called, or of what type they are.
 * You need to loop through the properties and using reflective programming techniques,
 * display the data to the application window. */
void MainWindow::guiClicked()
{
    QDialog outputDialog;
    outputDialog.setModal(true);
    QVBoxLayout *dialogMainLayout = new QVBoxLayout;
    outputDialog.setLayout(dialogMainLayout);

    for(int i=0; i<noPrograms; i++)
    {
        //H layout for each program & add to main layout
        QWidget *subWidget = new QWidget;
        QHBoxLayout *dialogSubLayout = new QHBoxLayout;
        subWidget->setLayout(dialogSubLayout);
        dialogMainLayout->addWidget(subWidget);

        //Create lable for each property and add to H layout
        QLabel *n = new QLabel(inputData.nameList.at(i).toString() + '\t');
        dialogSubLayout->addWidget(n);

        QLabel *d = new QLabel(inputData.dateList.at(i).toDate().toString("yyyy-MM-dd") + '\t');
        dialogSubLayout->addWidget(d);

        if(inputData.recommendList.at(i).toBool())
        {
            QLabel *r = new QLabel("Recommended");
            dialogSubLayout->addWidget(r);
        }
        else
        {
            QLabel *r = new QLabel("Not recommended");
            dialogSubLayout->addWidget(r);
        }

    }

    outputDialog.exec();

    /*const QMetaObject *metaObject = &MyStruct::staticMetaObject;
        for (int i = 0; i < metaObject->propertyCount(); ++i) {
            QMetaProperty property = metaObject->property(i);
            const char *propertyName = property.name();
            QVariant propertyValue = data.property(propertyName);*/

}

void MainWindow::addClicked()
{
    //qDebug() << "Add button clicked.";
    inputData.nameList << programName->text();
    inputData.dateList << date->date();
    inputData.recommendList << recommendedState;
    this->clearFields();
    noPrograms++;
}
