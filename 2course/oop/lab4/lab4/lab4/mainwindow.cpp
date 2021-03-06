#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPalette>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->setStyleSheet("background : black; color : red; ;");
    ui->lcdNumber->setPalette(Qt::red);

    ui->lift_floor_box->hide();

    connect(&controller, SIGNAL(set_lift_st(state_lift)), this, SLOT(change_lift_st(state_lift)));
    connect(&controller, SIGNAL(floor_ch(int)), this, SLOT(floor_changed(int)));
    connect(&controller, SIGNAL(hide()), this, SLOT(hide_el()));
    connect(&controller, SIGNAL(show()), this, SLOT(show_el()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::floor_changed(int a)
{
    ui->lcdNumber->display(a);
}
void MainWindow::show_el()
{

    ui->lift_floor_box->show();
}
void MainWindow::hide_el()
{
    ui->lift_floor_box->hide();

}
void MainWindow::change_lift_st(state_lift st_l)
{
    QTime time;
    time.start();
    for (; time.elapsed() < 1000;) {
        qApp->processEvents();
    }
    switch (st_l) {
    case state_lift::doors_closing:
        ui->lift_state->setText("doors closing");
        break;
    case state_lift::doors_opening:
        ui->lift_state->setText("doors opening");
        break;
    case state_lift::doors_opened:
        ui->lift_state->setText("doors opened");
        break;
    case state_lift::go_empty:
        ui->lift_state->setText("moving empty");
        break;
    case state_lift::go_full:
        ui->lift_state->setText("moving full");
        break;
    case state_lift::wait:
        ui->lift_state->setText("waiting");
        break;
    case state_lift::hide_panel:
        ui->lift_state->setText("hide panel");
        break;
    case state_lift::show_panel:
        ui->lift_state->setText("show panel");
        break;
        /* case state_lift::minor_wait:
        ui->lift_state->setText("minor_wait");
        break;*/
    }
}

void MainWindow::on_floor1BTN_clicked()
{
    controller.flor_btn_p(1);
}

void MainWindow::on_floor2BTN_clicked()
{
    controller.flor_btn_p(2);
}

void MainWindow::on_floor3BTN_clicked()
{
    controller.flor_btn_p(3);
}

void MainWindow::on_floor4BTN_clicked()
{
    controller.flor_btn_p(4);
}

void MainWindow::on_floor5BTN_clicked()
{
    controller.flor_btn_p(5);
}

void MainWindow::on_floor6BTN_clicked()
{
    controller.flor_btn_p(6);
}

void MainWindow::on_floor7BTN_clicked()
{
    controller.flor_btn_p(7);
}

void MainWindow::on_floor1BTN_2_clicked()
{
    controller.lift_btn_p(1);
}

void MainWindow::on_floor2BTN_2_clicked()
{
    controller.lift_btn_p(2);
}

void MainWindow::on_floor3BTN_2_clicked()
{
    controller.lift_btn_p(3);
}

void MainWindow::on_floor4BTN_2_clicked()
{
    controller.lift_btn_p(4);
}

void MainWindow::on_floor5BTN_2_clicked()
{
    controller.lift_btn_p(5);
}

void MainWindow::on_floor6BTN_2_clicked()
{
    controller.lift_btn_p(6);
}

void MainWindow::on_floor7BTN_2_clicked()
{
    controller.lift_btn_p(7);
}
