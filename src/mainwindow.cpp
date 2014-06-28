#include "mainwindow.h"
#include "ui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::addPlaylistItem(std::string s) {
  ui->listWidget->addItem(new QListWidgetItem("Testing"));
}
