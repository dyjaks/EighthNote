#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QShortcut>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPlaylistItem(QString artist, QString title);

    int getPreviousSelectedPlaylist() {return previousSelectedPlaylist; }

    void setPreviousSelectedPlaylist(int id) {previousSelectedPlaylist = id; }

private slots:

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void deleteItem();

    void on_playlistTableWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    int previousSelectedPlaylist;
};

#endif // MAINWINDOW_H
