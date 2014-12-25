#ifndef CONFIG_H
#define CONFIG_H

#include <player.h>
#include <QDialog>
#include <QMessageBox>
#include <opencv/cv.h>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/cxcore.h>


namespace Ui {
class config;
}

class config : public QDialog
{
    Q_OBJECT
    
public:
    explicit config(Player *parent = 0);
    ~config();
    
private slots:
    void on_resetAllToDefaultsButton_clicked();

    void on_okCancelBox_accepted();

    void change_background_module(QAbstractButton* but);


private:
    String file_name;
    Ui::config *ui;
    int module;
    int direction;
};

#endif // CONFIG_H
