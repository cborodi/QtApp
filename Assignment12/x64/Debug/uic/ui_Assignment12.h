/********************************************************************************
** Form generated from reading UI file 'Assignment12.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGNMENT12_H
#define UI_ASSIGNMENT12_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assignment12Class
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab_17;
    QVBoxLayout *verticalLayout;
    QListWidget *dogListWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QLabel *label_3;
    QLineEdit *breedLineEdit;
    QLabel *label_2;
    QLineEdit *dateLineEdit;
    QLabel *label_4;
    QLineEdit *vaccinationLineEdit;
    QLabel *label_5;
    QLineEdit *photographLineEdit;
    QGridLayout *gridLayout_2;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QWidget *tab_18;
    QVBoxLayout *verticalLayout_2;
    QListWidget *dogListWidget_modeB;
    QGridLayout *gridLayout;
    QPushButton *nextButton;
    QPushButton *saveButton;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QLineEdit *breedLineEdit_modeB;
    QLabel *label_7;
    QLineEdit *vaccinationLineEdit_modeB;
    QPushButton *filterButton;
    QListWidget *mylistWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *undoBButton;
    QPushButton *redoBButton;
    QPushButton *newWindowButton;
    QPushButton *displayButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Assignment12Class)
    {
        if (Assignment12Class->objectName().isEmpty())
            Assignment12Class->setObjectName(QString::fromUtf8("Assignment12Class"));
        Assignment12Class->resize(551, 565);
        centralWidget = new QWidget(Assignment12Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_17 = new QWidget();
        tab_17->setObjectName(QString::fromUtf8("tab_17"));
        verticalLayout = new QVBoxLayout(tab_17);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dogListWidget = new QListWidget(tab_17);
        dogListWidget->setObjectName(QString::fromUtf8("dogListWidget"));
        QFont font;
        font.setPointSize(12);
        dogListWidget->setFont(font);

        verticalLayout->addWidget(dogListWidget);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(tab_17);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameLineEdit = new QLineEdit(tab_17);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        label_3 = new QLabel(tab_17);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        breedLineEdit = new QLineEdit(tab_17);
        breedLineEdit->setObjectName(QString::fromUtf8("breedLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, breedLineEdit);

        label_2 = new QLabel(tab_17);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        dateLineEdit = new QLineEdit(tab_17);
        dateLineEdit->setObjectName(QString::fromUtf8("dateLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateLineEdit);

        label_4 = new QLabel(tab_17);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        vaccinationLineEdit = new QLineEdit(tab_17);
        vaccinationLineEdit->setObjectName(QString::fromUtf8("vaccinationLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, vaccinationLineEdit);

        label_5 = new QLabel(tab_17);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        photographLineEdit = new QLineEdit(tab_17);
        photographLineEdit->setObjectName(QString::fromUtf8("photographLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, photographLineEdit);


        verticalLayout->addLayout(formLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        addButton = new QPushButton(tab_17);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setFont(font);

        gridLayout_2->addWidget(addButton, 0, 0, 1, 1);

        deleteButton = new QPushButton(tab_17);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setFont(font);

        gridLayout_2->addWidget(deleteButton, 0, 1, 1, 2);

        updateButton = new QPushButton(tab_17);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setFont(font);

        gridLayout_2->addWidget(updateButton, 0, 3, 1, 1);

        undoButton = new QPushButton(tab_17);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));
        undoButton->setFont(font);

        gridLayout_2->addWidget(undoButton, 1, 0, 1, 2);

        redoButton = new QPushButton(tab_17);
        redoButton->setObjectName(QString::fromUtf8("redoButton"));
        redoButton->setFont(font);

        gridLayout_2->addWidget(redoButton, 1, 2, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QString::fromUtf8("tab_18"));
        verticalLayout_2 = new QVBoxLayout(tab_18);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dogListWidget_modeB = new QListWidget(tab_18);
        dogListWidget_modeB->setObjectName(QString::fromUtf8("dogListWidget_modeB"));
        dogListWidget_modeB->setFont(font);

        verticalLayout_2->addWidget(dogListWidget_modeB);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nextButton = new QPushButton(tab_18);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setFont(font);

        gridLayout->addWidget(nextButton, 0, 0, 1, 1);

        saveButton = new QPushButton(tab_18);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font);

        gridLayout->addWidget(saveButton, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_6 = new QLabel(tab_18);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        breedLineEdit_modeB = new QLineEdit(tab_18);
        breedLineEdit_modeB->setObjectName(QString::fromUtf8("breedLineEdit_modeB"));
        QFont font1;
        font1.setPointSize(8);
        breedLineEdit_modeB->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, breedLineEdit_modeB);

        label_7 = new QLabel(tab_18);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        vaccinationLineEdit_modeB = new QLineEdit(tab_18);
        vaccinationLineEdit_modeB->setObjectName(QString::fromUtf8("vaccinationLineEdit_modeB"));
        vaccinationLineEdit_modeB->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, vaccinationLineEdit_modeB);


        verticalLayout_2->addLayout(formLayout_3);

        filterButton = new QPushButton(tab_18);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));
        filterButton->setFont(font);
        filterButton->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_2->addWidget(filterButton);

        mylistWidget = new QListWidget(tab_18);
        mylistWidget->setObjectName(QString::fromUtf8("mylistWidget"));
        mylistWidget->setFont(font);

        verticalLayout_2->addWidget(mylistWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        undoBButton = new QPushButton(tab_18);
        undoBButton->setObjectName(QString::fromUtf8("undoBButton"));
        undoBButton->setFont(font);

        horizontalLayout->addWidget(undoBButton);

        redoBButton = new QPushButton(tab_18);
        redoBButton->setObjectName(QString::fromUtf8("redoBButton"));
        redoBButton->setFont(font);

        horizontalLayout->addWidget(redoBButton);


        verticalLayout_2->addLayout(horizontalLayout);

        newWindowButton = new QPushButton(tab_18);
        newWindowButton->setObjectName(QString::fromUtf8("newWindowButton"));
        newWindowButton->setFont(font);

        verticalLayout_2->addWidget(newWindowButton);

        displayButton = new QPushButton(tab_18);
        displayButton->setObjectName(QString::fromUtf8("displayButton"));
        displayButton->setFont(font);

        verticalLayout_2->addWidget(displayButton);

        tabWidget->addTab(tab_18, QString());

        verticalLayout_3->addWidget(tabWidget);

        Assignment12Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Assignment12Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 551, 21));
        Assignment12Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Assignment12Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Assignment12Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Assignment12Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Assignment12Class->setStatusBar(statusBar);

        retranslateUi(Assignment12Class);
        QObject::connect(addButton, SIGNAL(clicked()), Assignment12Class, SLOT(addDog()));
        QObject::connect(updateButton, SIGNAL(clicked()), Assignment12Class, SLOT(updateDog()));
        QObject::connect(saveButton, SIGNAL(clicked()), Assignment12Class, SLOT(saveDog()));
        QObject::connect(displayButton, SIGNAL(clicked()), Assignment12Class, SLOT(runMyList()));
        QObject::connect(filterButton, SIGNAL(clicked()), Assignment12Class, SLOT(filter()));
        QObject::connect(nextButton, SIGNAL(clicked()), Assignment12Class, SLOT(next()));
        QObject::connect(undoButton, SIGNAL(clicked()), Assignment12Class, SLOT(undo()));
        QObject::connect(redoButton, SIGNAL(clicked()), Assignment12Class, SLOT(redo()));
        QObject::connect(newWindowButton, SIGNAL(clicked()), Assignment12Class, SLOT(showNewWindow()));
        QObject::connect(undoBButton, SIGNAL(clicked()), Assignment12Class, SLOT(undo_modeB()));
        QObject::connect(redoBButton, SIGNAL(clicked()), Assignment12Class, SLOT(redo_modeB()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Assignment12Class);
    } // setupUi

    void retranslateUi(QMainWindow *Assignment12Class)
    {
        Assignment12Class->setWindowTitle(QCoreApplication::translate("Assignment12Class", "Assignment12", nullptr));
        label->setText(QCoreApplication::translate("Assignment12Class", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("Assignment12Class", "Breed", nullptr));
        label_2->setText(QCoreApplication::translate("Assignment12Class", "Date Of Birth", nullptr));
        label_4->setText(QCoreApplication::translate("Assignment12Class", "Vaccination Count", nullptr));
        label_5->setText(QCoreApplication::translate("Assignment12Class", "Photograph", nullptr));
        addButton->setText(QCoreApplication::translate("Assignment12Class", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("Assignment12Class", "Delete", nullptr));
        updateButton->setText(QCoreApplication::translate("Assignment12Class", "Update", nullptr));
        undoButton->setText(QCoreApplication::translate("Assignment12Class", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        undoButton->setShortcut(QCoreApplication::translate("Assignment12Class", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        redoButton->setText(QCoreApplication::translate("Assignment12Class", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        redoButton->setShortcut(QCoreApplication::translate("Assignment12Class", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tab_17), QCoreApplication::translate("Assignment12Class", "mode A", nullptr));
        nextButton->setText(QCoreApplication::translate("Assignment12Class", "Next", nullptr));
        saveButton->setText(QCoreApplication::translate("Assignment12Class", "Save", nullptr));
        label_6->setText(QCoreApplication::translate("Assignment12Class", "Breed", nullptr));
        label_7->setText(QCoreApplication::translate("Assignment12Class", "Vaccination Count", nullptr));
        filterButton->setText(QCoreApplication::translate("Assignment12Class", "Filter", nullptr));
        undoBButton->setText(QCoreApplication::translate("Assignment12Class", "Undo", nullptr));
        redoBButton->setText(QCoreApplication::translate("Assignment12Class", "Redo", nullptr));
        newWindowButton->setText(QCoreApplication::translate("Assignment12Class", "Display mylist in new window", nullptr));
        displayButton->setText(QCoreApplication::translate("Assignment12Class", "Display mylist with external app", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_18), QCoreApplication::translate("Assignment12Class", "mode B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assignment12Class: public Ui_Assignment12Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGNMENT12_H
