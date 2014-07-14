#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wrapper.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    previousSelectedPlaylist = 0; //what if already playing? fix this
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPlaylistItem(QString artist, QString title) {
    int newRow = ui->playlistTableWidget->rowCount();
    //artist
    QTableWidgetItem *artistItem = new QTableWidgetItem;
    artistItem->setText(artist);
    //title
    QTableWidgetItem *titleItem = new QTableWidgetItem;
    titleItem->setText(title);
    titleItem->setTextAlignment(Qt::AlignRight);

    ui->playlistTableWidget->insertRow(newRow);
    ui->playlistTableWidget->setItem(newRow, 0 , artistItem);
    ui->playlistTableWidget->setItem(newRow, 1 , titleItem);
}


void MainWindow::on_toolButton_clicked()
{
    Mpd.Play();
}

void MainWindow::on_toolButton_2_clicked()
{
    Mpd.Pause(1);
}

void MainWindow::on_toolButton_3_clicked()
{
    Mpd.Prev();
}

void MainWindow::on_toolButton_4_clicked()
{
    Mpd.Next();
}


void MainWindow::deleteItem() {
 /*   // Delete from mpd queue
    QModelIndexList indexes = ui->playlistTableWidget->selectionModel()->selectedIndexes();
    foreach(QModelIndex index, indexes)
    {
        Mpd.Delete(index.row());
        ui->playlistTableWidget->takeItem(index.row());
    }

    // Delete from UI
    QList<QListWidgetItem *> itemList = ui->playlistTableWidget->selectedItems();
    foreach(QListWidgetItem *item, itemList) {
        delete item;
    }

    // TODO: Delete from songlist
*/
}


void MainWindow::on_playlistTableWidget_doubleClicked(const QModelIndex &index)
{
    QFont font;
    font.setBold(false);

    ui->playlistTableWidget->item(getPreviousSelectedPlaylist(), 0)->setFont(font);
    ui->playlistTableWidget->item(getPreviousSelectedPlaylist(), 1)->setFont(font);

    font.setBold(true);
    ui->playlistTableWidget->item(index.row(), 0)->setFont(font);
    ui->playlistTableWidget->item(index.row(), 1)->setFont(font);

    setPreviousSelectedPlaylist(index.row());
    Mpd.Play(index.row());
}
