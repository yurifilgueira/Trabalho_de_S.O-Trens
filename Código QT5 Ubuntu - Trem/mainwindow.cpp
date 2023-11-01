#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,190,30);
    trem2 = new Trem(2,460,30);
    trem3 = new Trem(3,80,150);
    trem4 = new Trem(4,310,150);
    trem5 = new Trem(5,550,150);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1        
        ui->label_trem1->setGeometry(x,y,21,17);
        ui->t1x->setText(QString::number(x));
        ui->t1y->setText(QString::number(y));
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        ui->t2x->setText(QString::number(x));
        ui->t2y->setText(QString::number(y));
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        ui->t3x->setText(QString::number(x));
        ui->t3y->setText(QString::number(y));
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        ui->t4x->setText(QString::number(x));
        ui->t4y->setText(QString::number(y));
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        ui->t5x->setText(QString::number(x));
        ui->t5y->setText(QString::number(y));
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::startTrens()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_vel_trem1_valueChanged(int value)
{
    int novaVelocidade = calcularNovaVelocidade(value);
    trem1->setVelocidade(novaVelocidade);
    ui->t1Vel->setText(QString::number(novaVelocidade));
}

void MainWindow::on_vel_trem2_valueChanged(int value)
{
    int novaVelocidade = calcularNovaVelocidade(value);
    trem2->setVelocidade(novaVelocidade);
    ui->t2Vel->setText(QString::number(novaVelocidade));
}

void MainWindow::on_vel_trem3_valueChanged(int value)
{
    int novaVelocidade = calcularNovaVelocidade(value);
    trem3->setVelocidade(novaVelocidade);
    ui->t3Vel->setText(QString::number(novaVelocidade));
}

void MainWindow::on_vel_trem4_valueChanged(int value)
{
    int novaVelocidade = calcularNovaVelocidade(value);
    trem4->setVelocidade(novaVelocidade);
    ui->t4Vel->setText(QString::number(novaVelocidade));
}

void MainWindow::on_vel_trem5_valueChanged(int value)
{
    int novaVelocidade = calcularNovaVelocidade(value);
    trem5->setVelocidade(novaVelocidade);
    ui->t5Vel->setText(QString::number(novaVelocidade));
}

int MainWindow::calcularNovaVelocidade(int value){
    return 5 * value;
}
